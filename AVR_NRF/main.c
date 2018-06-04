/*
 * AVR_NRF.c
 *
 * Created: 15.09.2017 23:09:52
 * Author : ANGRY_ELECTRONICAN
 */ 

#include <avr/io.h>
//#include "spi.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define F_CPU 8000000UL
#include "NRF.h"
#include "gpio.h"
uint8_t buf=0;
ISR(INT0_vect){

	while(NRF_DataAvailable()){
		NRF_ReadPLD(&buf,1);
		NRF_StatusClear();
		PORTA=buf;
	}
	PORTD^=(1<<PD5);
}

int main(void)
{
	
	//uint8_t data=0;
	uint8_t pipe0[]={33,33,33,33,33};
	uint8_t pipe1[]={66,33,33,33,33};
	uint8_t TX1[]={66,33,33,33,33};
	uint8_t TX0[]={33,33,33,33,33};
	DDRA=0xFF;
	DDRD=0xFF;
	
	DDRD&=~(1<<PD2);
	DDRB|=1<<PB0;
	PORTB&=~(1<<PB0);
	PORTB|=(1<<PB0);
	
	PORTD|=1<<PD2;
	//cleBit(MCUCSR,ISC2);
	//MCUCSR&=~(1<<ISC2);
	//setBit(GICR,INT2);
	GICR|=1<<INT0;
	//MCUCR|=(1<<SE);//|(1<<SM1);
	_delay_ms(1);
	sei();
	
	
	NRF_Init();
	
	NRF_PowerOff();
	
	NRF_FlashRx();
	NRF_FlashTx();	
	NRF_SetPipeAddress(0,pipe0,5);
	NRF_SetTransmitAddress(TX0,5);
	NRF_OpenPipe(0,1);
	NRF_PowerOn();
	NRF_ReceiveMode();
	
	NRF_ReadReg(STATUS,&buf,1);
	NRF_WriteReg(STATUS,&buf,1);
	//NRF_TransmitMode();
	
    while (1) 
    {
		
		//
		//NRF_TransmitMode();
		//NRF_WritePLD(&buf,1);
		//NRF_WriteData();
		//NRF_ReadReg(STATUS,&buf,1);
		//NRF_ReceiveMode();
		PORTA=0xFF;
		sleep_enable();
		set_sleep_mode(SLEEP_MODE_PWR_DOWN);
		sleep_cpu();
		sleep_disable();
		//MCUCR|=(1<<SE);
		//asm("SLEEP");
		//MCUCR&=~(1<<SE);
		PORTA=0x00;
		//NRF_FlashRx();
		
		
		_delay_ms(100);	
    }
}

