/*
 * Kitchen_timer.c
 *
 * Created: 2021/02/20 20:41:41
 * Author : Kazu-SK
 */ 


#include "SetTimer.h"
#include "Display.h"
#include "Count.h"


int main(void)
{
	/* Replace with your application code */
	uint8_t display_num[4] = {0,0,0,0};
		
		
	DDRB = 0b11111111;
	DDRC = 0b00101111;
	DDRD = 0b10000000;
	

	TCCR1A = 0b00000000;
	TCCR1B = 0b00001100;
	
	TIMSK1 = 0b00000010;
	OCR1A = 31249;
	OCR1B = 15624;
	
	cli();

	for(;;)
	{
		if(PIND & (1 << PIND2)){
			TCCR1B ^= 1 << WGM12;
			SetMinutes(display_num);
			TCCR1B |= 1 << WGM12;
		}
		
		if(PIND & (1 << PIND3)){
			SetSeconds(display_num);
		}
		
		if(PIND & (1 << PIND4)){
			CountDown(display_num);
		}
		
		DynamicDrive(display_num);
	}
}
