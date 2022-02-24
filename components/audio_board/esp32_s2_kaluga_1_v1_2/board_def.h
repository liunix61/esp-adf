/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2020 <ESPRESSIF SYSTEMS (SHANGHAI) CO., LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _AUDIO_BOARD_DEFINITION_H_
#define _AUDIO_BOARD_DEFINITION_H_

#include "driver/touch_pad.h"

/**
 * @brief LED Function Definition
 */
#define FUNC_SYS_LEN_EN             (1)
#define WS2812_LED_GPIO             45


/**
 * @brief LCD SCREEN Function Definition
 */
#define FUNC_LCD_SCREEN_EN          (1)
#define LCD_CTRL_GPIO               GPIO_NUM_6
#define LCD_RST_GPIO                GPIO_NUM_16
#define LCD_CS_GPIO                 GPIO_NUM_11
// LCD SPI Pins
#define LCD_DC_GPIO                 GPIO_NUM_13
#define LCD_CLK_GPIO                GPIO_NUM_15
#define LCD_MOSI_GPIO               GPIO_NUM_9
// The LCD pixel number in horizontal and vertical
#define LCD_H_RES                   320
#define LCD_V_RES                   240
#define LCD_SWAP_XY                 (true)
#define LCD_MIRROR_X                (true)
#define LCD_MIRROR_Y                (true)
#define LCD_COLOR_INV               (false)


/**
 * @brief Audio Codec Chip Function Definition
 */
#define FUNC_AUDIO_CODEC_EN         (1)
#define PA_ENABLE_GPIO              10
#define ES8311_MCLK_SOURCE          1   /* 0 From MCLK, 1 From BCLK */
#define CODEC_ADC_I2S_PORT         (0)
#define CODEC_ADC_BITS_PER_SAMPLE  I2S_BITS_PER_SAMPLE_16BIT
#define CODEC_ADC_SAMPLE_RATE      (48000)
#define RECORD_HARDWARE_AEC        (false)

extern audio_hal_func_t AUDIO_CODEC_ES8311_DEFAULT_HANDLE;
#define AUDIO_CODEC_DEFAULT_CONFIG(){                   \
        .adc_input  = AUDIO_HAL_ADC_INPUT_LINE1,        \
        .dac_output = AUDIO_HAL_DAC_OUTPUT_ALL,         \
        .codec_mode = AUDIO_HAL_CODEC_MODE_BOTH,        \
        .i2s_iface = {                                  \
            .mode = AUDIO_HAL_MODE_SLAVE,               \
            .fmt = AUDIO_HAL_I2S_NORMAL,                \
            .samples = AUDIO_HAL_48K_SAMPLES,           \
            .bits = AUDIO_HAL_BIT_LENGTH_16BITS,        \
        },                                              \
};


/**
 * @brief Button Function Definition
 */
#define FUNC_BUTTON_EN              (1)
#define BUTTON_ADC                  6
#define INPUT_KEY_NUM               6
#define BUTTON_VOLUP_ID             0
#define BUTTON_VOLDOWN_ID           1
#define BUTTON_SET_ID               2
#define BUTTON_PLAY_ID              3
#define BUTTON_MODE_ID              4
#define BUTTON_REC_ID               5
#define INPUT_KEY_DEFAULT_INFO() {                      \
     {                                                  \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_REC,               \
        .act_id = BUTTON_REC_ID,                        \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_MODE,              \
        .act_id = BUTTON_MODE_ID,                       \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_SET,               \
        .act_id = BUTTON_SET_ID,                        \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_PLAY,              \
        .act_id = BUTTON_PLAY_ID,                       \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_VOLUP,             \
        .act_id = BUTTON_VOLUP_ID,                      \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_VOLDOWN,           \
        .act_id = BUTTON_VOLDOWN_ID,                    \
    }                                                   \
}

#endif
