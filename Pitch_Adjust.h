/*
 * Pitch_Adjust.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Logan
 */

#ifndef REPO_PITCH_ADJUST_H_
#define REPO_PITCH_ADJUST_H_

#include "KnobFSM.h" //get enums
#include "../Repo/Sean_queue.h"

/* Notes { // Freqiency
	A=220,
	B=246.94,
	C=261.63, //Middle C
	D=293.66,
	E=329.63,
	F=349.23,
	G=392,
};*/

class Pitch_Adjust{
private:
	Sean_queue *q_val;
	static uint8_t octave; //max value

public:
	void set_octave(Sean_queue *q_cmd); //use queue and get the message to change the pitch number
	uint8_t get_octave(); //get the pitch number and change it to frequency

};


#endif /* REPO_PITCH_ADJUST_H_ */
