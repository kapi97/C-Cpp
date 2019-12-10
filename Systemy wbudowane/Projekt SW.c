#include <avr/io.h>
#include <util/delay.h>
#include "HD44780.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	LCD_Initialize();
	char integer[1];
	int i = 1000;
	sprintf(integer, "%d", i);
	
	/*bool flaga1 = false;
	if(!(PINC & 1 << PC3)){
	flaga1 = true;
	_delay_ms(100);}*/
	
		/*DDRD = (0<<PD0); //do usuniêcia
		_delay_ms(500);    //do usuniêcia
		DDRD = (1<<PD0);*/ //do usuniêcia

	PORTD |= 1<<PD0;
	PORTD |= 1<<PD7;
	DDRD = (0<<PD1);
	sprintf(integer, "%d", i);
	LCD_WriteText(integer);

	while(1)
	{
		DDRD = (0<<PD1);
		//LCD_Clear();
		if(!(PINC & 1<<PC0))
		{
			i += 1000;
			_delay_ms(250);
			LCD_Clear();
			sprintf(integer, "%d", i);
			LCD_WriteText(integer);
		}
		if(!(PINC & 1<<PC1))
		{
			i += 1000;
			_delay_ms(250);
			LCD_Clear();
			sprintf(integer, "%d", i);
			LCD_WriteText(integer);
		}	
		if(!(PIND & (1<<PD7)))
		{
			_delay_ms(i);
			DDRB = (1<<PB0);
			_delay_ms(500);
			DDRB = (0<<PB0);
			_delay_ms(500);
			DDRB = (1<<PB1);
			_delay_ms(500);
			DDRB = (0<<PB1);
			_delay_ms(500);
			DDRB = (1<<PB2);
			_delay_ms(500);
			DDRB = (0<<PB2);
			_delay_ms(500);
			DDRB = (1<<PB3);
			_delay_ms(500);
			DDRB = (0<<PB3);
			_delay_ms(500);
			DDRB = (1<<PB4);
			_delay_ms(500);
			DDRB = (0<<PB4);
			_delay_ms(500);
			DDRB = (1<<PB5);
			_delay_ms(500);
			DDRB = (0<<PB5);
			_delay_ms(500);
			DDRB = (1<<PB6);
			_delay_ms(500);
			DDRB = (0<<PB6);
			_delay_ms(500);
			DDRB = (1<<PB7);
			_delay_ms(500);
			DDRB = (0<<PB7);
			_delay_ms(500);
		}	
	}
	return 0;
}
