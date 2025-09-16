/*****************************************************************************
* | File      	:   DEV_Config.h
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2020-02-19
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

// #include <Arduino.h>
#include <stdint.h>
#include <stdio.h>

// esp-idf
#include <driver/gpio.h>
#include <freertos/idf_additions.h>

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/**
 * GPIO config
**/

#define EPD_SCK_PIN  CONFIG_WAVESHARE_EPAPER_GPIO_SCK
#define EPD_MOSI_PIN CONFIG_WAVESHARE_EPAPER_GPIO_MOSI
#define EPD_CS_PIN   CONFIG_WAVESHARE_EPAPER_GPIO_CS
#define EPD_RST_PIN  CONFIG_WAVESHARE_EPAPER_GPIO_RST
#define EPD_DC_PIN   CONFIG_WAVESHARE_EPAPER_GPIO_DC
#define EPD_BUSY_PIN CONFIG_WAVESHARE_EPAPER_GPIO_BUSY

#if (CONFIG_WAVESHARE_EPAPER_GPIO_SCK == CONFIG_WAVESHARE_EPAPER_GPIO_MOSI) || \
    (CONFIG_WAVESHARE_EPAPER_GPIO_SCK == CONFIG_WAVESHARE_EPAPER_GPIO_CS) || \
    (CONFIG_WAVESHARE_EPAPER_GPIO_SCK == CONFIG_WAVESHARE_EPAPER_GPIO_RST) || \
    (CONFIG_WAVESHARE_EPAPER_GPIO_SCK == CONFIG_WAVESHARE_EPAPER_GPIO_DC) || \
    (CONFIG_WAVESHARE_EPAPER_GPIO_SCK == CONFIG_WAVESHARE_EPAPER_GPIO_BUSY) || \
    \
    (CONFIG_WAVESHARE_EPAPER_GPIO_CS == CONFIG_WAVESHARE_EPAPER_GPIO_RST) || \
    (CONFIG_WAVESHARE_EPAPER_GPIO_CS == CONFIG_WAVESHARE_EPAPER_GPIO_DC) || \
    (CONFIG_WAVESHARE_EPAPER_GPIO_CS == CONFIG_WAVESHARE_EPAPER_GPIO_BUSY) || \
    \
    (CONFIG_WAVESHARE_EPAPER_GPIO_RST == CONFIG_WAVESHARE_EPAPER_GPIO_DC) || \
    (CONFIG_WAVESHARE_EPAPER_GPIO_RST == CONFIG_WAVESHARE_EPAPER_GPIO_BUSY) || \
    \
    (CONFIG_WAVESHARE_EPAPER_GPIO_DC == CONFIG_WAVESHARE_EPAPER_GPIO_BUSY) || \
    0

#warning "GPIO misconfigured.  Configure GPIO with `idf.py menuconfig`"
#endif

/*
#define EPD_SCK_PIN  6
#define EPD_MOSI_PIN 7
#define EPD_CS_PIN   10
#define EPD_RST_PIN  4
#define EPD_DC_PIN   9
#define EPD_BUSY_PIN 18
*/


#define GPIO_PIN_SET   1
#define GPIO_PIN_RESET 0


/**
 * GPIO read and write
**/
#define DEV_Digital_Write(_pin, _value)  ESP_ERROR_CHECK(gpio_set_level((gpio_num_t)_pin, _value == 0 ? 0 : 1))
#define DEV_Digital_Read(_pin) gpio_get_level((gpio_num_t)_pin)

/**
 * delay x ms
**/
#define DEV_Delay_ms(__xms) vTaskDelay(pdMS_TO_TICKS(__xms))

/*------------------------------------------------------------------------------------------------------*/
UBYTE DEV_Module_Init(void);
void GPIO_Mode(UWORD GPIO_Pin, UWORD Mode);
void DEV_SPI_WriteByte(UBYTE data);
UBYTE DEV_SPI_ReadByte();
void DEV_SPI_Write_nByte(UBYTE *pData, UDOUBLE len);
void DEV_PowerOn();
void DEV_PowerOff();

#endif
