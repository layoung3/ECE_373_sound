/*
 * Pitch_Adjust.cpp
 *
 *  Created on: Oct 24, 2023
 *      Author: Logan
 */

#include "Pitch_Adjust.h"


bool Pitch_Adjust::set_pitch_number(Sean_queue *q_cmd){
	this->q_val = q_cmd;
	int16_t msg;
	bool has_message = q_val->dequeue(&msg);
	if(has_message){ //if true
		if(msg==Increase){ //8 notes. One octave
			if(this->pitch_number<7){
				pitch_number++;
				return true;
			}
		}
		else if(msg==Decrease){
			if(this->pitch_number>0){
				pitch_number--;
				return true;
			}
		}
		else
			return false;
	}

}
uint16_t Pitch_Adjust::pitch_to_freq(){
	uint16_t frequency =0;
	switch(pitch_number){ //set frequency with 0 being lowest
	case 0:
		frequency = 10;
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	}
	return frequency;
}


