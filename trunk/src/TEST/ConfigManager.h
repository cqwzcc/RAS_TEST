#ifndef _AL_CONFIGMANAGER_H_
#define _AL_CONFIGMANAGER_H_

#include "common/sys/Singleton.h"

#include <string>
#include <stdint.h>
#include <inttypes.h>
#include <vector>

using std::string;
using std::vector;

class ConfigManager : public Singleton<ConfigManager>
{
public:
    friend class Singleton<ConfigManager>;

    ConfigManager();
    ~ConfigManager();

    int configWithXML(const char*);

    uint32_t getFrameworkId() const
    {
        return m_frameworkId;
    }

    uint32_t getFWInstanceId() const
    {
        return m_FWInstanceId;
    }

    uint32_t getModuleId() const
    {
        return m_moduleId;
    }
    const vector<uint32_t>& getListenPort() const
    {
        return m_listenPorts;
    }
    string getRcIp() const
    {
        return m_RcIp;
    }
    uint32_t getRcPort() const
    {
        return m_RcPort;
    }
    string getSelfIp() const
    {
        return m_selfIp;
    }
    string getFwmIp() const
    {
        return m_FwmIp;
    }
    uint32_t getFwmPort() const
    {
        return m_FwmPort;
    }

    vector<string> split(const string&);
private:
    uint32_t m_frameworkId;
    uint32_t m_FWInstanceId;
    uint32_t m_moduleId;
    vector<uint32_t> m_listenPorts;
    string m_RcIp;
    uint32_t m_RcPort;
    string m_selfIp;
    string m_FwmIp;
    uint32_t m_FwmPort;
};

#endif
