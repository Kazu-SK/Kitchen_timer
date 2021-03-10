/*
 * SetTimer.h
 *
 * Created: 2021/02/25 6:19:03
 *  Author: Kazu-SK
 */ 


#ifndef SETTIMER_H_
#define SETTIMER_H_

#include "Display.h"
#include "Define.h"


void MinutesCounter(uint8_t d_num[]);
void SecondsCounter(uint8_t d_num[]);

void SetMinutes(uint8_t d_num[]);
void SetSeconds(uint8_t d_num[]);


#endif /* SETTIMER_H_ */