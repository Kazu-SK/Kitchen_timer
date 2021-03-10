/*
 * SetTimer.c
 *
 * Created: 2021/02/25 6:21:09
 *  Author: Kazu-SK
 */ 

#include "SetTimer.h"

void MinutesCounter(uint8_t d_num[]){
	
	if(d_num[2] != 9)
		d_num[2]++;
	else{
		d_num[2] = 0;
		
		if(d_num[3] != 9)
			d_num[3]++;
		else
			d_num[3] = 0;
	}
}

void SecondsCounter(uint8_t d_num[]){

	if(d_num[1] != 5)
		d_num[1]++;
	else
		d_num[1] = 0;
}


void SetMinutes(uint8_t d_num[]){
	
	uint32_t *p;
	float pulse_count = 0.0;
	float push_time = 0.0;
	


	MinutesCounter(d_num);

	TCNT1 = 0;
	while(PIND & MINUTE_SWITCH){
		DynamicDrive(d_num);
		
		pulse_count = TCNT1;
		push_time = pulse_count * M_CYCLE / F;
		
		if(push_time >= 1){
			
			TCNT1 = 0;
			
			while(PIND & MINUTE_SWITCH && !(PIND & SECONDS_SWITCH)){
				
				pulse_count = TCNT1;
				push_time = pulse_count * M_CYCLE / F;
				
				if (push_time >= LONG_PLESS )
				{
					MinutesCounter(d_num);
					TCNT1 = 0;
				}
				
				DynamicDrive(d_num);
			}
		}
		
		if(PIND & SECONDS_SWITCH){
			p = (uint32_t *)d_num;
			*p = 0x00000000;
			
			while(PIND & SECONDS_SWITCH || PIND & MINUTE_SWITCH){
				DynamicDrive(d_num);
			}
			
			break;
		}
	}
	
}

void SetSeconds(uint8_t d_num[]){
	
	uint32_t *p;
	
	
	SecondsCounter(d_num);
	
	while(PIND & SECONDS_SWITCH){
		DynamicDrive(d_num);
		
		if(PIND & MINUTE_SWITCH){
			p = (uint32_t *)d_num;
			*p = 0x00000000;
			
			while(PIND & SECONDS_SWITCH || PIND & MINUTE_SWITCH){
				DynamicDrive(d_num);
			}
			
			break;
		}
	}
	
}