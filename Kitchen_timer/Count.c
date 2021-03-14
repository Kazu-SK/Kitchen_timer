/*
 * Count.c
 *
 * Created: 2021/02/25 6:37:01
 *  Author: Kazu-SK
 */ 

#include "Count.h"


uint8_t *remain_time;


ISR(TIMER1_COMPA_vect){

	TimeDisplay();
}

ISR(TIMER1_COMPB_vect){
	
	if(PORTB == OFF)
		PORTB = ALL_LIGHT;
	else
		PORTB = OFF;
	
	PORTD ^= 1 << DDD7;
	TCNT1 = 0; 
}


void TimeDisplay(){
	
	if(remain_time[SECONDS_DIG1] == 0){
		remain_time[SECONDS_DIG1] = 9;	
			
		if(remain_time[SECONDS_DIG2] == 0){
			remain_time[SECONDS_DIG2] = 5;
			
			if (remain_time[MINUTE_DIG1] == 0){
				remain_time[MINUTE_DIG2]--;
				remain_time[MINUTE_DIG1] = 9;
			}
			else
				remain_time[MINUTE_DIG1]--;	
		}
		else
			remain_time[SECONDS_DIG2]--;		
	}
	else
		remain_time[SECONDS_DIG1]--;
	
}

void CountDown(uint8_t d_num[]){

	remain_time = d_num;
	uint16_t hold_timer = 0;
	uint32_t *p;
	uint8_t reset_signal = RESET_OFF;


	TCNT1 = 0;	
	TIFR1 |= 1 << OCF1A;
	SREG |= 0x80;
	//sei();
	

	while (PIND & START_SWITCH)
	{
	if(d_num[SECONDS_DIG1] == 0 && d_num[SECONDS_DIG2] == 0 && d_num[MINUTE_DIG1] == 0 && d_num[MINUTE_DIG2] == 0){
		cli();
		break;
	}
		
	DynamicDrive(d_num);
	}

	for(;;){

	if(d_num[SECONDS_DIG1] == 0 && d_num[SECONDS_DIG2] == 0 && d_num[MINUTE_DIG1] == 0 && d_num[MINUTE_DIG2] == 0){
		cli();
		break;
	}

	if (PIND & START_SWITCH){
			
		cli();
		hold_timer = TCNT1;
			
		while (PIND & START_SWITCH){
			DynamicDrive(d_num);
		}
			
		while(!(PIND & START_SWITCH) && !(PIND & MINUTE_SWITCH)){
			DynamicDrive(d_num);
		}
			
		if(PIND & MINUTE_SWITCH){
				
			p = (uint32_t *)d_num;
			*p = 0x00000000;
				
			while (PIND & MINUTE_SWITCH){
				DynamicDrive(d_num);
			}				
				
			reset_signal = RESET_ON;
				
			break;
		}
			
		TCNT1 = hold_timer;
		TIFR1 |= 1 << OCF1A;
		//sei();	
		SREG |= 0x80;
			
		while (PIND & START_SWITCH)
		{
			DynamicDrive(d_num);
				
			if(d_num[SECONDS_DIG1] == 0 && d_num[SECONDS_DIG2] == 0 && d_num[MINUTE_DIG1] == 0 && d_num[MINUTE_DIG2] == 0)
				break;
		}			
	}
		
	DynamicDrive(d_num);
	}

	//TCCR1A = 0b00000000;
	//TCCR1B = 0b00001100;

	PORTB = 0x00;

    if(reset_signal == RESET_OFF){
		
		TIMSK1 = 0b00000100;
		
		OCR1B = 15624;

		TCNT1 = 0;
		TIFR1 |= 1 << OCF1A;
		SREG |= 0x80;
	
		while(PIND & START_SWITCH){
			DisplayFlick();
		}
	
		for(;;){
		
			if(PIND & START_SWITCH){
				cli();
				PORTD = !(PORTD | 0xFF);
				break;
			}
	
			DisplayFlick();
		}
	
		while(PIND & START_SWITCH){
			DynamicDrive(d_num);
		}
		
		TIMSK1 = 0b00000010;
	}
	
}