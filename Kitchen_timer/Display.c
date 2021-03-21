/*
 * Display.c
 *
 * Created: 2021/02/25 6:24:36
 *  Author: Kazu-SK
 */ 


#include "Display.h"


void DynamicDrive(uint8_t disp[]){
	
	PORTD = OFF;
	DisplaySegment(disp[SECONDS_DIG1]);
	PORTC = DISPLAY_DIG4;
	_delay_ms(LIGHT_TIME);
	
	PORTD = OFF;
	DisplaySegment(disp[SECONDS_DIG2]);
	PORTC = DISPLAY_DIG3;
	_delay_ms(LIGHT_TIME);
	
	PORTD = OFF;
	DisplaySegment(disp[MINUTE_DIG1]);
	PORTD ^= 1 << PORTD7;    //Turn on the DP.
	PORTC = DISPLAY_DIG2;
	_delay_ms(LIGHT_TIME);
	
	PORTD = OFF;
	DisplaySegment(disp[MINUTE_DIG2]);
	PORTC = DISPLAY_DIG1;
	_delay_ms(LIGHT_TIME);
}


void DisplayFlick(){
	
	PORTC = DISPLAY_DIG4;
	_delay_ms(LIGHT_TIME);

	PORTC = DISPLAY_DIG3;
	_delay_ms(LIGHT_TIME);

	PORTC = DISPLAY_DIG2;
	_delay_ms(LIGHT_TIME);
	
	PORTC = DISPLAY_DIG1;
	_delay_ms(LIGHT_TIME);
}


void DisplaySegment(uint8_t num){
	
	switch(num){
		case DISPLAY_NUM0:
			PORTD = SEGMENT_NUM0;
			break;
		case DISPLAY_NUM1:
			PORTD = SEGMENT_NUM1;
			break;
		case DISPLAY_NUM2:
			PORTD = SEGMENT_NUM2;
			break;
		case DISPLAY_NUM3:
			PORTD = SEGMENT_NUM3;
			break;
		case DISPLAY_NUM4:
			PORTD = SEGMENT_NUM4;
			break;
		case DISPLAY_NUM5:
			PORTD = SEGMENT_NUM5;
			break;
		case DISPLAY_NUM6:
			PORTD = SEGMENT_NUM6;
			break;
		case DISPLAY_NUM7:
			PORTD = SEGMENT_NUM7;
			break;
		case DISPLAY_NUM8:
			PORTD = SEGMENT_NUM8;
			break;
		case DISPLAY_NUM9:
			PORTD = SEGMENT_NUM9;
			break;
		default:
			PORTD = SEGMENT_ERROR;
			break;
	}
	
	
}