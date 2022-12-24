/*
 * timer.c
 *
 *  Created on: Oct 29, 2022
 *      Author: pc
 */


#include <software_timer.h>
#include "main.h"
//#include "input_reading.h"
//#include "button.h"
//#include "scheduler.h"

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	if(htim->Instance == TIM2 ){
//		button_reading();
		timerRun();
//		getKeyInput();
//		SCH_Update();
	}
}
