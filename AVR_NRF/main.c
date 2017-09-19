/*
 * AVR_NRF.c
 *
 * Created: 15.09.2017 23:09:52
 * Author : ANGRY_ELECTRONICAN
 */ 

#include <avr/io.h>
//#include "spi.h"
#include "NRF.h"


int main(void)
{
	uint8_t transmitAddress[5]={0xFF,0xFF,0xFF,0xFF,0xFF};
	uint8_t returnedAddress[5]={0,0,0,0,0};
	//uint8_t data=0;
	DDRA=0xFF;
	NRF_Init();
	readRegNRF(CONFIG,returnedAddress,1);
	PORTA=returnedAddress[0];
	
    while (1) 
    {
		
    }
}

