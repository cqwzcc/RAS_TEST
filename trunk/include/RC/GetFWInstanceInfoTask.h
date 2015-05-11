/*************************************************************************
	> File Name: GetFWInstanceInfoTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Tue 07 Apr 2015 06:28:59 AM PDT
 ************************************************************************/

#ifndef _GETFWINSTANCEINFOTASK_H
#define _GETFWINSTANCEINFOTASK_H

#include "Task.h"
#include "common/comm/BaseHeader.h"
#include "protocol/AlProtocol.pb.h"

namespace rc 
{

const uint32_t GETFWINSTANCEINFOTASK_DOPARSE = 1;
const uint32_t GETFWINSTANCEINFOTASK_GETINFO = 2;
const uint32_t GETFWINSTANCEINFOTASK_FINISH_TASK = 3;

class GetFWInstanceInfoTask : public Task
{
public:
    GetFWInstanceInfoTask();
    ~GetFWInstanceInfoTask();

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

    int getAllFrameworkResourceInfo(AlProto::FrameworkInstanceResourceInfo &);
    int getAllMachineResourceInfo(AlProto::FrameworkInstanceResourceInfo &);
    void sendALAck(string &);
private:
    uint32_t m_agentID;
};

}
#endif
