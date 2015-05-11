/*************************************************************************
	> File Name: HeartBeatTimer.cpp
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Sat 09 May 2015 05:58:05 AM PDT
 ************************************************************************/

#include<iostream>
#include "common/comm/TaskManager.h"
#include "common/comm/Error.h"
#include "common/log/log.h"
#include "common/comm/AgentManager.h"
#include "ServerAgent.h"

#include "protocol/RASCmdCode.h"
#include "protocol/RASErrorCode.h"
#include "ConfigManager.h"
#include "protocol/FwmRcProtocol.pb.h"
#include "HeartBeatTimer.h"


using namespace std;

HeartBeatTimer::HeartBeatTimer(unsigned int timelen, unsigned int id):
    Timer(timelen)
{
    this->id = id;
}

HeartBeatTimer::~HeartBeatTimer()
{
    
}

int 
HeartBeatTimer::doAction()
{ 
    FwmRcProto::HeartBeatInfo heartBeatInfo;
    FwmRcProto::FrameworkInstanceInfo *pFrameworkInstanceInfo = \
                heartBeatInfo.mutable_framework_instance_info();
    pFrameworkInstanceInfo->set_framework_id(ConfigManager::getInstance()->getFrameworkId());
    pFrameworkInstanceInfo->set_framework_instance_id(ConfigManager::getInstance()->getFWInstanceId());

    heartBeatInfo.set_self_module_id(ConfigManager::getInstance()->getModuleId());

    string strHeartBeatInfo;
    heartBeatInfo.SerializeToString(&strHeartBeatInfo);

    MsgHeader msg;
    msg.cmd = MSG_FWM_RC_SEND_HEARTBEAT;
    msg.length = strHeartBeatInfo.length();
   
    ServerAgent *pAgent = dynamic_cast<ServerAgent *>(AgentManager::getInstance()->get(id));
    pAgent->sendPackage(msg, strHeartBeatInfo.c_str());
}
