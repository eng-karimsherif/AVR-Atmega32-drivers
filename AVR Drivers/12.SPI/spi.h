/*
 * spi.h
 *
 * Created: 09/08/2020 14:12:22
 *  Author: karim sherif
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "std_macros.h"

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void master_init_spi();
void slave_init_spi();
void spi_send_char(uint8_t);
uint8_t spi_recieve_char();
uint8_t spi_tx_rx(uint8_t);


#endif /* SPI_H_ */