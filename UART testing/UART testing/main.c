/*
 * UART testing.c
 *
	using ATMEL AVR atmega16
 * Created: 30-Jan-18 1:44:55 PM
 * Author : mossa
 */ 

#include <avr/io.h>
#include "uart.h"

int main(void)
{
    /* Replace with your application code */
	UART_init();
    while (1) 
    {
		UART_sendString("m1_18");
		_delay_ms(500);
    }
}

