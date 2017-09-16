/*
 * spi.c
 *
 * Created: 15.09.2017 23:13:55
 *  Author: ANGRY_ELECTRONICAN
 */ 
#include <avr/io.h>
#include "spi.h"

void SPI_Init(uint8_t CE, uint8_t CSN){
	DDRB=(1<<CE)|(1<<CSN)|(1<<PB5)|(1<<PB7);
	PORTB|=(1<<CSN);
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0);
	
}
uint8_t SPI_ReadByte(void){
	while(!(SPSR&(1<<SPIF))){}
		return SPDR;
}
uint8_t SPI_ReadWriteByte(uint8_t data){
	//uint8_t empty=0;
	SPDR=data;
	while(!(SPSR&(1<<SPIF))){}
	return SPDR;	
}