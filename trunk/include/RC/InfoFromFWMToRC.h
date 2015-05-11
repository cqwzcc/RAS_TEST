#ifndef _RC_INFOFROMFWMTORC_H_
#define _RC_INFOFROMFWMTORC_H_

#include "common/comm/BaseReq.h"

#include <stdint.h>
#include <string>

using std::string;

namespace rc
{

class InfoFromFWMToRC
{
public:
    InfoFromFWMToRC(uint32_t, string, uint32_t, uint32_t);
    ~InfoFromFWMToRC();

    int handleFWMReq(InReq &);
    int taskReportFromFWM(uint32_t, uint64_t);
    int doRegister(uint64_t, string);
    int startSlave(string&);
    int requestResource(string&);
    int returnResource(string&);
    int stopModule(string &);
    int closeSelf(string &);
    int heartBeat(string &);
    void sendAckToFWM(uint32_t, uint32_t, uint32_t, uint32_t);
    uint64_t mergeID(uint32_t, uint32_t) const;

    void setFrameworkID(uint32_t frameworkID)
    {
        m_frameworkID = frameworkID;
    }
    uint32_t getFrameworkID() const
    {
        return m_frameworkID;
    }
    void setFwInstanceID(uint32_t fwInstanceID)
    {
        m_fwInstanceID = fwInstanceID;
    }
    uint32_t getFwInstanceID() const
    {
        return m_fwInstanceID;
    }
private:
    uint32_t m_FWMAgentID;
    string m_FWMIP;
    uint32_t m_frameworkID;
    uint32_t m_fwInstanceID;

};

}

#endif
