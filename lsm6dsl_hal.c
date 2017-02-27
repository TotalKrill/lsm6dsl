/**
 * @file lsm6ds3h_hal.c
 * @brief abstraction, this will define the actual spi transactions etc
 * @author Kristoffer Ödmark
 * @version 1.0
 * @date 2017-02-27
 */


#include "lsm6dsl_hal.h"

#include "hal.h"

#define LSM_SPI_BUS SPID3

static const SPIConfig lsm_spicfg = {
    NULL, GPIOD, GPIOD_IMU_CS, SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0};

void lsm_spi_init(void){
    palSetPad(GPIOD, GPIOD_IMU_CS);
    spiStart(&LSM_SPI_BUS, &lsm_spicfg);
}

void lsm_spi_select(void)
{
    spiAcquireBus(&LSM_SPI_BUS);  /* Acquire ownership of the bus.*/
    spiSelect(&LSM_SPI_BUS);      /* Slave Select assertion. */

}


void lsm_spi_unselect(void)
{
    spiUnselect(&LSM_SPI_BUS);       /* Slave Select de-assertion.*/
    spiReleaseBus(&LSM_SPI_BUS);     /* Ownership release.*/

}

void lsm_spi_write(uint8_t *data, uint8_t len)
{
     spiSend(&LSM_SPI_BUS, len, data);
}
void lsm_spi_read(uint8_t *data, uint8_t len)
{
    spiReceive(&LSM_SPI_BUS, len, data);
}


