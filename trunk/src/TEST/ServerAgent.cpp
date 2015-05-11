/*
 * =====================================================================================
 *
 *       Filename:  ServerAgent.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/05/13 04:19:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heaven (), zhanwenhan@163.com
 *        Company:  NDSL
 *
 * =====================================================================================
 */

#include "ServerAgent.h"
#include "protocol/RASCmdCode.h"
#include "protocol/RASErrorCode.h"
#include "ConfigManager.h"
#include "protocol/FwmRcProtocol.pb.h"
#include "HeartBeatTimer.h"
#include "header.h"

#include "common/comm/Epoll.h"
#include "common/comm/SocketAddress.h"
#include "common/log/log.h"

#include <iostream>
#include <stdint.h>
#include <stdlib.h>

ServerAgent::ServerAgent()
{

}

ServerAgent::ServerAgent(const SocketAddress &addr):
    TCPAgent(addr)
{

}

ServerAgent::ServerAgent(const TCPSocket &sock, const SocketAddress &addr):
    TCPAgent(sock,addr)
{

}

ServerAgent::~ServerAgent()
{
}

int
ServerAgent::init()
{
    if ( this->connect() != SUCCESSFUL )
    {
        ERROR_LOG("in ServerAgent::init connect server error");
        return FAILED;
    }

    return SUCCESSFUL;
}

int
ServerAgent::connectAfter( bool bConnect)
{
    if (bConnect )
    {        
        INFO_LOG("ServerAgent::connectAfter: sendPackage");

        FwmRcProto::Register fwmRegister;

        FwmRcProto::FrameworkInstanceInfo *pFrameworkInstanceInfo = \
                    fwmRegister.mutable_framework_instance_info();
        pFrameworkInstanceInfo->set_framework_id(ConfigManager::getInstance()->getFrameworkId());
        pFrameworkInstanceInfo->set_framework_instance_id(ConfigManager::getInstance()->getFWInstanceId());

        fwmRegister.set_self_module_id(ConfigManager::getInstance()->getModuleId());
        
        FwmRcProto::NetAddress *pNetAddress = fwmRegister.mutable_data_search_entry();
        pNetAddress->set_ip(ConfigManager::getInstance()->getSelfIp());
        pNetAddress->set_port(100000);

        string strRegister;
        fwmRegister.SerializeToString(&strRegister);

        MsgHeader msg;
        msg.cmd = MSG_FWM_RC_REGISTER;
        msg.length = strRegister.length();

        sendPackage(msg, strRegister.c_str());

        return SUCCESSFUL;
    }
    else
    {
        return FAILED;
    }
}
void
ServerAgent::readBack(InReq &req)
{
    switch (req.m_msgHeader.cmd)
    {
        case MSG_FWM_RC_REGISTER_ACK:
        {
            std::cout << "MSG_FWM_RC_REGISTER_ACK" << std::endl;

            g_pHeartBeatTimer->attachTimer();
        }
        case MSG_FWM_RC_STOP_MODULE_ACK:
        {
            FwmRcProto::RequestStartSlave requestStartSlave;
            FwmRcProto::FrameworkInstanceInfo *pFrameworkInstanceInfo = \
                        requestStartSlave.mutable_framework_instance_info();
            pFrameworkInstanceInfo->set_framework_id(ConfigManager::getInstance()->getFrameworkId());
            pFrameworkInstanceInfo->set_framework_instance_id(ConfigManager::getInstance()->getFWInstanceId());

            requestStartSlave.set_self_module_id(ConfigManager::getInstance()->getModuleId());

            for(int i = 0; i < 5; i++){
                FwmRcProto::EachModuleResourceInfo *pEachModuleResourceInfo = \
                            requestStartSlave.add_start_module_resource_info();
                pEachModuleResourceInfo->set_start_module_name("/root/mycpp/a.out");
                pEachModuleResourceInfo->set_ip("*");
                pEachModuleResourceInfo->set_listen_port_num(3);
                FwmRcProto::ResourceInfo *pResourceInfo = \
                            pEachModuleResourceInfo->mutable_resource_info();
                pResourceInfo->set_cpu_num(5);
                pResourceInfo->set_cpu_mem_size(50);
            }

            FwmRcProto::NetAddress *pNetAddress = \
                        requestStartSlave.mutable_fwm_net_address();
            pNetAddress->set_ip("192.168.1.75");
            pNetAddress->set_port(100);

            string str;
            requestStartSlave.SerializeToString(&str);

            MsgHeader msg;
            msg.cmd = MSG_FWM_RC_REQUEST_START_SLAVE;
            msg.length = str.length();
            
            sendPackage(msg, str.c_str());
            
            std::cout << "MSG_FWM_RC_REQUEST_START_SLAVE" << std::endl;
            break;
        }
        case MSG_FWM_RC_SEND_HEARTBEAT_ACK:
        {
            string data(req.ioBuf, req.m_msgHeader.length);
            
           
            g_pHeartBeatTimer->updateExpiredTime(3);
            std::cout << "MSG_FWM_RC_SEND_HEARTBEAT_ACK" << std::endl;
            break;
        }
/*
        case MSG_FWM_RC_SEND_HEARTBEAT_ACK:
        {
            string data(req.ioBuf, req.m_msgHeader.length);
            
            FwmRcProto::RequestStartSlave requestStartSlave;
            FwmRcProto::FrameworkInstanceInfo *pFrameworkInstanceInfo = \
                        requestStartSlave.mutable_framework_instance_info();
            pFrameworkInstanceInfo->set_framework_id(ConfigManager::getInstance()->getFrameworkId());
            pFrameworkInstanceInfo->set_framework_instance_id(ConfigManager::getInstance()->getFWInstanceId());

            requestStartSlave.set_self_module_id(ConfigManager::getInstance()->getModuleId());

            for(int i = 0; i < 10; i++){
                FwmRcProto::EachModuleResourceInfo *pEachModuleResourceInfo = \
                            requestStartSlave.add_start_module_resource_info();
                pEachModuleResourceInfo->set_start_module_name("/root/mycpp/a.out");
                pEachModuleResourceInfo->set_ip("*");
                pEachModuleResourceInfo->set_listen_port_num(3);
                FwmRcProto::ResourceInfo *pResourceInfo = \
                            pEachModuleResourceInfo->mutable_resource_info();
                pResourceInfo->set_cpu_num(5);
                pResourceInfo->set_cpu_mem_size(50);
            }

            FwmRcProto::NetAddress *pNetAddress = \
                        requestStartSlave.mutable_fwm_net_address();
            pNetAddress->set_ip("192.167.1.140");
            pNetAddress->set_port(100);

            string str;
            requestStartSlave.SerializeToString(&str);

            MsgHeader msg;
            msg.cmd = MSG_FWM_RC_REQUEST_START_SLAVE;
            msg.length = str.length();
            
            sendPackage(msg, str.c_str());
            
            std::cout << "MSG_FWM_RC_REQUEST_START_SLAVE" << std::endl;
            break;
        }
*/
/*
        case MSG_FWM_RC_SEND_HEARTBEAT_ACK:
        {
            string data(req.ioBuf, req.m_msgHeader.length);

            FwmRcProto::RequestTaskResource requestTaskResource;
            FwmRcProto::FrameworkInstanceInfo *pFrameworkInstanceInfo = \
                        requestTaskResource.mutable_framework_instance_info();
            pFrameworkInstanceInfo->set_framework_id(ConfigManager::getInstance()->getFrameworkId());
            pFrameworkInstanceInfo->set_framework_instance_id(ConfigManager::getInstance()->getFWInstanceId());

            requestTaskResource.set_self_module_id(ConfigManager::getInstance()->getModuleId());

            for(int i = 0; i < 5 ; i++){
                FwmRcProto::EachModuleRequestOrReturnResourceInfo *pEachModuleRequestOrReturnResourceInfo = \
                            requestTaskResource.add_module_add_resource_info();
                pEachModuleRequestOrReturnResourceInfo->set_resource_request_or_return_to_module_id(1);
                FwmRcProto::ResourceInfo *pResourceInfo = \
                            pEachModuleRequestOrReturnResourceInfo->mutable_resource_info();
                pResourceInfo->set_cpu_num(3);
                pResourceInfo->set_cpu_mem_size(50);
            }
            string str;
            requestTaskResource.SerializeToString(&str);

            MsgHeader msg;
            msg.cmd = MSG_FWM_RC_REQUEST_TASK_RESOURCE;
            msg.length = str.length();
            
            sendPackage(msg, str.c_str());
            break;

        }
*/
/*
        case MSG_FWM_RC_SEND_HEARTBEAT_ACK:
        { 
            string data(req.ioBuf, req.m_msgHeader.length);

            FwmRcProto::ReturnTaskResource returnTaskResource;
            FwmRcProto::FrameworkInstanceInfo *pFrameworkInstanceInfo = \
                        returnTaskResource.mutable_framework_instance_info();
            pFrameworkInstanceInfo->set_framework_id(ConfigManager::getInstance()->getFrameworkId());
            pFrameworkInstanceInfo->set_framework_instance_id(ConfigManager::getInstance()->getFWInstanceId());

            returnTaskResource.set_self_module_id(ConfigManager::getInstance()->getModuleId());

            for(int i = 0; i < 6 ; i++){
                FwmRcProto::EachModuleRequestOrReturnResourceInfo *pEachModuleRequestOrReturnResourceInfo = \
                            returnTaskResource.add_module_return_resource_info();
                pEachModuleRequestOrReturnResourceInfo->set_resource_request_or_return_to_module_id(1);
                FwmRcProto::ResourceInfo *pResourceInfo = \
                            pEachModuleRequestOrReturnResourceInfo->mutable_resource_info();
                pResourceInfo->set_cpu_num(1);
                pResourceInfo->set_cpu_mem_size(20);
            }
            string str;
            returnTaskResource.SerializeToString(&str);

            MsgHeader msg;
            msg.cmd = MSG_FWM_RC_RETURN_TASK_RESOURCE;
            msg.length = str.length();
            
            sendPackage(msg, str.c_str());
            break;

        }
*/
        case MSG_FWM_RC_REQUEST_START_SLAVE_ACK:
        {
            vector<unsigned int> moduleIds; 
            string data(req.ioBuf, req.m_msgHeader.length);

            FwmRcProto::RequestStartSlaveAck requestStartSlaveAck;
            requestStartSlaveAck.ParseFromString(data);
            for(int i = 0; i < requestStartSlaveAck.module_id_size(); i++){
                moduleIds.push_back(requestStartSlaveAck.module_id(i));
            }

            FwmRcProto::StopModule stopModule;
            FwmRcProto::FrameworkInstanceInfo *pFrameworkInstanceInfo = \
                        stopModule.mutable_framework_instance_info();
            pFrameworkInstanceInfo->set_framework_id(ConfigManager::getInstance()->getFrameworkId());
            pFrameworkInstanceInfo->set_framework_instance_id(ConfigManager::getInstance()->getFWInstanceId());

            stopModule.set_self_module_id(ConfigManager::getInstance()->getModuleId());
            for(int i = 0; i < moduleIds.size(); i++){
                stopModule.add_stop_module_id(moduleIds[i]);
            }

            string str;
            stopModule.SerializeToString(&str);

            MsgHeader msg;
            msg.cmd = MSG_FWM_RC_STOP_MODULE;
            msg.length = str.length();
            
            sendPackage(msg, str.c_str());
            break;

        }
/*
        case MSG_FWM_RC_SEND_HEARTBEAT_ACK:
        {
            string data(req.ioBuf, req.m_msgHeader.length);

            FwmRcProto::CloseFrameworkInstanceInfo closeFrameworkInstanceInfo;
            FwmRcProto::FrameworkInstanceInfo *pFrameworkInstanceInfo = \
                        closeFrameworkInstanceInfo.mutable_framework_instance_info();
            pFrameworkInstanceInfo->set_framework_id(ConfigManager::getInstance()->getFrameworkId());
            pFrameworkInstanceInfo->set_framework_instance_id(ConfigManager::getInstance()->getFWInstanceId());

            closeFrameworkInstanceInfo.set_self_module_id(ConfigManager::getInstance()->getModuleId());

            string str;
            closeFrameworkInstanceInfo.SerializeToString(&str);

            MsgHeader msg;
            msg.cmd = MSG_FWM_RC_CLOSE_FRAMEWORK_INSTANCE;
            msg.length = str.length();
            
            sendPackage(msg, str.c_str());
            break;

        }
*/
/*
        case MSG_FWM_RC_CLOSE_FRAMEWORK_INSTANCE_ACK:
        {
            std::cout << "MSG_FWM_RC_CLOSE_FRAMEWORK_INSTANCE_ACK" << endl;
            break;
        }
*/
        default:
            break;
    }
}

void
ServerAgent::writeBack(bool result)
{
    if (!result)
    {
        ERROR_LOG("\nIn ServerAgent: "
                "writeBack(): write out error!\n");
    }
}

int
ServerAgent::sendPackage(MsgHeader &header, const char *dataStr)
{
    uint32_t msgLength = header.length + sizeof(MsgHeader);
    char *sendBuf = new char[msgLength + 1];
    memset(sendBuf, 0, msgLength + 1);
    memcpy(sendBuf, &header, sizeof(MsgHeader));
    if (dataStr != NULL)
    {
        memcpy(sendBuf + sizeof(MsgHeader), dataStr, header.length);
    }

    if (this->writeToBuffer(sendBuf, msgLength) == FAILED)
    {
        DEBUG_LOG("\nIn ServerAgent: "
                "sendPackage(): write data error!\n");
        return FAILED;
    }

    return SUCCESSFUL;
}
