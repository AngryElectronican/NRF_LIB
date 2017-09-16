/*
 * AVR_NRF.c
 *
 * Created: 15.09.2017 23:09:52
 * Author : ANGRY_ELECTRONICAN
 */ 

#include <avr/io.h>
#include "spi.h"

#define setBit(PORT,PIN) PORT|=(1<<PIN)
#define cleBit(PORT,PIN) PORT&=~(1<<PIN)

#define CN	PB3
#define CSN	PB4

int main(void)
{
	uint8_t data=0;
	DDRA=0xFF;
	SPI_Init(CN,CSN);
	cleBit(PORTB,CSN);
	data=SPI_ReadWriteByte(0x00);
	data=SPI_ReadWriteByte(0xFF);
	setBit(PORTB,CSN);
	PORTA=data;
	
    while (1) 
    {
		
    }
}

