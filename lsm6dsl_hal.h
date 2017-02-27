/**
 * @file lsm6ds3h_hal.h
 * @brief Spi translation untit for transfers to different systems
 * @author Kristoffer Ödmark
 * @version
 * @date 2017-02-27
 */
#ifndef LSM6DS3H_HAL_H
#define LSM6DS3H_HAL_H

#include "stdint.h"

void lsm_spi_init(void);
void lsm_spi_select(void);
void lsm_spi_unselect(void);
void lsm_spi_write(uint8_t *data, uint8_t len);
void lsm_spi_read(uint8_t *data, uint8_t len);


#endif /* LSM6DS3H_HAL_H */
