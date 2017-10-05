/*
 * registersNRF.h
 *
 * Created: 19.09.2017 22:46:05
 *  Author: ANGRY_ELECTRONICAN
 */ 


#ifndef REGNRF_H_
#define REGNRF_H_
//Commands

enum{
    CONFIG  = 0x00,
    EN_AA,
    EN_RXADDR,
    SETUP_AW,
    SETUP_RETR,
    RF_CH,
    RF_SETUP,
    STATUS,
    OBSERVE_TX,
    CD,
    RX_ADDR_P0,
    RX_ADDR_P1,
    RX_ADDR_P2,
    RX_ADDR_P3,
    RX_ADDR_P4,
    RX_ADDR_P5,
    TX_ADDR,
    RX_PW_P0,
    RX_PW_P1,
    RX_PW_P2,
    RX_PW_P3,
    RX_PW_P4,
    RX_PW_P5,
    FIFO_STATUS_REG
	};

	#define R_REGISTER			0x00
	#define W_REGISTER			0x20
	#define R_RX_PAYLOAD		0x61
	#define W_TX_PAYLOAD		0xA0
	#define FLUSH_TX				0xE1
	#define FLUSH_RX				0xE2
	#define REUSE_TX_PL			0xE3
	#define NOP							0xFF
//CONFIG

#define PRIM_RX 0
#define PWR_UP 1


#endif /* REGNRF_H_ */