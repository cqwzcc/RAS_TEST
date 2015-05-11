/*************************************************************************
	> File Name: RequestResTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Wed 01 Apr 2015 10:02:44 PM PDT
 ************************************************************************/

#ifndef _REQUESTRESTASK_H
#define _REQUESTRESTASK_H
#include "ContainResourceTask.h"  
#include "common/comm/BaseHeader.h"
#include "protocol/FwmRcProtocol.pb.h"

#include <string>
#include <inttypes.h>
using std::string;

namespace rc

{

const uint32_t APPLYRESOURCETASK_DOPARSE = 1;
const uint32_t APPLYRESOURCETASK_ALLOC_RESOURCE = 2;
const uint32_t APPLYRESOURCETASK_SCHEDULER = 3;
const uint32_t APPLYRESOURCETASK_UPDATE_RESOURCE = 4;
const uint32_t APPLYRESOURCETASK_WAIT_NC_ACK = 5;
const uint32_t APPLYRESOURCETASK_FINISH_TASK = 6;
const uint32_t APPLYRESOURCETASK_ERROR_FINISH_TASK = 7;

struct TaskResourceInfo
{
    uint32_t moduleID;
    double cpuNum;
    uint32_t cpuMemSize;
    uint32_t gpuNum;

    vector<string> gpuNames;
    vector<uint32_t> gpuMemSizes;

    string IP;
    uint32_t ProcessID;

public:
    TaskResourceInfo():
    moduleID(0),
    cpuNum(0.0),
    cpuMemSize(0),
    gpuNum(0),
    gpuNames(),
    gpuMemSizes(),
    IP(),
    ProcessID(0){}

};

class RequestResTask : public ContainResourceTask
{
public:
    RequestResTask();
    ~RequestResTask();

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
