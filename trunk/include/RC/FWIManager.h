#ifndef _RC_FWIMANAGER_H_
#define _RC_FWIMANAGER_H_

#include <map>
#include <vector>
#include "common/sys/Singleton.h"

using std::map;
using std::vector;

namespace rc
{
class FWInstance;

class FWIManager : public Singleton<FWIManager>
{
public:
    friend class Singleton<FWIManager>;

    uint32_t add(FWInstance*);
    FWInstance* get(uint32_t) const;
    bool find(uint32_t) const;
    bool remove(uint32_t);
    void recycle(uint32_t);
    void recycleAll();
    vector<uint32_t> getAllInstanceID();

    FWInstance* createFWInstance();
    uint32_t generateInstanceID();
    uint32_t generateModuleID();

private:
    FWIManager();
    ~FWIManager();

    typedef map<uint32_t, FWInstance*> FWIMap;

    FWIMap m_map;
    uint32_t m_FWIID;
    uint32_t m_moduleID;
};
}
#endif
