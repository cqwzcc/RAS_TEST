/*************************************************************************
	> File Name: GetPlatformResInfoTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Tue 07 Apr 2015 02:29:02 AM PDT
 ************************************************************************/

#ifndef _GETPLATFORMRESINFOTASK_H
#define _GETPLATFORMRESINFOTASK_H

#include "Task.h"
#include "common/comm/BaseHeader.h"
#include "protocol/AlProtocol.pb.h"

namespace rc 
{

const uint32_t GETPLATFORMRESINFOTASK_DOPARSE = 1;
const uint32_t GETPLATFORMRESINFOTASK_GETINFO = 2;
const uint32_t GETPLATFORMRESINFOTASK_SEND_TO_AL = 3;
const uint32_t GETPLATFORMRESINFOTASK_FINISH_TASK = 4;

class GetPlatformResInfoTask : public Task
{
public:
    GetPlatformResInfoTask();
    ~GetPlatformResInfoTask();

    void setMsgHeader(MsgHeader &msgHeader, uint32_t cmd, uint32_t err, uint32_t len, uint64_t tid);
    int goNext();
    int doParse();

    void setAgentID(uint32_t agentID)
    {
        m_agentID = agentID;
    }
    uint32_t getAgentID() const
    {
        return m_agentID;
    }

    int getPlatformRes(AlProto::PlatformAndMachineResouceInfo &);
    int getEachMachineRes(AlProto::PlatformAndMachineResouceInfo &);
    void sendALAck(string &);
private:
    uint32_t m_agentID;
};

}

#endif
