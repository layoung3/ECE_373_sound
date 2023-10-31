/*
 * Play_Note.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Logan
 */

#ifndef REPO_PLAY_NOTE_H_
#define REPO_PLAY_NOTE_H_

#include "Pitch_Adjust.h"
#include <cmath>

class Play_Note{
private:
	float base_frequency[7]={220,246.94,261.63,293.66,329.63,349.23}; //A - G: C is Middle C
	float play_frequency[7]={220,246.94,261.63,293.66,329.63,349.23}; //this will changed based off octave
	uint8_t current_octave = 0;
	uint8_t new_octave;
	bool changed;
	Pitch_Adjust pitch;
public:
	void update();
};



#endif /* REPO_PLAY_NOTE_H_ */
