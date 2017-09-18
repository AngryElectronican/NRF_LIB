/*
 * NRF.h
 *
 * Created: 17.09.2017 22:27:53
 *  Author: ANGRY_ELECTRONICAN
 */ 


#ifndef NRF_H_
#define NRF_H_
#include <avr/io.h>
#define WRITE_COMMAND 0x20
void readRegNRF(uint8_t addr,uint8_t *buffer,uint8_t size);
uint8_t writeRegNRF(uint8_t addr,uint8_t *value,uint8_t num);

#endif /* NRF_H_ */