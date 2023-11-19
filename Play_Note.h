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
#include <complex>

class Play_Note{
private:
	double base_frequency[7]={220,246.94,261.63,293.66,329.63,349.23}; //A - G: C is Middle C
	double play_frequency[7]={220,246.94,261.63,293.66,329.63,349.23}; //this will changed based off octave
	uint8_t current_octave = 0;
	uint8_t new_octave;
	bool changed, start;
	Pitch_Adjust pitch;
	double a_base,b_base,c_base, a,b,c;
	_Complex double c_complex,b_complex,a_complex;

public:
	void update();
};



#endif /* REPO_PLAY_NOTE_H_ */
