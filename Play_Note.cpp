/*
 * Play_Note.cpp
 *
 *  Created on: Oct 31, 2023
 *      Author: Logan
 */

#include "Play_Note.h"

extern DAC_HandleTypeDef hdac1;

void Play_Note::update(){
	new_octave = pitch.get_octave();
	if(new_octave == current_octave){
		changed = false;
	}
	else{
		current_octave = new_octave;
		changed = true;
	}

	if (changed == true){ //if octave changed, calculate the note_frequency
		for(int i=0;i<3;i++){
			  play_frequency[i]= (base_frequency[i]*pow(2,current_octave));
		}

		a_complex = exp(6.283185307*play_frequency[0]*.001);
		b_complex = exp(6.283185307*play_frequency[1]*.001);
		c_complex = exp(6.283185307*play_frequency[2]*.001);

		//start bool for first instance of note
		start = true;
	}


	if (HAL_GPIO_ReadPin(GPIOD,Keypad_a_Pin)==0){
		if (start == true){
			a_base = a_complex.real();
			a = a_base;
			HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,a);
			start = false;
		}
		else{
			a = a*a_base;
			HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,a);
		}
	}
	else if(HAL_GPIO_ReadPin(GPIOD,Keypad_b_Pin)==0){
		if (start == true){
			b_base = b_complex.real();
			b=b_base;
			HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,b);
			start = false;
		}
		else{
			b = b*b_base;
			HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,b);
		}

	}
	else if(HAL_GPIO_ReadPin(GPIOD,Keypad_c_Pin)==0){
		if (start == true){
			c_base = c_complex.real();
			c=c_base;
			HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,c);
			start = false;
		}
		else{
			c = c*c_base;
			HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_2,DAC_ALIGN_12B_L,c);
		}
	}
	else
	{}
}

