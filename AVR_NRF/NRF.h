/*
 * NRF.h
 *
 * Created: 17.09.2017 22:27:53
 *  Author: ANGRY_ELECTRONICAN
 */ 


#ifndef NRF_H_
#define NRF_H_

#include <avr/io.h>
#include "regNRF.h"
#include <util/delay.h>

void NRF_ReadReg(uint8_t addr,uint8_t *buffer,uint8_t size);
void NRF_WriteReg(uint8_t addr,uint8_t *value,uint8_t num);
void NRF_WritePLD(uint8_t *buf,uint8_t size);
void NRF_Init(void);
void NRF_PowerOff(void);
void NRF_PowerOn(void);
void NRF_ReceiveMode(void);
void NRF_TransmitMode(void);
void NRF_WriteData();
void NRF_OpenPipe(uint8_t pipe,uint8_t width);


#endif /* NRF_H_ */