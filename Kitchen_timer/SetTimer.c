/*
 * SetTimer.c
 *
 * Created: 2021/02/25 6:21:09
 *  Author: Kazu-SK
 */ 

#include "SetTimer.h"

void MinutesCounter(uint8_t d_num[]){
	
	if(d_num[MINUTE_DIG1] != 9)
		d_num[MINUTE_DIG1]++;
	else{
		d_num[MINUTE_DIG1] = 0;
		
		if(d_num[MINUTE_DIG2] != 9)
			d_num[MINUTE_DIG2]++;
		else
			d_num[MINUTE_DIG2] = 0;
	}
}

void SecondsCounter(uint8_t d_num[]){

	if(d_num[SECONDS_DIG2] != 5)
		d_num[SECONDS_DIG2]++;
	else
		d_num[SECONDS_DIG2] = 0;
}


void SetMinutes(uint8_t d_num[]){
	
	uint32_t *p;
	float pulse_count = 0.0;
	float push_time = 0.0;
	

	MinutesCounter(d_num);

	TCNT1 = 0;
	//while(PIND & MINUTE_SWITCH){
	while(PINB & MINUTE_SWITCH){
		DynamicDrive(d_num);
		
		pulse_count = TCNT1;
		push_time = pulse_count * M_CYCLE / F;
		
		if(push_time >= LONG_PLESS_TIME){
			
			TCNT1 = 0;
			
			//while(PIND & MINUTE_SWITCH && !(PIND & SECONDS_SWITCH)){
			while(PINB & MINUTE_SWITCH && !(PINB & SECONDS_SWITCH)){
				
				pulse_count = TCNT1;
				push_time = pulse_count * M_CYCLE / F;
				
				if (push_time >= LONG_PLESS_COUNTER)
				{
					MinutesCounter(d_num);
					TCNT1 = 0;
				}
				
				DynamicDrive(d_num);
			}
		}
		
		//if(PIND & SECONDS_SWITCH){
		if(PINB & SECONDS_SWITCH){
			p = (uint32_t *)d_num;
			*p = 0x00000000;
			
			//while(PIND & SECONDS_SWITCH || PIND & MINUTE_SWITCH){
			while(PINB & SECONDS_SWITCH || PINB & MINUTE_SWITCH){
				DynamicDrive(d_num);
			}
			
			break;
		}
	}
	
}

void SetSeconds(uint8_t d_num[]){
	
	uint32_t *p;
	
	
	SecondsCounter(d_num);
	
	//while(PIND & SECONDS_SWITCH){
	while(PINB & SECONDS_SWITCH){
		DynamicDrive(d_num);
		
		//if(PIND & MINUTE_SWITCH){
		if(PINB & MINUTE_SWITCH){
			p = (uint32_t *)d_num;
			*p = 0x00000000;
			
			//while(PIND & SECONDS_SWITCH || PIND & MINUTE_SWITCH){
			while(PINB & SECONDS_SWITCH || PINB & MINUTE_SWITCH){
				DynamicDrive(d_num);
			}
			
			break;
		}
	}
	
}