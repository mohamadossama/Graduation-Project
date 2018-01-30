#include "uart.h"

#define M2_READY 0x10

int main(void)
{
	UART_init(); // initialize UART
	while(UART_recieveByte() != M2_READY){} // wait until MC2 is ready
	UART_sendString("m1_30#"); // send the required string to MC2
	
	while(1)
	{
		
	}
}
