/*************************************************************************
	> File Name: ReturnResTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Thu 02 Apr 2015 06:35:42 PM PDT
 ************************************************************************/

#ifndef _RETURNRESTASK_H
#define _RETURNRESTASK_H


#include "ContainResourceTask.h"  
#include "common/comm/BaseHeader.h"
#include "protocol/FwmRcProtocol.pb.h"
#include "RequestResTask.h"

#include <string>
#include <inttypes.h>
using std::string;

namespace rc
{

const uint32_t RETURNRESOURCETASK_DOPARSE = 1;
const uint32_t RETURNRESOURCETASK_ALLOC_RESOURCE = 2;
const uint32_t RETURNRESOURCETASK_SCHEDULER = 3;
const uint32_t RETURNRESOURCETASK_UPDATE_RESOURCE = 4;
const uint32_t RETURNRESOURCETASK_WAIT_NC_ACK = 5;
const uint32_t RETURNRESOURCETASK_FINISH_TASK = 6;
const uint32_t RETURNRESOURCETASK_ERROR_FINISH_TASK = 7;


class ReturnResTask : public ContainResourceTask
{
public:
    ReturnResTask();
    ~ReturnResTask();


    void setMsgHeader(MsgHeader &msgHeader, uint32_t cmd, uint32_t len, uint64_t tid);
    int goNext();
    int doParse();
    unsigned int allocResource();
    void rollBack(unsigned int );
    void sendFwmAck(const string &);
    struct TaskResourceInfo getNextTaskResInfo();

    void setAgentID(uint32_t agentID)
    {
        m_FWMAgentID = agentID;
    }
    uint32_t getAgentID() const
    {
        return m_FWMAgentID;
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
    uint32_t m_FWMAgentID;
    uint32_t m_frameworkID;
    uint32_t m_FWInstanceID;
    uint32_t m_selfModuleID;
    vector<struct TaskResourceInfo> m_taskResourceInfos;

    unsigned int m_moduleFlag;
};
}

#endif
