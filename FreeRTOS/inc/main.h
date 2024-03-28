/*
* Filename: main.h
* Content: main source include file
*/
#ifndef _MAIN_H_
#define _MAIN_H_

/* Include the main device */
#include "RCC.h"    /* RCC device */
#include "GPIO.h"    /* GPIO device */

/* Include the library */
#include "FreeRTOS.h"
#include "task.h"

/* Define super loop */
#define TRUE 1
#define FALSE 0

/* Define time delay */
#define DELAY_1SECOND 1000
#define DELAY_2SECOND 2000

/* Define the pin of LED */
#define LED_PC13 13
#define LED_PC12 12

/* Stack Depth of task */
#define STACKDEPTH_UNIT 200

/* Priority of Task */
#define PRIORITY_REALTIME 0

/* Toggle Led 1 in 1 second */
static void toggle_led_1(void* p_ptrVoid);

/* Toggle Led 2 in 2 second */
static void toggle_led_2(void* p_ptrVoid);

#endif /* _MAIN_H_ */
