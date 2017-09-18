/*
 * NRF.c
 *
 * Created: 17.09.2017 22:29:59
 *  Author: ANGRY_ELECTRONICAN
 */ 
#include "NRF.h"
#include "spi.h"

void readRegNRF(uint8_t addr,uint8_t *buffer,uint8_t size){
	cleBit(PORTB,PB4);
	SPI_ReadWriteByte(addr);
	for(int i=0;i<size;i++){
	buffer[i]=SPI_ReadWriteByte(0xFF);
	}
	setBit(PORTB,PB4);
}
uint8_t writeRegNRF(uint8_t addr,uint8_t *value,uint8_t num){
	uint8_t receive=0;
	cleBit(PORTB,PB4);
	receive=SPI_ReadWriteByte(addr|0x20);
	for(int i=0;i<num;i++){
		SPI_ReadWriteByte(value[i]);
	}
	setBit(PORTB,PB4);
	return receive;	
}