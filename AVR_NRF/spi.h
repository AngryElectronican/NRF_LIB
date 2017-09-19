/*
 * spi.h
 *
 * Created: 15.09.2017 23:14:09
 *  Author: ANGRY_ELECTRONICAN
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define CE	PB3
#define CSN PB4

#define setBit(PORT,PIN) PORT|=(1<<PIN)
#define cleBit(PORT,PIN) PORT&=~(1<<PIN)

void SPI_Init(uint8_t CE_pin, uint8_t CSN_pin);
uint8_t SPI_ReadByte(void);
uint8_t SPI_ReadWriteByte(uint8_t data);

#endif /* SPI_H_ */