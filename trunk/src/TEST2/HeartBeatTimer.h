/*************************************************************************
	> File Name: HeartBeatTimer.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Sat 09 May 2015 05:55:59 AM PDT
 ************************************************************************/

#ifndef _HEARTBEATTIMER_H
#define _HEARTBEATTIMER_H

#include "common/Timer/Timer.h"

class HeartBeatTimer : public Timer
{
public:
    HeartBeatTimer(unsigned int, unsigned int);
    ~HeartBeatTimer();

    int doAction();
private:
    unsigned int id;

};

extern HeartBeatTimer *g_pHeartBeatTimer;

#endif
