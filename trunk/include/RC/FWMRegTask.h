/*************************************************************************
	> File Name: FWMRegTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Mon 30 Mar 2015 12:40:25 AM PDT
 ************************************************************************/

#ifndef _FWMREGTASK_H
#define _FWMREGTASK_H

#include "Task.h"

#include "common/comm/Error.h"

#include <string>
#include <inttypes.h>

using std::string;

namespace rc
{
    
const uint32_t FWMREGTASK_DOPARSE = 1;
const uint32_t FWMREGTASK_INSERT_ENTRY = 2;
const uint32_t FWMREGTASK_FINISH_TASK = 3;

class FWMRegTask : public Task
{
public:
    FWMRegTask();
    ~FWMRegTask();

    int goNext();
    int sendAckToFWM(int);
    int doParse();
    void addQueryEntryToSAS();

    void setAgentID(uint32_t agentID)
    {
        m_FWMAgentID = agentID;
    }
    uint32_t getAgentID() const
    {
        return m_FWMAgentID;
    }

    void setFWMIP(const string& FWMIP)
    {
        m_FWMIP = FWMIP;
    }
    string getFWMIP(  ) const
    {
        return m_FWMIP;
    }

    void setFWMTaskID( uint64_t taskID )
    {
        m_FWMTaskID = taskID;
    }
    uint64_t getFWMTaskID() const
    {
        return m_FWMTaskID;
    }

private:
    uint32_t m_FWMAgentID;

    string m_FWMIP;
    uint32_t m_FWMPort;
    uint64_t m_FWMTaskID;
    uint32_t m_frameworkID;
    uint32_t m_frameworkInstanceID;

};
}
#endif
