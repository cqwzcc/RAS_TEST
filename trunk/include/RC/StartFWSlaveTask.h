/*************************************************************************
	> File Name: StartFWSlaveTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Mon 30 Mar 2015 07:05:47 AM PDT
 ************************************************************************/

#ifndef _STARTFWSLAVETASK_H
#define _STARTFWSLAVETASK_H
#include "ContainResourceTask.h"
#include "protocol/FwmRcProtocol.pb.h"
#include "common/comm/BaseHeader.h"

#include <string>
#include <inttypes.h>

using std::string;

namespace rc
{

const uint32_t STARTFWSLAVETASK_DOPARSE = 1;
const uint32_t STARTFWSLAVETASK_ALLOCA_RESOURCE = 2;
const uint32_t STARTFWSLAVETASK_SCHEDULER = 3;
const uint32_t STARTFWSLAVETASK_UPDATE_RESOURCE = 4;
const uint32_t STARTFWSLAVETASK_WAIT_NC_ACK = 5;
const uint32_t STARTFWSLAVETASK_ERROR_FINISH_TASK = 6;
const uint32_t STARTFWSLAVETASK_FINISH_TASK = 7;

struct SlaveModuleInfo
{
    string startModuleName;
    string IP;
    uint32_t listenPortNum;

    double cpuNum;
    uint32_t cpuMemSize;
    uint32_t gpuNum;

    vector<string> gpuNames;
    vector<uint32_t> gpuMemSizes;
};

class StartFWSlaveTask : public ContainResourceTask
{
public:
    StartFWSlaveTask();
    ~StartFWSlaveTask();

    void setMsgHeader(MsgHeader &msgHeader, uint32_t cmd, uint32_t len, uint64_t tid);
    
    int goNext();
    int doParse();
    int allocaResource();
    unsigned int schedule();
    void rollBack(unsigned int );
    int setTaskSchedulerType(StartFWSlaveTask *, string);
    int addFWInstanceResource( uint32_t, const string &, const struct ApplyUseRes& );
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
        m_frameworkInstanceID = frameworkInstanceID;
    }
    uint32_t getFWInstanceID() const
    {
        return m_frameworkInstanceID;
    }
//for chilerenTask
    void setChildrenModuleInfo(struct SlaveModuleInfo childrenModuleInfo)
    {
        m_childrenModuleInfo = childrenModuleInfo;
    }
    struct SlaveModuleInfo getChilerenModuleInfo() const
    {
        return m_childrenModuleInfo;
    }

    void setFatherID(unsigned int fatherID)
    {
        m_fatherID = fatherID;
    }
    unsigned int getFatherID()
    {
        return m_fatherID;
    }

    void setChildrenFlagID(unsigned int childrenFlagID)
    {
        m_childrenFlagID = childrenFlagID;
    }
    unsigned int getChildrenFlagID() const
    {
        return m_childrenFlagID;
    }
    void setNCIP(const string& ncIP)
    {
        m_NCIP = ncIP;
    }
    string getNCIP() const
    {
        return m_NCIP;
    }
    void setSlaveModuleID(uint32_t slaveModuleID)
    {
        m_slaveModuleID = slaveModuleID;
    }
    uint32_t getSlaveModuleID() const
    {
        return m_slaveModuleID;
    }
    uint32_t getSelfModuleID() const
    {
        return m_selfModuleID;
    }
    void setFWMIP(const string& FWMIP)
    {
        m_FWMIP = FWMIP;
    }
    string getFWMIP() const
    {
        return m_FWMIP;
    }
    void setFWMPort(uint32_t FWMPort)
    {
        m_FWMPort = FWMPort;
    }
    uint32_t getFWMPort() const
    {
        return m_FWMPort;
    }
private:
    uint32_t m_FWMAgentID;
    uint32_t m_frameworkID;
    uint32_t m_frameworkInstanceID;
    uint32_t m_selfModuleID;
    string m_FWMIP;
    uint32_t m_FWMPort;

    unsigned int m_childFlag;
    vector<struct SlaveModuleInfo> m_slaveModuleInfos;
    vector<StartFWSlaveTask *> m_childrenTasks;

//for childreTask
    struct SlaveModuleInfo m_childrenModuleInfo;
    unsigned int m_childrenFlagID;
    unsigned int m_fatherID;
    uint32_t m_slaveModuleID;
    string m_NCIP;
};
}
#endif
