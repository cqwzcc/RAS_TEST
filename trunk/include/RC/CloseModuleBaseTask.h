/*************************************************************************
	> File Name: CloseModuleBaseTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Mon 06 Apr 2015 06:56:33 PM PDT
 ************************************************************************/

#ifndef _CLOSEMODULEBASETASK_H
#define _CLOSEMODULEBASETASK_H


#include "ContainResourceTask.h"  
#include "FWInstance.h"
#include "FWIManager.h"
#include "common/comm/BaseHeader.h"
#include "protocol/FwmRcProtocol.pb.h"

#include <string>
#include <list>
#include <inttypes.h>
using std::string;
using std::list;

namespace rc
{
class CloseModuleBaseTask : public Task
{
public:
    CloseModuleBaseTask();
    ~CloseModuleBaseTask();

    void setMsgHeader(MsgHeader &msgHeader, uint32_t cmd, uint32_t len, uint64_t tid);
    virtual int goNext()
    {
        return SUCCESSFUL;
    }
    virtual int doParse()
    {
        return SUCCESSFUL;
    }
    void sendFwmAck(const string &, uint32_t);
    int createStopModuleOrder();
    int moduleTreeLevelorder(uint32_t topModuleID);
    uint32_t getModuleID()
    {
        return *m_iterModuleFlag;
    }
    uint32_t getNextModulePID()
    {
        FWInstance *pFWInstance = (FWIManager::getInstance()
                                  ->get(m_FWInstanceID));
        IPProcess iPProcess = pFWInstance->getModuleIPProcess(getModuleID());
        m_iterModuleFlag++;
        return iPProcess.getProcessID();
    }

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

protected:
    uint32_t m_AgentID;
    uint32_t m_frameworkID;
    uint32_t m_FWInstanceID;
    uint32_t m_selfModuleID;

    list<uint32_t> m_stopModuleIDs;
    list<uint32_t>::iterator m_iterModuleFlag;

    vector<uint32_t> m_topStopModuleIDs;
};

}

#endif
