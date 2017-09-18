/*
 * AVR_NRF.c
 *
 * Created: 15.09.2017 23:09:52
 * Author : ANGRY_ELECTRONICAN
 */ 

#include <avr/io.h>
#include "spi.h"

#define CN	PB3
#define CSN PB4

#include "NRF.h"



int main(void)
{
	uint8_t transmitAddress[5]={0xFF,0xFF,0xFF,0xFF,0xFF};
	uint8_t returnedAddress[5]={0,0,0,0,0};
	//uint8_t data=0;
	DDRA=0xFF;
	SPI_Init(CN,CSN);
	writeRegNRF(0x10,transmitAddress,5);
	readRegNRF(0x10,returnedAddress,5);
	PORTA=returnedAddress[0];
	
    while (1) 
    {
		
    }
}

