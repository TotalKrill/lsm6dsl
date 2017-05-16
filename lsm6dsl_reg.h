/**
 * @file lsm6dsl_reg.h
 * @brief registers and functions
 * @author Kristoffer Ödmark
 * @version 1.0
 * @date 2017-02-27
 */
#ifndef LSM6DSL_REG_H
#define LSM6DSL_REG_H

/* FLAGS */
// interrupt on int 1
#define INT1_INACT_STATE 0x80
#define INT1_SINGLE_TAP 0x40
#define INT1_WAKE_UP 0x20
#define INT1_FREE_FALL 0x10
#define INT1_DOUBLE_TAP 0x08
#define INT1_6D 0x04
#define INT1_TILT 0x02
#define INT1_TIMER 0x01

// Flags for INT1_CTRL
#define INT1_STEP_DETECTOR 0x80
#define INT1_SIGN_MOT 0x40
#define INT1_FULL_FLAG 0x20
#define INT1_FIFO_OVR 0x10
#define INT1_FTH 0x08
#define INT1_BOOT 0x04
#define INT1_DRDY_G 0x02
#define INT1_DRDY_XL 0x01

// TAP configs
#define INTERRUPTS_ENABLE 0x80
#define INACT_EN0 0x40
#define INACT_EN1 0x20
#define SLOPE_FDS 0x10
#define TAP_X_EN 0x08
#define TAP_Y_EN 0x04
#define TAP_Z_EN 0x02
#define LIR 0x01

// CTRL1_XL settings
#define ODR_XL3 0x80
#define ODR_XL2 0x40
#define ODR_XL1 0x20
#define ODR_XL0 0x10
#define FS_XL1 0x08
#define FS_XL0 0x04
#define FS_2g (0x00)
#define FS_4g (FS_XL1)
#define FS_8g (FS_XL1 | FS_XL0)
#define FS_16g (FS_XL0)
#define LPF1_BW_SEL 0x02
// CTRL2_G settings
#define ODR_G3 0x80
#define ODR_G2 0x40
#define ODR_G1 0x20
#define ODR_G0 0x10
#define FS_G1 0x08
#define FS_G0 0x04
#define FS_245dps (0x00)
#define FS_500dps (FS_G0)
#define FS_1000dps (FS_G1)
#define FS_2000dps (FS_G1 | FS_G0)
#define FS_125dps 0x02

// DRDY_PULSE_CFG_G settings
#define DRDY_PULSED 0x80
#define INT2_WRIST_TILT 0x01

//  TAP_SRC
#define TAP_IA 0x40
#define SINGLE_TAP 0x20
#define DOUBLE_TAP 0x10
#define TAP_SIGN 0x08
#define X_TAP 0x04
#define Y_TAP 0x02
#define Z_TAP 0x01

// TAP_THS_6D

#define D4D_EN 0x80
#define SIXD_THS_80DEG 0x00
#define SIXD_THS_70DEG 0x20
#define SIXD_THS_60DEG 0x40
#define SIXD_THS_50DEG 0x60
// corresponds to the fullscale g settings
// at max value, the IMU must saturate
#define TAP_THS4 0x10
#define TAP_THS3 0x08
#define TAP_THS2 0x04
// lsb is 8 ODR_XL
#define TAP_THS1 0x02
#define TAP_THS0 0x01

#define TAP_THS_PERCENT(c)  ((uint8_t)((c * 0x1F))& 0x1F )

// INT_DUR2
// lsb is 32 times ODR_XL, the update rate.
#define DUR3 0x80
#define DUR2 0x40
#define DUR1 0x20
#define DUR0 0x10
// lsb is 4 * ODR_XL
#define QUIET1 0x08
#define QUIET0 0x04
// lsb is 8 ODR_XL
#define SHOCK1 0x02
#define SHOCK0 0x01

/* Registers */
#define LSM_REG_INT1_CTRL 0x0D
#define LSM_REG_INT2_CTRL 0x0E
#define LSM_REG_WHOAMI 0x0E
#define LSM_REG_DRDY_PULSE_CFG_G 0x0B
#define LSM_REG_CTRL1_XL 0x10
#define LSM_REG_CTRL2_G 0x11
#define LSM_REG_CTRL3_C 0x12
#define LSM_REG_CTRL4_C 0x13
#define LSM_REG_CTRL5_C 0x14
#define LSM_REG_CTRL6_C 0x15
#define LSM_REG_CTRL7_G 0x16
#define LSM_REG_CTRL8_XL 0x17
#define LSM_REG_CTRL9_XL 0x18
#define LSM_REG_CTRL10_C 0x19
#define LSM_REG_MASTER_CONFIG 0x1a
#define LSM_REG_WAKE_UP_SRC 0x1b
#define LSM_REG_TAP_SRC 0x1c
#define LSM_REG_D6D_SRC 0x1d
#define LSM_REG_STATUS 0x1e

#define LSM_REG_OUT_TEMP_L 0x20
#define LSM_REG_OUT_TEMP_H 0x21
#define LSM_REG_OUTX_L_g 0x22
#define LSM_REG_OUTX_H_g 0x23
#define LSM_REG_OUTY_L_g 0x24
#define LSM_REG_OUTY_H_g 0x25
#define LSM_REG_OUTZ_L_g 0x26
#define LSM_REG_OUTZ_H_g 0x27
#define LSM_REG_OUTX_L_XL 0x28
#define LSM_REG_OUTX_H_XL 0x29
#define LSM_REG_OUTY_L_XL 0x2a
#define LSM_REG_OUTY_H_XL 0x2b
#define LSM_REG_OUTZ_L_XL 0x2c
#define LSM_REG_OUTZ_H_XL 0x2d


#define LSM_REG_MD1_CFG 0x5E
#define LSM_REG_MD2_CFG 0x5F

#define LSM_REG_TAP_CFG 0x58
#define LSM_REG_TAP_THS_6D 0x59
#define LSM_REG_INT_DUR2 0x5A

#endif /* LSM6DSL_REG_H */
