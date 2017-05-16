/**
 * @file lsm6ds3h.c
 * @brief driver for the lsm6 IMU
 * @author Kristoffer Ödmark
 * @version 1.0
 * @date 2017-02-27
 */

#include "lsm6dsl.h"
#include "lsm6dsl_reg.h"
#include "lsm6dsl_hal.h"

#include "debug_print.h"

void lsm_write(uint8_t addr, uint8_t *data, uint8_t len)
{

     uint8_t header = 0x7F & addr;
     lsm_spi_select();
     lsm_spi_write(&header, 1);
     lsm_spi_write(data, len);
     lsm_spi_unselect();
}
void lsm_write_8bit(uint8_t addr, uint8_t data)
{
    lsm_write(addr, &data, 1);
}

void lsm_read(uint8_t addr, uint8_t *data, uint8_t len)
{
     uint8_t header = 0x80 | addr;
     lsm_spi_select();

     lsm_spi_write(&header, 1);
     lsm_spi_read(data, len);

     lsm_spi_unselect();
}

uint8_t lsm_read_8bit(uint8_t addr)
{
    uint8_t data;
    lsm_read(addr, &data, 1);
    return data;
}
uint16_t lsm_read_16bit(uint8_t addr)
{
    uint16_t data;
    lsm_read(addr, (uint8_t*)&data, 2);
    return data;
}
void lsm_get_data( lsm_imu_data_t *data ){
    static int taps = 0;
    if(lsm_read_8bit(LSM_REG_TAP_SRC) )
    {
        taps++;
        printf("TAP: %i\n", taps);
    }
    lsm_read(LSM_REG_OUT_TEMP_L, (uint8_t *)data, 2*7);
}

#include "debug_print.h"
void lsm_init()
{
    lsm_spi_init();

    lsm_write_8bit(LSM_REG_MD1_CFG, INT1_SINGLE_TAP);

    lsm_write_8bit(LSM_REG_DRDY_PULSE_CFG_G, DRDY_PULSED);

    // interrupt when new data available
    lsm_write_8bit(LSM_REG_INT1_CTRL,INT1_DRDY_G | INT1_DRDY_XL);

    // start data aquisition at specified scales and 104hz
    lsm_write_8bit(LSM_REG_CTRL1_XL, ODR_XL2 | FS_16g);
    lsm_write_8bit(LSM_REG_CTRL2_G, ODR_G2 | FS_2000dps);

    lsm_write_8bit(LSM_REG_TAP_CFG, INTERRUPTS_ENABLE | TAP_X_EN | TAP_Y_EN | TAP_Z_EN);
    lsm_write_8bit(LSM_REG_TAP_THS_6D, TAP_THS1 | TAP_THS0);
    //lsm_write_8bit(LSM_REG_INT_DUR2, QUIET0);
}
