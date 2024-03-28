/*
* Filename: main.c
* Content: main source code program
*/
#include "main.h"

int main(){
	/* Init RCC */
	RCC_ClockHSE();
	RCC_CongfigAHBPrescaler(AHB_1);
	RCC_EnableAndCongfigAPB2(APB2_1, APB2_PORTC);    /* Clock 8Mhz, enable Port C */
	
	/* Init GPIO */
	GPIO_Output_Init(GPIO_C,LED_PC13); 
	GPIO_Output_Init(GPIO_C,LED_PC12); 
	
	/* Create two task toggle led */
	xTaskCreate(toggle_led_1,"Toggle led PC13 in 1 second", STACKDEPTH_UNIT, NULL, PRIORITY_REALTIME, NULL);
	xTaskCreate(toggle_led_2,"Toggle led PC12 in 2 second", STACKDEPTH_UNIT, NULL, PRIORITY_REALTIME, NULL);
	
	/* Start operation of Task */
	vTaskStartScheduler();
}

/* Toggle led 1 in 1 second */
static void toggle_led_1(void* p_ptrVoid){
	while(TRUE)
	{
		GPIO_SetTogglePIN(GPIO_C,LED_PC13);
		vTaskDelay(DELAY_1SECOND);
	}
}

/* Toggle led 2 in 2 seconds */
static void toggle_led_2(void* p_ptrVoid){
		while(TRUE)
	{
		GPIO_SetTogglePIN(GPIO_C,LED_PC12);
		vTaskDelay(DELAY_2SECOND);
	}
}

