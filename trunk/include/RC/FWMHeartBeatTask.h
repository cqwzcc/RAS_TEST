/*************************************************************************
	> File Name: FWMHeartBeatTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Mon 06 Apr 2015 08:53:12 PM PDT
 ************************************************************************/

#ifndef _FWMHEARTBEATTASK_H
#define _FWMHEARTBEATTASK_H

#include "Task.h"
#include "common/comm/BaseHeader.h"

namespace rc
{

uint32_t const FWMHEARTBEATTASK_DOPARSE = 1;
uint32_t const FWMHEARTBEATTASK_SEARCH = 2;
uint32_t const FWMHEARTBEATTASK_FINISH_TASK = 3;

class FWMHeartBeatTask : public Task
{
public:
    FWMHeartBeatTask();
    ~FWMHeartBeatTask();

    int goNext();
    int doParse();

    void sendFwmAck(const string& str);
    void setMsgHeader(MsgHeader &msgHeader, uint32_t cmd, uint32_t len, uint64_t tid);

    void setAgentID(uint32_t agentID)
    {
        m_AgentID = agentID;
    }
    uint32_t getAgentID() const
    {
        return m_AgentID;
    }

    void setFrameworkID(uint32_t frameworkID)
    {
        m_frameworkID = frameworkID;
    }
    uint32_t getFrameworkID() const
    {
        return m_frameworkID;
    }

    void setFWInstanceID(uint32_t frameworkInstanceID)
    {
        m_FWInstanceID = frameworkInstanceID;
    }
    uint32_t getFWInstanceID() const
    {
        return m_FWInstanceID;
    }
private:
    uint32_t m_AgentID;
    uint32_t m_frameworkID;
    uint32_t m_FWInstanceID;
    uint32_t m_selfModuleID;
};

}
#endif
