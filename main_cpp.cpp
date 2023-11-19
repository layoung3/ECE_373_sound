/*
 * main_cpp.cpp
 *
 *  Created on: Oct 30, 2023
 *      Author: Logan
 */

#include "main.h"
#include "../Repo/KnobFSM.h"
#include "../Repo/Sample_clock.h"
#include "../Repo/Sean_queue.h"
#include "../Repo/Pitch_Adjust.h"
#include "../Repo/Play_Note.h"

//DAC_HandleTypeDef hdac1;

Sean_queue q_ms;
Sean_queue q_get_data_asap;
Sean_queue q_user_command;
Pitch_Adjust pitch;

extern DAC_HandleTypeDef hdac1;

uint32_t number;

/*void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim17){
	bool cross_fingers = q_ms.enqueue(1);
	assert(cross_fingers);   // ERROR TRAP - queue overflow!
}*/

void main_cpp(){

	//HAL_DAC_Start(&hdac1, DAC_CHANNEL_2); //Initialize DAC
	Sample_clock tick_filter(&q_ms, &q_get_data_asap, 1);
	Knob_FSM knob1(&q_user_command, &q_get_data_asap, GPIOC, Quad_A_PC2_Pin, GPIOC, Quad_B_PC3_Pin);

	while(1){
		pitch.set_octave(&q_user_command);

		for(number = 0; number<123456; number++){
				  HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,number);
			  }
			  for(number=0; number>0; number--){
				  HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,number);
			  }
	}
}
