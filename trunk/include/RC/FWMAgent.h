#ifndef _RC_FWMAGENT_H_
#define _RC_FWMAGENT_H_

#include "InfoFromFWMToRC.h"

#include "common/comm/TCPAgent.h"
#include "common/comm/Epoll.h"

namespace rc
{

class FWMAgent : public TCPAgent
{
public:
    FWMAgent(const TCPSocket &sock,
            const SocketAddress &oppoAddr);
    ~FWMAgent();

    int init(void);
    void readBack(InReq&);
    void recycler(void);

    void setMsgHeader(uint32_t, uint32_t err = 0, 
            uint32_t len = 0, uint64_t tid = 0);
    int sendPackage(MsgHeader&, string data = "");

    void setModuleID(uint32_t moduleID)
    {
        m_FWMModuleID = moduleID;
    }
    uint32_t getModuleID() const
    {
        return m_FWMModuleID;
    }
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
    void reInit();
    
    string m_FWMIP;
    uint32_t m_FWMModuleID;
    MsgHeader m_msg;
    InfoFromFWMToRC *m_pInfoFromFWMToRC;
    uint32_t m_frameworkID;
    uint32_t m_fwInstanceID;
};

}

#endif
