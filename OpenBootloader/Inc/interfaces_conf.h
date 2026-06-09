/**
  ******************************************************************************
  * @file    interfaces_conf.h
  * @author  MCD Application Team
  * @brief   Contains Interfaces configuration
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INTERFACES_CONF_H
#define INTERFACES_CONF_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_ll_i2c.h"

#define MEMORIES_SUPPORTED                7U

/*-------------------------- Definitions for I2C -----------------------------*/
#define I2Cx                              I2C2
#define I2Cx_CLK_ENABLE()                 __HAL_RCC_I2C2_CLK_ENABLE()
#define I2Cx_CLK_DISABLE()                __HAL_RCC_I2C2_CLK_DISABLE()
#define I2Cx_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOH_CLK_ENABLE()
#define I2Cx_DEINIT()                     LL_I2C_DeInit(I2Cx)

#define I2Cx_SCL_PIN                      GPIO_PIN_4
#define I2Cx_SCL_PIN_PORT                 GPIOH
#define I2Cx_SDA_PIN                      GPIO_PIN_5
#define I2Cx_SDA_PIN_PORT                 GPIOH
#define I2Cx_ALTERNATE                    GPIO_AF4_I2C2
#define I2C_ADDRESS                       0x000000B4U
#define OPENBL_I2C_TIMEOUT                0xFFFFF000U
#define I2C_TIMING                        0x00800000U

/*-------------------------- Definitions for FDCAN ---------------------------*/
#define FDCANx                            FDCAN1
#define FDCANx_CLK_ENABLE()               __HAL_RCC_FDCAN1_CLK_ENABLE()
#define FDCANx_CLK_DISABLE()              __HAL_RCC_FDCAN1_CLK_DISABLE()
#define FDCANx_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOB_CLK_ENABLE()

#define FDCANx_TX_PIN                     GPIO_PIN_8
#define FDCANx_TX_GPIO_PORT               GPIOB
#define FDCANx_TX_AF                      GPIO_AF9_FDCAN1
#define FDCANx_RX_PIN                     GPIO_PIN_9
#define FDCANx_RX_GPIO_PORT               GPIOB
#define FDCANx_RX_AF                      GPIO_AF9_FDCAN1

#define FDCANx_FORCE_RESET()              __HAL_RCC_FDCAN1_FORCE_RESET()
#define FDCANx_RELEASE_RESET()            __HAL_RCC_FDCAN1_RELEASE_RESET()

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* INTERFACES_CONF_H */
