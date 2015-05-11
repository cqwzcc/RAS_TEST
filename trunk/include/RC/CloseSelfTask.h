/*************************************************************************
	> File Name: CloseSelfTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Mon 06 Apr 2015 07:51:19 PM PDT
 ************************************************************************/

#ifndef _CLOSESELFTASK_H
#define _CLOSESELFTASK_H

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

const uint32_t CLOSESELFTASK_DOPARSE = 1;
const uint32_t CLOSESELFTASK_CREATE_ORDER = 2;
const uint32_t CLOSESELFTASK_SCHEDULER = 3;
const uint32_t CLOSESELFTASK_UPDATE_RESOURCE = 4;
const uint32_t CLOSESELFTASK_WAIT_NC_ACK = 5;
const uint32_t CLOSESELFTASK_FINISH_TASK = 6;
const uint32_t CLOSESELFTASK_ERROR_FINISH_TASK = 7;

class CloseSelfTask : public CloseModuleBaseTask
{
public:
    CloseSelfTask();
    ~CloseSelfTask();

    int goNext();
    int doParse();
};

}
#endif
