/*************************************************************************
	> File Name: main.cpp
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Thu 09 Apr 2015 02:43:33 AM PDT
 ************************************************************************/

#include<iostream>

#include "ServerAgent.h"
#include "ClientAgent.h"
#include "common/comm/Epoll.h"
#include "common/comm/TCPListenAgent.h"
#include "common/comm/AgentManager.h"
#include "common/comm/TaskManager.h"
#include "common/log/log.h"
#include "common/util/util.h"
#include "ConfigManager.h"
#include "header.h"
#include "HeartBeatTimer.h"

#include <stdlib.h>
#include <signal.h>
#include <cstdio>
#include <unistd.h>
using util::conv::conv;

Epoll  *g_pEpoll  = NULL;
ServerAgent *g_pServerAgent = NULL;
SocketAddress servaddr;
const char * const shortOpt = "hf:";
HeartBeatTimer *g_pHeartBeatTimer = NULL;
TimerManager *g_pTimerManager = NULL;   

const int EPOLLSIZE = 1024;

void doExit(int signo)
{
    if (signo == SIGINT)       
    {
        INFO_LOG("client sigint catch!");
        
        AgentManager::getInstance()->clearAllAgent();
        TaskManager::getInstance()->clearAllTask();
        
        if ( g_pEpoll != NULL)
        {
            g_pEpoll->finish();
        }   
        if ( g_pHeartBeatTimer != NULL ){
            g_pHeartBeatTimer->detachTimer();
            g_pHeartBeatTimer = NULL;
        }
    }
}

int main(int argc, char *argv[])
{
    if ( argc != 3 )
    {
        cout << "Usage: " << argv[0] << " -f config_filename" << endl;
        return FAILED;
    }

    g_pTimerManager = (AgentManager::getInstance())->createAgent<TimerManager>();
    if ( g_pTimerManager->init() < 0  ){
        ERROR_LOG("main : cann't init timerManager");
        return FAILED;
    }
    int ch = 0;
    const char *pConfigFileName = NULL;
    while((ch = getopt(argc, argv, shortOpt)) != -1)
    {
        switch(ch)
        {
            case 'h':
                std::cout << "Usage: " << argv[0] 
                    << " -f config_filename" << std::endl;
                return SUCCESSFUL;
            case 'f':
                pConfigFileName = optarg;
                break;
            default:
                std::cerr << "Unknown option: " << char(optopt) << std::endl;
                return FAILED;
        }
    }

    if(NULL == pConfigFileName)
        pConfigFileName = "config.xml";

    if(FAILED == (ConfigManager::getInstance())->configWithXML(pConfigFileName))
    {
        ERROR_LOG("AL : Config init ERROR");
        return FAILED;
    }

    g_pEpoll = new Epoll();
    if ( g_pEpoll->initialize(EPOLLSIZE) == FAILED )
    {
        ERROR_LOG("\nIn main: init epoll error!\n");
        delete g_pEpoll;
        g_pEpoll = NULL;
        return FAILED;
    }
    
    sleep(10);
    servaddr.setAddress(
            (ConfigManager::getInstance())->getRcIp().c_str(),
            (ConfigManager::getInstance())->getRcPort());
    g_pServerAgent = (AgentManager::getInstance())->createAgent<ServerAgent>(servaddr);
    g_pServerAgent->init();
/*
    const vector<uint32_t>& vec = ConfigManager::getInstance()->getListenPort();
    SocketAddress listenAddress((ConfigManager::getInstance()->getSelfIp()).c_str(), vec[0]);
    
    TCPListenAgent<ClientAgent> *pClientLisAgent = \
            (AgentManager::getInstance())->
            createAgent< TCPListenAgent<ClientAgent> >(listenAddress);
    pClientLisAgent->init();
*/
    if ( signal(SIGINT, doExit) == SIG_ERR )
    {
        ERROR_LOG("\nIn main: set SIGINT(catch \"ctrl+c\") signal error!\n");
        return FAILED;
    }
   
    g_pHeartBeatTimer = new HeartBeatTimer(3, g_pServerAgent->getID());
    g_pEpoll->run();

    AgentManager::destroyInstance();
    TaskManager::destroyInstance();
    
    if ( g_pEpoll != NULL )
    {
        delete g_pEpoll;
        g_pEpoll = NULL;
    }

    LoggerFactory::getInstance()->clear();
    LoggerFactory::destroyInstance();
    
    return 0;
}
