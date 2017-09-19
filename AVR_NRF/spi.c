/*
 * spi.c
 *
 * Created: 15.09.2017 23:13:55
 *  Author: ANGRY_ELECTRONICAN
 */ 

#include "spi.h"

void SPI_Init(uint8_t CE_pin, uint8_t CSN_pin){
	DDRB=(1<<CE_pin)|(1<<CSN_pin)|(1<<PB5)|(1<<PB7);
	PORTB|=(1<<CSN_pin);
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