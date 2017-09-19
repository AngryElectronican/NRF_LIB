/*
 * NRF.c
 *
 * Created: 17.09.2017 22:29:59
 *  Author: ANGRY_ELECTRONICAN
 */ 
#include "NRF.h"
#include "spi.h"


void readRegNRF(uint8_t addr,uint8_t *buffer,uint8_t size){
	cleBit(PORTB,CSN);
	SPI_ReadWriteByte(addr);
	for(int i=0;i<size;i++){
	buffer[i]=SPI_ReadWriteByte(0xFF);
	}
	setBit(PORTB,CSN);
}
uint8_t writeRegNRF(uint8_t addr,uint8_t *value,uint8_t num){
	uint8_t receive=0;
	cleBit(PORTB,CSN);
	receive=SPI_ReadWriteByte(addr|0x20);
	for(int i=0;i<num;i++){
		SPI_ReadWriteByte(value[i]);
	}
	setBit(PORTB,CSN);
	return receive;	
}
void NRF_Init(void){
	uint8_t startup[]={0x0A};
	SPI_Init(CE,CSN);
	cleBit(PORTB,CE);
	writeRegNRF(CONFIG,startup,1);
}