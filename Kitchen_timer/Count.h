/*
 * Count.h
 *
 * Created: 2021/02/25 6:36:38
 *  Author: Kazu-SK
 */ 


#ifndef COUNT_H_
#define COUNT_H_

#include "Display.h"
#include "Define.h"


#include <stdio.h>


extern uint8_t *remain_time;

void TimeDisplay();
void CountDown(uint8_t d_num[]);



#endif /* COUNT_H_ */