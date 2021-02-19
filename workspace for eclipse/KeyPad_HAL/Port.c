/*
 * Port.c
 *
 *  Created on: Jan 17, 2021
 *      Author: hossam
 */
#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
//#include "../Lib/ATmega32_Registers.h"
#include <avr/io.h>
#undef F_CPU
#define F_CPU 8000000

#include "../PORT_Peripheral/Port_int.h"
#include "../PORT_Peripheral/Port_priv.h"
#include "../PORT_Peripheral/Port_cfg.h"
void Port_vidInit(void)
{
#if	 PORT_u8PIN_0_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_0_DEFAULT_VALUE
#undef PORT_u8PIN_0_DEFAULT_DIR
#define PORT_u8PIN_0_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_0_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_0_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_0_DEFAULT_VALUE
#undef PORT_u8PIN_0_DEFAULT_DIR
#define PORT_u8PIN_0_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_0_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_0_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_0_DEFAULT_VALUE
#undef PORT_u8PIN_0_DEFAULT_DIR
#define PORT_u8PIN_0_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_0_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_0_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_0_DEFAULT_VALUE
#undef PORT_u8PIN_0_DEFAULT_DIR
#define PORT_u8PIN_0_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_0_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 0 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_1_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_1_DEFAULT_VALUE
#undef PORT_u8PIN_1_DEFAULT_DIR
#define PORT_u8PIN_1_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_1_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_1_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_1_DEFAULT_VALUE
#undef PORT_u8PIN_1_DEFAULT_DIR
#define PORT_u8PIN_1_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_1_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_1_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_1_DEFAULT_VALUE
#undef PORT_u8PIN_1_DEFAULT_DIR
#define PORT_u8PIN_1_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_1_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_1_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_1_DEFAULT_VALUE
#undef PORT_u8PIN_1_DEFAULT_DIR
#define PORT_u8PIN_1_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_1_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 1 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_2_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_2_DEFAULT_VALUE
#undef PORT_u8PIN_2_DEFAULT_DIR
#define PORT_u8PIN_2_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_2_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_2_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_2_DEFAULT_VALUE
#undef PORT_u8PIN_2_DEFAULT_DIR
#define PORT_u8PIN_2_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_2_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_2_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_2_DEFAULT_VALUE
#undef PORT_u8PIN_2_DEFAULT_DIR
#define PORT_u8PIN_2_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_2_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_2_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_2_DEFAULT_VALUE
#undef PORT_u8PIN_2_DEFAULT_DIR
#define PORT_u8PIN_2_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_2_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 2 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_3_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_3_DEFAULT_VALUE
#undef PORT_u8PIN_3_DEFAULT_DIR
#define PORT_u8PIN_3_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_3_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_3_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_3_DEFAULT_VALUE
#undef PORT_u8PIN_3_DEFAULT_DIR
#define PORT_u8PIN_3_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_3_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_3_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_3_DEFAULT_VALUE
#undef PORT_u8PIN_3_DEFAULT_DIR
#define PORT_u8PIN_3_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_3_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_3_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_3_DEFAULT_VALUE
#undef PORT_u8PIN_3_DEFAULT_DIR
#define PORT_u8PIN_3_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_3_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 3 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_4_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_4_DEFAULT_VALUE
#undef PORT_u8PIN_4_DEFAULT_DIR
#define PORT_u8PIN_4_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_4_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_4_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_4_DEFAULT_VALUE
#undef PORT_u8PIN_4_DEFAULT_DIR
#define PORT_u8PIN_4_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_4_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_4_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_4_DEFAULT_VALUE
#undef PORT_u8PIN_4_DEFAULT_DIR
#define PORT_u8PIN_4_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_4_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_4_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_4_DEFAULT_VALUE
#undef PORT_u8PIN_4_DEFAULT_DIR
#define PORT_u8PIN_4_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_4_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 4 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_5_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_5_DEFAULT_VALUE
#undef PORT_u8PIN_5_DEFAULT_DIR
#define PORT_u8PIN_5_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_5_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_5_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_5_DEFAULT_VALUE
#undef PORT_u8PIN_5_DEFAULT_DIR
#define PORT_u8PIN_5_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_5_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_5_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_5_DEFAULT_VALUE
#undef PORT_u8PIN_5_DEFAULT_DIR
#define PORT_u8PIN_5_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_5_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_5_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_5_DEFAULT_VALUE
#undef PORT_u8PIN_5_DEFAULT_DIR
#define PORT_u8PIN_5_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_5_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 5 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_6_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_6_DEFAULT_VALUE
#undef PORT_u8PIN_6_DEFAULT_DIR
#define PORT_u8PIN_6_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_6_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_6_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_6_DEFAULT_VALUE
#undef PORT_u8PIN_6_DEFAULT_DIR
#define PORT_u8PIN_6_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_6_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_6_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_6_DEFAULT_VALUE
#undef PORT_u8PIN_6_DEFAULT_DIR
#define PORT_u8PIN_6_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_6_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_6_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_6_DEFAULT_VALUE
#undef PORT_u8PIN_6_DEFAULT_DIR
#define PORT_u8PIN_6_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_6_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 6 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_7_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_7_DEFAULT_VALUE
#undef PORT_u8PIN_7_DEFAULT_DIR
#define PORT_u8PIN_7_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_7_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_7_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_7_DEFAULT_VALUE
#undef PORT_u8PIN_7_DEFAULT_DIR
#define PORT_u8PIN_7_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_7_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_7_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_7_DEFAULT_VALUE
#undef PORT_u8PIN_7_DEFAULT_DIR
#define PORT_u8PIN_7_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_7_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_7_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_7_DEFAULT_VALUE
#undef PORT_u8PIN_7_DEFAULT_DIR
#define PORT_u8PIN_7_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_7_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 7 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_8_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_8_DEFAULT_VALUE
#undef PORT_u8PIN_8_DEFAULT_DIR
#define PORT_u8PIN_8_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_8_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_8_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_8_DEFAULT_VALUE
#undef PORT_u8PIN_8_DEFAULT_DIR
#define PORT_u8PIN_8_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_8_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_8_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_8_DEFAULT_VALUE
#undef PORT_u8PIN_8_DEFAULT_DIR
#define PORT_u8PIN_8_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_8_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_8_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_8_DEFAULT_VALUE
#undef PORT_u8PIN_8_DEFAULT_DIR
#define PORT_u8PIN_8_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_8_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 8 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_9_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_9_DEFAULT_VALUE
#undef PORT_u8PIN_9_DEFAULT_DIR
#define PORT_u8PIN_9_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_9_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_9_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_9_DEFAULT_VALUE
#undef PORT_u8PIN_9_DEFAULT_DIR
#define PORT_u8PIN_9_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_9_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_9_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_9_DEFAULT_VALUE
#undef PORT_u8PIN_9_DEFAULT_DIR
#define PORT_u8PIN_9_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_9_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_9_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_9_DEFAULT_VALUE
#undef PORT_u8PIN_9_DEFAULT_DIR
#define PORT_u8PIN_9_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_9_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 9 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_10_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_10_DEFAULT_VALUE
#undef PORT_u8PIN_10_DEFAULT_DIR
#define PORT_u8PIN_10_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_10_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_10_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_10_DEFAULT_VALUE
#undef PORT_u8PIN_10_DEFAULT_DIR
#define PORT_u8PIN_10_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_10_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_10_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_10_DEFAULT_VALUE
#undef PORT_u8PIN_10_DEFAULT_DIR
#define PORT_u8PIN_10_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_10_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_10_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_10_DEFAULT_VALUE
#undef PORT_u8PIN_10_DEFAULT_DIR
#define PORT_u8PIN_10_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_10_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 10 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_11_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_11_DEFAULT_VALUE
#undef PORT_u8PIN_11_DEFAULT_DIR
#define PORT_u8PIN_11_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_11_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_11_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_11_DEFAULT_VALUE
#undef PORT_u8PIN_11_DEFAULT_DIR
#define PORT_u8PIN_11_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_11_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_11_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_11_DEFAULT_VALUE
#undef PORT_u8PIN_11_DEFAULT_DIR
#define PORT_u8PIN_11_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_11_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_11_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_11_DEFAULT_VALUE
#undef PORT_u8PIN_11_DEFAULT_DIR
#define PORT_u8PIN_11_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_11_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 11 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_12_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_12_DEFAULT_VALUE
#undef PORT_u8PIN_12_DEFAULT_DIR
#define PORT_u8PIN_12_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_12_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_12_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_12_DEFAULT_VALUE
#undef PORT_u8PIN_12_DEFAULT_DIR
#define PORT_u8PIN_12_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_12_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_12_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_12_DEFAULT_VALUE
#undef PORT_u8PIN_12_DEFAULT_DIR
#define PORT_u8PIN_12_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_12_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_12_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_12_DEFAULT_VALUE
#undef PORT_u8PIN_12_DEFAULT_DIR
#define PORT_u8PIN_12_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_12_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 12 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_13_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_13_DEFAULT_VALUE
#undef PORT_u8PIN_13_DEFAULT_DIR
#define PORT_u8PIN_13_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_13_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_13_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_13_DEFAULT_VALUE
#undef PORT_u8PIN_13_DEFAULT_DIR
#define PORT_u8PIN_13_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_13_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_13_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_13_DEFAULT_VALUE
#undef PORT_u8PIN_13_DEFAULT_DIR
#define PORT_u8PIN_13_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_13_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_13_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_13_DEFAULT_VALUE
#undef PORT_u8PIN_13_DEFAULT_DIR
#define PORT_u8PIN_13_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_13_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 13 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_14_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_14_DEFAULT_VALUE
#undef PORT_u8PIN_14_DEFAULT_DIR
#define PORT_u8PIN_14_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_14_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_14_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_14_DEFAULT_VALUE
#undef PORT_u8PIN_14_DEFAULT_DIR
#define PORT_u8PIN_14_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_14_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_14_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_14_DEFAULT_VALUE
#undef PORT_u8PIN_14_DEFAULT_DIR
#define PORT_u8PIN_14_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_14_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_14_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_14_DEFAULT_VALUE
#undef PORT_u8PIN_14_DEFAULT_DIR
#define PORT_u8PIN_14_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_14_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 14 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_15_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_15_DEFAULT_VALUE
#undef PORT_u8PIN_15_DEFAULT_DIR
#define PORT_u8PIN_15_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_15_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_15_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_15_DEFAULT_VALUE
#undef PORT_u8PIN_15_DEFAULT_DIR
#define PORT_u8PIN_15_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_15_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_15_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_15_DEFAULT_VALUE
#undef PORT_u8PIN_15_DEFAULT_DIR
#define PORT_u8PIN_15_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_15_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_15_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_15_DEFAULT_VALUE
#undef PORT_u8PIN_15_DEFAULT_DIR
#define PORT_u8PIN_15_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_15_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 15 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_16_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_16_DEFAULT_VALUE
#undef PORT_u8PIN_16_DEFAULT_DIR
#define PORT_u8PIN_16_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_16_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_16_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_16_DEFAULT_VALUE
#undef PORT_u8PIN_16_DEFAULT_DIR
#define PORT_u8PIN_16_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_16_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_16_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_16_DEFAULT_VALUE
#undef PORT_u8PIN_16_DEFAULT_DIR
#define PORT_u8PIN_16_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_16_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_16_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_16_DEFAULT_VALUE
#undef PORT_u8PIN_16_DEFAULT_DIR
#define PORT_u8PIN_16_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_16_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 16 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_17_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_17_DEFAULT_VALUE
#undef PORT_u8PIN_17_DEFAULT_DIR
#define PORT_u8PIN_17_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_17_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_17_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_17_DEFAULT_VALUE
#undef PORT_u8PIN_17_DEFAULT_DIR
#define PORT_u8PIN_17_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_17_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_17_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_17_DEFAULT_VALUE
#undef PORT_u8PIN_17_DEFAULT_DIR
#define PORT_u8PIN_17_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_17_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_17_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_17_DEFAULT_VALUE
#undef PORT_u8PIN_17_DEFAULT_DIR
#define PORT_u8PIN_17_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_17_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 17 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_18_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_18_DEFAULT_VALUE
#undef PORT_u8PIN_18_DEFAULT_DIR
#define PORT_u8PIN_18_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_18_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_18_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_18_DEFAULT_VALUE
#undef PORT_u8PIN_18_DEFAULT_DIR
#define PORT_u8PIN_18_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_18_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_18_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_18_DEFAULT_VALUE
#undef PORT_u8PIN_18_DEFAULT_DIR
#define PORT_u8PIN_18_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_18_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_18_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_18_DEFAULT_VALUE
#undef PORT_u8PIN_18_DEFAULT_DIR
#define PORT_u8PIN_18_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_18_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 18 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_19_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_19_DEFAULT_VALUE
#undef PORT_u8PIN_19_DEFAULT_DIR
#define PORT_u8PIN_19_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_19_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_19_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_19_DEFAULT_VALUE
#undef PORT_u8PIN_19_DEFAULT_DIR
#define PORT_u8PIN_19_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_19_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_19_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_19_DEFAULT_VALUE
#undef PORT_u8PIN_19_DEFAULT_DIR
#define PORT_u8PIN_19_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_19_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_19_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_19_DEFAULT_VALUE
#undef PORT_u8PIN_19_DEFAULT_DIR
#define PORT_u8PIN_19_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_19_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 19 , the default mode has been set (OUTPUT_LOW)"
#endif

#if	 PORT_u8PIN_20_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_20_DEFAULT_VALUE
#undef PORT_u8PIN_20_DEFAULT_DIR
#define PORT_u8PIN_20_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_20_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_20_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_20_DEFAULT_VALUE
#undef PORT_u8PIN_20_DEFAULT_DIR
#define PORT_u8PIN_20_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_20_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_20_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_20_DEFAULT_VALUE
#undef PORT_u8PIN_20_DEFAULT_DIR
#define PORT_u8PIN_20_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_20_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_20_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_20_DEFAULT_VALUE
#undef PORT_u8PIN_20_DEFAULT_DIR
#define PORT_u8PIN_20_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_20_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 20 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_21_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_21_DEFAULT_VALUE
#undef PORT_u8PIN_21_DEFAULT_DIR
#define PORT_u8PIN_21_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_21_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_21_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_21_DEFAULT_VALUE
#undef PORT_u8PIN_21_DEFAULT_DIR
#define PORT_u8PIN_21_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_21_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_21_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_21_DEFAULT_VALUE
#undef PORT_u8PIN_21_DEFAULT_DIR
#define PORT_u8PIN_21_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_21_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_21_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_21_DEFAULT_VALUE
#undef PORT_u8PIN_21_DEFAULT_DIR
#define PORT_u8PIN_21_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_21_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 21 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_22_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_22_DEFAULT_VALUE
#undef PORT_u8PIN_22_DEFAULT_DIR
#define PORT_u8PIN_22_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_22_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_22_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_22_DEFAULT_VALUE
#undef PORT_u8PIN_22_DEFAULT_DIR
#define PORT_u8PIN_22_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_22_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_22_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_22_DEFAULT_VALUE
#undef PORT_u8PIN_22_DEFAULT_DIR
#define PORT_u8PIN_22_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_22_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_22_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_22_DEFAULT_VALUE
#undef PORT_u8PIN_22_DEFAULT_DIR
#define PORT_u8PIN_22_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_22_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 22 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_23_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_23_DEFAULT_VALUE
#undef PORT_u8PIN_23_DEFAULT_DIR
#define PORT_u8PIN_23_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_23_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_23_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_23_DEFAULT_VALUE
#undef PORT_u8PIN_23_DEFAULT_DIR
#define PORT_u8PIN_23_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_23_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_23_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_23_DEFAULT_VALUE
#undef PORT_u8PIN_23_DEFAULT_DIR
#define PORT_u8PIN_23_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_23_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_23_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_23_DEFAULT_VALUE
#undef PORT_u8PIN_23_DEFAULT_DIR
#define PORT_u8PIN_23_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_23_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 23 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_24_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_24_DEFAULT_VALUE
#undef PORT_u8PIN_24_DEFAULT_DIR
#define PORT_u8PIN_24_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_24_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_24_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_24_DEFAULT_VALUE
#undef PORT_u8PIN_24_DEFAULT_DIR
#define PORT_u8PIN_24_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_24_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_24_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_24_DEFAULT_VALUE
#undef PORT_u8PIN_24_DEFAULT_DIR
#define PORT_u8PIN_24_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_24_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_24_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_24_DEFAULT_VALUE
#undef PORT_u8PIN_24_DEFAULT_DIR
#define PORT_u8PIN_24_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_24_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 24 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_25_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_25_DEFAULT_VALUE
#undef PORT_u8PIN_25_DEFAULT_DIR
#define PORT_u8PIN_25_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_25_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_25_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_25_DEFAULT_VALUE
#undef PORT_u8PIN_25_DEFAULT_DIR
#define PORT_u8PIN_25_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_25_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_25_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_25_DEFAULT_VALUE
#undef PORT_u8PIN_25_DEFAULT_DIR
#define PORT_u8PIN_25_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_25_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_25_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_25_DEFAULT_VALUE
#undef PORT_u8PIN_25_DEFAULT_DIR
#define PORT_u8PIN_25_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_25_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 25 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_26_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_26_DEFAULT_VALUE
#undef PORT_u8PIN_26_DEFAULT_DIR
#define PORT_u8PIN_26_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_26_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_26_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_26_DEFAULT_VALUE
#undef PORT_u8PIN_26_DEFAULT_DIR
#define PORT_u8PIN_26_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_26_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_26_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_26_DEFAULT_VALUE
#undef PORT_u8PIN_26_DEFAULT_DIR
#define PORT_u8PIN_26_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_26_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_26_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_26_DEFAULT_VALUE
#undef PORT_u8PIN_26_DEFAULT_DIR
#define PORT_u8PIN_26_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_26_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 26 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_27_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_27_DEFAULT_VALUE
#undef PORT_u8PIN_27_DEFAULT_DIR
#define PORT_u8PIN_27_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_27_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_27_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_27_DEFAULT_VALUE
#undef PORT_u8PIN_27_DEFAULT_DIR
#define PORT_u8PIN_27_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_27_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_27_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_27_DEFAULT_VALUE
#undef PORT_u8PIN_27_DEFAULT_DIR
#define PORT_u8PIN_27_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_27_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_27_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_27_DEFAULT_VALUE
#undef PORT_u8PIN_27_DEFAULT_DIR
#define PORT_u8PIN_27_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_27_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 27 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_28_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_28_DEFAULT_VALUE
#undef PORT_u8PIN_28_DEFAULT_DIR
#define PORT_u8PIN_28_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_28_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_28_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_28_DEFAULT_VALUE
#undef PORT_u8PIN_28_DEFAULT_DIR
#define PORT_u8PIN_28_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_28_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_28_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_28_DEFAULT_VALUE
#undef PORT_u8PIN_28_DEFAULT_DIR
#define PORT_u8PIN_28_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_28_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_28_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_28_DEFAULT_VALUE
#undef PORT_u8PIN_28_DEFAULT_DIR
#define PORT_u8PIN_28_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_28_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 28 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_29_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_29_DEFAULT_VALUE
#undef PORT_u8PIN_29_DEFAULT_DIR
#define PORT_u8PIN_29_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_29_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_29_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_29_DEFAULT_VALUE
#undef PORT_u8PIN_29_DEFAULT_DIR
#define PORT_u8PIN_29_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_29_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_29_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_29_DEFAULT_VALUE
#undef PORT_u8PIN_29_DEFAULT_DIR
#define PORT_u8PIN_29_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_29_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_29_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_29_DEFAULT_VALUE
#undef PORT_u8PIN_29_DEFAULT_DIR
#define PORT_u8PIN_29_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_29_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 29 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_30_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_30_DEFAULT_VALUE
#undef PORT_u8PIN_30_DEFAULT_DIR
#define PORT_u8PIN_30_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_30_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_30_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_30_DEFAULT_VALUE
#undef PORT_u8PIN_30_DEFAULT_DIR
#define PORT_u8PIN_30_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_30_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_30_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_30_DEFAULT_VALUE
#undef PORT_u8PIN_30_DEFAULT_DIR
#define PORT_u8PIN_30_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_30_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_30_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_30_DEFAULT_VALUE
#undef PORT_u8PIN_30_DEFAULT_DIR
#define PORT_u8PIN_30_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_30_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 30 , the default mode has been set (OUTPUT_LOW)"
#endif


#if	 PORT_u8PIN_31_INIT_MODE == PORT_u8OUTPUT_LOW
#undef PORT_u8PIN_31_DEFAULT_VALUE
#undef PORT_u8PIN_31_DEFAULT_DIR
#define PORT_u8PIN_31_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_31_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_31_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef PORT_u8PIN_31_DEFAULT_VALUE
#undef PORT_u8PIN_31_DEFAULT_DIR
#define PORT_u8PIN_31_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_31_DEFAULT_DIR		PORT_u8OUTPUT

#elif PORT_u8PIN_31_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_31_DEFAULT_VALUE
#undef PORT_u8PIN_31_DEFAULT_DIR
#define PORT_u8PIN_31_DEFAULT_VALUE		PORT_u8LOW
#define PORT_u8PIN_31_DEFAULT_DIR		PORT_u8INPUT

#elif PORT_u8PIN_31_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef PORT_u8PIN_31_DEFAULT_VALUE
#undef PORT_u8PIN_31_DEFAULT_DIR
#define PORT_u8PIN_31_DEFAULT_VALUE		PORT_u8HIGH
#define PORT_u8PIN_31_DEFAULT_DIR		PORT_u8INPUT

#else
#warning "you have entered wrong initial mode for pin 31 , the default mode has been set (OUTPUT_LOW)"
#endif

DDRA=CONC(PORT_u8PIN_7_DEFAULT_DIR,PORT_u8PIN_6_DEFAULT_DIR,PORT_u8PIN_5_DEFAULT_DIR,PORT_u8PIN_4_DEFAULT_DIR,PORT_u8PIN_3_DEFAULT_DIR,PORT_u8PIN_2_DEFAULT_DIR,PORT_u8PIN_1_DEFAULT_DIR,PORT_u8PIN_0_DEFAULT_DIR);
PORTA=CONC(PORT_u8PIN_7_DEFAULT_VALUE,PORT_u8PIN_6_DEFAULT_VALUE,PORT_u8PIN_5_DEFAULT_VALUE,PORT_u8PIN_4_DEFAULT_VALUE,PORT_u8PIN_3_DEFAULT_VALUE,PORT_u8PIN_2_DEFAULT_VALUE,PORT_u8PIN_1_DEFAULT_VALUE,PORT_u8PIN_0_DEFAULT_VALUE);

DDRB=CONC(PORT_u8PIN_15_DEFAULT_DIR,PORT_u8PIN_14_DEFAULT_DIR,PORT_u8PIN_13_DEFAULT_DIR,PORT_u8PIN_12_DEFAULT_DIR,PORT_u8PIN_11_DEFAULT_DIR,PORT_u8PIN_10_DEFAULT_DIR,PORT_u8PIN_9_DEFAULT_DIR,PORT_u8PIN_8_DEFAULT_DIR);
PORTB=CONC(PORT_u8PIN_15_DEFAULT_VALUE,PORT_u8PIN_14_DEFAULT_VALUE,PORT_u8PIN_13_DEFAULT_VALUE,PORT_u8PIN_12_DEFAULT_VALUE,PORT_u8PIN_11_DEFAULT_VALUE,PORT_u8PIN_10_DEFAULT_VALUE,PORT_u8PIN_9_DEFAULT_VALUE,PORT_u8PIN_8_DEFAULT_VALUE);

DDRC=CONC(PORT_u8PIN_23_DEFAULT_DIR,PORT_u8PIN_22_DEFAULT_DIR,PORT_u8PIN_21_DEFAULT_DIR,PORT_u8PIN_20_DEFAULT_DIR,PORT_u8PIN_19_DEFAULT_DIR,PORT_u8PIN_18_DEFAULT_DIR,PORT_u8PIN_17_DEFAULT_DIR,PORT_u8PIN_16_DEFAULT_DIR);
PORTC=CONC(PORT_u8PIN_23_DEFAULT_VALUE,PORT_u8PIN_22_DEFAULT_VALUE,PORT_u8PIN_21_DEFAULT_VALUE,PORT_u8PIN_20_DEFAULT_VALUE,PORT_u8PIN_19_DEFAULT_VALUE,PORT_u8PIN_18_DEFAULT_VALUE,PORT_u8PIN_17_DEFAULT_VALUE,PORT_u8PIN_16_DEFAULT_VALUE);

DDRD=CONC(PORT_u8PIN_31_DEFAULT_DIR,PORT_u8PIN_30_DEFAULT_DIR,PORT_u8PIN_29_DEFAULT_DIR,PORT_u8PIN_28_DEFAULT_DIR,PORT_u8PIN_27_DEFAULT_DIR,PORT_u8PIN_26_DEFAULT_DIR,PORT_u8PIN_25_DEFAULT_DIR,PORT_u8PIN_24_DEFAULT_DIR);
PORTD=CONC(PORT_u8PIN_31_DEFAULT_VALUE,PORT_u8PIN_30_DEFAULT_VALUE,PORT_u8PIN_29_DEFAULT_VALUE,PORT_u8PIN_28_DEFAULT_VALUE,PORT_u8PIN_27_DEFAULT_VALUE,PORT_u8PIN_26_DEFAULT_VALUE,PORT_u8PIN_25_DEFAULT_VALUE,PORT_u8PIN_24_DEFAULT_VALUE);
}

void Port_vidSetPinDir(Port_tenuPinId Copy_enuPinId, Port_tenuPinDir Copy_enuPinDir){

	u8 Loc_u8PortId;
	u8 Loc_u8PinId;

	Loc_u8PortId = Copy_enuPinId /8;
	Loc_u8PinId  = Copy_enuPinId %8;

	switch(Loc_u8PortId){
	case 0:	//PORTA
		if(Copy_enuPinDir==Port_enuOutput)
		{
			SET_BIT(DDRA,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(DDRA,Loc_u8PinId);
		}
	break;
	case 1:	//PORTB
		if(Copy_enuPinDir==Port_enuOutput)
		{
			SET_BIT(DDRB,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(DDRB,Loc_u8PinId);
		}
	break;
	case 2:	// PORTC
		if(Copy_enuPinDir==Port_enuOutput)
		{
			SET_BIT(DDRC,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(DDRC,Loc_u8PinId);
		}
	break;
	case 3:	// PORTD
		if(Copy_enuPinDir==Port_enuOutput)
		{
			SET_BIT(DDRD,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(DDRD,Loc_u8PinId);
		}
	break;
	default:
	break;
	}
}

void Port_vidSetPinMode(Port_tenuPinId Copy_enuPinId, Port_tenuPinMode Copy_enuPinMode){
	u8 Loc_u8PortId;
		u8 Loc_u8PinId;

		Loc_u8PortId = Copy_enuPinId /8;
		Loc_u8PinId  = Copy_enuPinId %8;

		switch(Loc_u8PortId){
		case 0:	//PORTA
			if(Copy_enuPinMode==Port_enuOutputHigh)
			{
				SET_BIT(DDRA,Loc_u8PinId);	// output
				SET_BIT(PORTA,Loc_u8PinId);	// high
			}
			else if (Copy_enuPinMode==Port_enuInputHighImpedance)
			{
				CLR_BIT(DDRA,Loc_u8PinId); 	// input
				CLR_BIT(PORTA,Loc_u8PinId);	// low (high impedance)
			}
			else if (Copy_enuPinMode==Port_enuInputPullUp)
			{
				CLR_BIT(DDRA,Loc_u8PinId);	// input
				SET_BIT(PORTA,Loc_u8PinId);	// high (PULL UP)
			}
			else{
				//it will be Port_enuOutputLOW
				SET_BIT(DDRA,Loc_u8PinId);	// output
				CLR_BIT(PORTA,Loc_u8PinId);	// low
			}
			break;
		break;
		case 1:	//PORTB
			if(Copy_enuPinMode==Port_enuOutputHigh)
				{
					SET_BIT(DDRB,Loc_u8PinId);	// output
					SET_BIT(PORTB,Loc_u8PinId);	// high
				}
			else if (Copy_enuPinMode==Port_enuInputHighImpedance)
				{
					CLR_BIT(DDRB,Loc_u8PinId); 	// input
					CLR_BIT(PORTB,Loc_u8PinId);	// low (high impedance)
				}
			else if (Copy_enuPinMode==Port_enuInputPullUp)
				{
					CLR_BIT(DDRB,Loc_u8PinId);	// input
					SET_BIT(PORTB,Loc_u8PinId);	// high (PULL UP)
				}
			else{
					//it will be Port_enuOutputLOW
					SET_BIT(DDRB,Loc_u8PinId);	// output
					CLR_BIT(PORTB,Loc_u8PinId);	// low
				}
		break;
		case 2:	// PORTC
			if(Copy_enuPinMode==Port_enuOutputHigh)
				{
					SET_BIT(DDRC,Loc_u8PinId);	// output
					SET_BIT(PORTC,Loc_u8PinId);	// high
				}
			else if (Copy_enuPinMode==Port_enuInputHighImpedance)
				{
					CLR_BIT(DDRC,Loc_u8PinId); 	// input
					CLR_BIT(PORTC,Loc_u8PinId);	// low (high impedance)
				}
			else if (Copy_enuPinMode==Port_enuInputPullUp)
				{
					CLR_BIT(DDRC,Loc_u8PinId);	// input
					SET_BIT(PORTC,Loc_u8PinId);	// high (PULL UP)
				}
			else{
					//it will be Port_enuOutputLOW
					SET_BIT(DDRC,Loc_u8PinId);	// output
					CLR_BIT(PORTC,Loc_u8PinId);	// low
				}
			break;
		case 3:	// PORTD
			if(Copy_enuPinMode==Port_enuOutputHigh)
				{
					SET_BIT(DDRD,Loc_u8PinId);	// output
					SET_BIT(PORTD,Loc_u8PinId);	// high
				}
			else if (Copy_enuPinMode==Port_enuInputHighImpedance)
				{
					CLR_BIT(DDRD,Loc_u8PinId); 	// input
					CLR_BIT(PORTD,Loc_u8PinId);	// low (high impedance)
				}
			else if (Copy_enuPinMode==Port_enuInputPullUp)
				{
					CLR_BIT(DDRD,Loc_u8PinId);	// input
					SET_BIT(PORTD,Loc_u8PinId);	// high (PULL UP)
				}
			else{
					//it will be Port_enuOutputLOW
					SET_BIT(DDRD,Loc_u8PinId);	// output
					CLR_BIT(PORTD,Loc_u8PinId);	// low
				}
			break;
		default:
		break;
		}

}





