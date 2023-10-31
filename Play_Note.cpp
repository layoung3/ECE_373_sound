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
}

