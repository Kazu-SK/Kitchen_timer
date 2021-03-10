/*
 * Display.c
 *
 * Created: 2021/02/25 6:24:36
 *  Author: Kazu-SK
 */ 


#include "Display.h"


void DynamicDrive(uint8_t disp[]){
	
	PORTB = OFF;
	DisplaySegment(disp[0]);
	PORTC = DISPLAY_DIG4;
	_delay_ms(LIGHT_TIME);
	
	PORTB = OFF;
	DisplaySegment(disp[1]);
	PORTC = DISPLAY_DIG3;
	_delay_ms(LIGHT_TIME);
	
	PORTB = OFF;
	DisplaySegment(disp[2]);
	PORTB ^= 1 << PORTB7;    //Turn on the DP.
	PORTC = DISPLAY_DIG2;
	_delay_ms(LIGHT_TIME);
	
	PORTB = OFF;
	DisplaySegment(disp[3]);
	PORTC = DISPLAY_DIG1;
	_delay_ms(LIGHT_TIME);
}


void DisplayFlick(){
	
	PORTC = DISPLAY_DIG4;
	_delay_ms(LIGHT_TIME);

	PORTC = DISPLAY_DIG3;
	_delay_ms(2);

	PORTC = DISPLAY_DIG2;
	_delay_ms(LIGHT_TIME);
	
	PORTC = DISPLAY_DIG1;
	_delay_ms(LIGHT_TIME);
}


void DisplaySegment(uint8_t num){
	
	switch(num){
		case 0:
			PORTB = DISPLAY_NUM0;
			break;
		case 1:
			PORTB = DISPLAY_NUM1;
			break;
		case 2:
			PORTB = DISPLAY_NUM2;
			break;
		case 3:
			PORTB = DISPLAY_NUM3;
			break;
		case 4:
			PORTB = DISPLAY_NUM4;
			break;
		case 5:
			PORTB = DISPLAY_NUM5;
			break;
		case 6:
			PORTB = DISPLAY_NUM6;
			break;
		case 7:
			PORTB = DISPLAY_NUM7;
			break;
		case 8:
			PORTB = DISPLAY_NUM8;
			break;
		case 9:
			PORTB = DISPLAY_NUM9;
			break;
		default:
			PORTB = DISPLAY_ERROR;
			break;
	}
	
	
}