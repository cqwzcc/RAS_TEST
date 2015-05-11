#ifndef _RC_TASKTYPE_H_
#define _RC_TASKTYPE_H_
#include <inttypes.h>

const uint32_t NC_REG_TASK = 1;
const uint32_t NC_HEART_BEAT_TASK = 2;
const uint32_t START_FW_ROOT_TASK = 3;

const uint32_t FWM_REG_TASK = 4;
const uint32_t START_FW_SLAVE_TASK = 5;
const uint32_t REQUEST_RES_TASK = 6;

const uint32_t RETURN_RES_TASK = 7;
const uint32_t STOP_MODULE_TASK = 8;
const uint32_t CLOSE_SELF_TASK = 9;

const uint32_t FWM_HEART_BEAT_TASK = 10;
const uint32_t CLOSE_INSTANCE_TASK = 11;
const uint32_t GET_PLAT_RES_TASK = 12;

const uint32_t GET_INSTANCE_RES_TASK = 13;
#endif
