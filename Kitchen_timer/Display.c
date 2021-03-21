/*
 * Display.c
 *
 * Created: 2021/02/25 6:24:36
 *  Author: Kazu-SK
 */ 


#include "Display.h"


void DynamicDrive(uint8_t disp[]){
	
	//PORTB = OFF;
	PORTD = OFF;
	DisplaySegment(disp[SECONDS_DIG1]);
	PORTC = DISPLAY_DIG4;
	_delay_ms(LIGHT_TIME);
	
	//PORTB = OFF;
	PORTD = OFF;
	DisplaySegment(disp[SECONDS_DIG2]);
	PORTC = DISPLAY_DIG3;
	_delay_ms(LIGHT_TIME);
	
	//PORTB = OFF;
	PORTD = OFF;
	DisplaySegment(disp[MINUTE_DIG1]);
	//PORTB ^= 1 << PORTB7;    //Turn on the DP.
	PORTD ^= 1 << PORTD7;    //Turn on the DP.
	PORTC = DISPLAY_DIG2;
	_delay_ms(LIGHT_TIME);
	
	//PORTB = OFF;
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
			//PORTB = SEGMENT_NUM0;
			PORTD = SEGMENT_NUM0;
			break;
		case DISPLAY_NUM1:
			//PORTB = SEGMENT_NUM1;
			PORTD = SEGMENT_NUM1;
			break;
		case DISPLAY_NUM2:
			//PORTB = SEGMENT_NUM2;
			PORTD = SEGMENT_NUM2;
			break;
		case DISPLAY_NUM3:
			//PORTB = SEGMENT_NUM3;
			PORTD = SEGMENT_NUM3;
			break;
		case DISPLAY_NUM4:
			//PORTB = SEGMENT_NUM4;
			PORTD = SEGMENT_NUM4;
			break;
		case DISPLAY_NUM5:
			//PORTB = SEGMENT_NUM5;
			PORTD = SEGMENT_NUM5;
			break;
		case DISPLAY_NUM6:
			//PORTB = SEGMENT_NUM6;
			PORTD = SEGMENT_NUM6;
			break;
		case DISPLAY_NUM7:
			//PORTB = SEGMENT_NUM7;
			PORTD = SEGMENT_NUM7;
			break;
		case DISPLAY_NUM8:
			//PORTB = SEGMENT_NUM8;
			PORTD = SEGMENT_NUM8;
			break;
		case DISPLAY_NUM9:
			//PORTB = SEGMENT_NUM9;
			PORTD = SEGMENT_NUM9;
			break;
		default:
			//PORTB = SEGMENT_ERROR;
			PORTD = SEGMENT_ERROR;
			break;
	}
	
	
}