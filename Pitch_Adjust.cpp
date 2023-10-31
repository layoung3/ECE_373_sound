/*
 * Pitch_Adjust.cpp
 *
 *  Created on: Oct 24, 2023
 *      Author: Logan
 */

#include "Pitch_Adjust.h"


void Pitch_Adjust::set_octave(Sean_queue *q_cmd){ //return a boolean to isChanged to know if we need to adjust base frequency
	this->q_val = q_cmd;
	int16_t msg;
	bool has_message = q_val->dequeue(&msg);
	if(has_message){ //if true
		if(msg==Increase){ //8 notes. One octave
			if(this->octave<7){
				octave++;
			}
		}
		if(msg==Decrease){
			if(this->octave>0){
				octave--;
			}
		}
	}
}
uint8_t Pitch_Adjust::get_octave(){
	return octave;
}


