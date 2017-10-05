/*
 * NRF.c
 *
 * Created: 17.09.2017 22:29:59
 *  Author: ANGRY_ELECTRONICAN
 */ 
#include "NRF.h"
#include "spi.h"


void NRF_ReadReg(uint8_t addr,uint8_t *buffer,uint8_t size){
	cleBit(PORTB,CSN);
	SPI_ReadWriteByte(addr);
	for(int i=0;i<size;i++){
	buffer[i]=SPI_ReadWriteByte(0xFF);
	}
	setBit(PORTB,CSN);
}
void NRF_WriteReg(uint8_t addr,uint8_t *value,uint8_t num){
	cleBit(PORTB,CSN);
	SPI_ReadWriteByte(addr|0x20);
	for(int i=0;i<num;i++){
		SPI_ReadWriteByte(value[i]);
	}
	setBit(PORTB,CSN);
}

void NRF_Init(void){
	uint8_t clear=0x08;
	SPI_Init(CE,CSN);
	cleBit(PORTB,CE);
	NRF_WriteReg(CONFIG,&clear,1);
}
void NRF_PowerOff(void){
	uint8_t value=0;
	NRF_ReadReg(CONFIG,&value,1);
	value&=~(1<<PWR_UP);
	NRF_WriteReg(CONFIG,&value,1);
	_delay_ms(2);
}
void NRF_PowerOn(void){
	uint8_t value=0;
	NRF_ReadReg(CONFIG,&value,1);
	value|=(1<<PWR_UP);
	NRF_WriteReg(CONFIG,&value,1);
	_delay_ms(2);
}
void NRF_ReceiveMode(void){
	uint8_t value=0;
	NRF_ReadReg(CONFIG,&value,1);
	value|=(1<<PRIM_RX);
	NRF_WriteReg(CONFIG,&value,1);
	setBit(PORTB,CE);
	_delay_us(135);
}
void NRF_TransmitMode(){
	uint8_t value=0;
	NRF_ReadReg(CONFIG,&value,1);
	value&=~(1<<PRIM_RX);
	NRF_WriteReg(CONFIG,&value,1);
	cleBit(PORTB,CE);
	_delay_us(135);
}
void NRF_WritePLD(uint8_t *buf,uint8_t size){
	cleBit(PORTB,CSN);
	SPI_ReadWriteByte(W_TX_PAYLOAD);
	for(int i=0; i<size;i++){
		SPI_ReadWriteByte(buf[i]);
	}
	setBit(PORTB,CSN);
}
void NRF_WriteData(){
	uint8_t status=0;
	setBit(PORTB,CE);
	_delay_us(15);
	NRF_ReadReg(STATUS,&status,1);
	while(!(status&(1<<5)))
	{
		NRF_ReadReg(STATUS,&status,1);
	}
	NRF_WriteReg(STATUS,&status,1);
	cleBit(PORTB,CE);
}
void NRF_OpenPipe(uint8_t pipe,uint8_t width){
	uint8_t size=width;
	NRF_WriteReg(RX_PW_P0+pipe,&size,1);
}