/**
 * @file lsm6ds3h.h
 * @brief
 * @author Kristoffer Ödmark
 * @version 1.0
 * @date 2017-02-27
 */
#ifndef LSM6DS3H_H
#define LSM6DS3H_H

#include "stdint.h"

typedef enum {
    FULL_SCALE_2G,
    FULL_SCALE_4G,
    FULL_SCALE_8G,
    FULL_SCALE_16G
} LSM_G_SCALE;

typedef struct __attribute__(( packed )){
    int16_t temp;
    int16_t rx;
    int16_t ry;
    int16_t rz;
    int16_t gx;
    int16_t gy;
    int16_t gz;
} lsm_imu_data_t;


void lsm_init(void);

void lsm_write(uint8_t addr, uint8_t *data, uint8_t len);

void lsm_read(uint8_t addr, uint8_t *data, uint8_t len);

void lsm_get_data(lsm_imu_data_t *data);

#endif /* LSM6DS3H_H */
