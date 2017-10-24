/*
 * AVR_NRF.c
 *
 * Created: 15.09.2017 23:09:52
 * Author : ANGRY_ELECTRONICAN
 */ 

#include <avr/io.h>
//#include "spi.h"
#define F_CPU 8000000UL
#include "NRF.h"

int main(void)
{
	uint8_t transmit[1]={0xAA};
	uint8_t data=0;
	DDRA=0xFF;
	NRF_Init();
	NRF_OpenPipe(0,1);
	NRF_PowerOn();
	NRF_ReceiveMode();
	/*NRF_TransmitMode();
	NRF_WritePLD(transmit,1);
	NRF_WriteData();
	NRF_ReadReg(STATUS,&data,1);
	PORTA=data;*/
    while (1) 
    {
		/*NRF_TransmitMode();
		NRF_WritePLD(transmit,1);
		NRF_WriteData();*/
		
		/*NRF_ResetRetransmitCounter();*/
		if(NRF_DataAvailable()){
			NRF_ReadPLD(&data,1);
		}
		PORTA=data;
		
    }
}

