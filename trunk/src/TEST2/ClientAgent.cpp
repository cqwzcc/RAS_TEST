/*
 * =====================================================================================
 *
 *       Filename:  ClientAgent.cpp
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

#include "ClientAgent.h"
#include "protocol/AlProtocol.pb.h"
#include "protocol/RASCmdCode.h"
#include "protocol/RASErrorCode.h"
#include "header.h"

#include "common/comm/TaskManager.h"
#include "common/log/log.h"

ClientAgent::ClientAgent()
{

}

ClientAgent::ClientAgent(const SocketAddress &addr):
    TCPAgent(addr)
{

}

ClientAgent::ClientAgent(const TCPSocket &sock, const SocketAddress &addr):
    TCPAgent(sock,addr)
{

}

ClientAgent::~ClientAgent()
{
}

void
ClientAgent::readBack(InReq &req)
{
    switch (req.m_msgHeader.cmd)
    {
        case MSG_BC_SAS_GET_BUSINESS_ENTRY:
        {
            break;
        }
        default:
            break;
    }
}

void
ClientAgent::writeBack(bool result)
{
    if (!result)
    {
        ERROR_LOG("\nIn ClientAgent: "
                "writeBack(): write out error!\n");
    }
}

int
ClientAgent::sendPackage(MsgHeader &header, const char *dataStr)
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
        DEBUG_LOG("\nIn ClientAgent: "
                "sendPackage(): write data error!\n");
        return FAILED;
    }

    return SUCCESSFUL;
}
