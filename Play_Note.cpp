/*
 * Play_Note.cpp
 *
 *  Created on: Oct 31, 2023
 *      Author: Logan
 */

#include "Play_Note.h"

void Play_Note::update(){
	uint8_t new_octave = pitch.get_octave();
	if(new_octave == current_octave){
		changed = false;
	}
	else{
		current_octave = new_octave;
		changed = true;
	}

	if (changed == true){ //if octave changed, calculate the note_frequency
		//octave = pitch.get_octave();
		for(int i=0;i<7;i++){
			  play_frequency[i]= (base_frequency[i]*pow(2,current_octave));
		}
	}

	//Keypad_out_Pin set to 0 so check input for 0
	if (HAL_GPIO_ReadPin(GPIOD,Keypad_a_Pin)==0){ //prioritize a note since there is no chord
		HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,play_frequency[0]);
	}
	else if(HAL_GPIO_ReadPin(GPIOD,Keypad_b_Pin)==0){
		HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,play_frequency[1]);
	}
	else if(HAL_GPIO_ReadPin(GPIOD,Keypad_c_Pin)==0){
		HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,play_frequency[2]);
	}
	else
		break;
}

