/*************************************************************************
	> File Name: StopModuleTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Fri 03 Apr 2015 12:45:37 AM PDT
 ************************************************************************/

#ifndef _STOPMODULETASK_H
#define _STOPMODULETASK_H

#include "ContainResourceTask.h"  
#include "FWInstance.h"
#include "FWIManager.h"
#include "common/comm/BaseHeader.h"
#include "protocol/FwmRcProtocol.pb.h"
#include "CloseModuleBaseTask.h"

#include <string>
#include <list>
#include <inttypes.h>
using std::string;
using std::list;

namespace rc
{

const uint32_t STOPMODULETASK_DOPARSE = 1;
const uint32_t STOPMODULETASK_CREATE_ORDER = 2;
const uint32_t STOPMODULETASK_SCHEDULER = 3;
const uint32_t STOPMODULETASK_UPDATE_RESOURCE = 4;
const uint32_t STOPMODULESUBTASK_WAIT_NC_ACK = 5;
const uint32_t STOPMODULETASK_FINISH_TASK = 6;
const uint32_t STOPMODULETASK_ERROR_FINISH_TASK = 7;

class StopModuleTask : public CloseModuleBaseTask
{
public:
    StopModuleTask();
    ~StopModuleTask();

    int goNext();
    int doParse();
};

}
#endif
