#include "ConfigManager.h"

#include "header.h"
#include "common/xml/XMLConfig.h"
#include "common/util/util.h"

using util::conv::conv;

ConfigManager::ConfigManager():
    m_frameworkId(0),
    m_FWInstanceId(0),
    m_moduleId(0),
    m_listenPorts(),
    m_RcIp(),
    m_RcPort(0),
    m_selfIp(),
    m_FwmIp(),
    m_FwmPort(0)
{

}

ConfigManager::~ConfigManager()
{

}

int ConfigManager::configWithXML(const char *configFileName)
{
    XMLConfig *pXML = new XMLConfig(configFileName);
    string strFrameworkId, strFWInstanceId, strModuleId, strRcPort, strFwmPort;

    int ret;
    
    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/FRAMEWORK_ID", strFrameworkId);
    if(ret < 0)
    {
        delete pXML;
        return ret;
    }
    m_frameworkId = conv<uint32_t, string>(strFrameworkId);

    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/FRAMEWORK_INSTANCE_ID", strFWInstanceId);
    if(ret < 0)
    {
        delete pXML;
        return ret;
    }
    m_FWInstanceId = conv<uint32_t, string>(strFWInstanceId);

    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/MODULE_ID", strModuleId);
    if(ret < 0)
    {
        delete pXML;
        return ret;
    }
    m_moduleId = conv<uint32_t , string>(strModuleId);

    
    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/RC_IP", m_RcIp);
    if(ret < 0)
    {
        delete pXML;
        return ret;
    }
    
    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/RC_PORT", strRcPort);
    if (ret < 0){
        delete pXML;
        return ret;
    }
    m_RcPort = conv<uint32_t, string>(strRcPort);

    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/SELF_IP", m_selfIp);
    if ( ret < 0 ){
        delete pXML;
        return ret;
    }

    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/FWM_IP", m_FwmIp);
    if ( ret < 0 ){
        delete pXML;
        return ret;
    }

    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/FWM_PORT", strFwmPort);
    if ( ret < 0 ){
        delete pXML;
        return ret;
    }
    m_FwmPort = conv<uint32_t, string>(strFwmPort);

    string strData;
    ret = pXML->getFirstNodeValue("/CONFIG/RAS_CONFIG/LISTEN_PORT", strData);
    if ( ret < 0 ){
        delete pXML;
        return ret;
    }
    vector<string> vecStr = split(strData);
    for(unsigned int i = 0; i < vecStr.size(); i++){
        m_listenPorts.push_back(conv<uint32_t, string>(vecStr[i]));
    }

    delete pXML;
    return ret;
}

vector<string>
ConfigManager::split(const string& data)
{
    vector<string> elems;
    int start = 0;
    int end;
    while( ( end = data.find( ',', start) ) != string::npos ){
        elems.push_back( data.substr( start, end - start ) );
        start = end + 1;
    }
    elems.push_back( data.substr(start) );
    return elems;
}

