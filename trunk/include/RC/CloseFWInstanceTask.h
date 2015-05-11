/*************************************************************************
	> File Name: CloseFWInstanceTask.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Tue 07 Apr 2015 01:12:29 AM PDT
 ************************************************************************/

#ifndef _CLOSEFWINSTANCETASK_H
#define _CLOSEFWINSTANCETASK_H

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

const uint32_t CLOSEINSTANCETASK_DOPARSE = 1;
const uint32_t CLOSEINSTANCETASK_CREATE_ORDER = 2;
const uint32_t CLOSEINSTANCETASK_SCHEDULER = 3;
const uint32_t CLOSEINSTANCETASK_UPDATE_RESOURCE = 4;
const uint32_t CLOSEINSTANCETASK_WAIT_NC_ACK = 5;
const uint32_t CLOSEINSTANCETASK_FINISH_TASK = 6;
const uint32_t CLOSEINSTANCETASK_ERROR_FINISH_TASK = 7;

class CloseFWInstanceTask : public CloseModuleBaseTask
{
public:
    CloseFWInstanceTask();
    ~CloseFWInstanceTask();

    int goNext();
    int doParse();
    void setAlMsgHeader( MsgHeader &, uint32_t, uint32_t, uint32_t ,uint64_t );
};

}
#endif
