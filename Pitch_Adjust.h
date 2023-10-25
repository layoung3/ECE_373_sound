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

class Pitch_Adjust{
private:
	Sean_queue *q_val;
	static uint8_t pitch_number; //max value
	bool set_pitch_number(Sean_queue *q_cmd); //use queue and get the message to change the pitch number

public:
	uint16_t pitch_to_freq(); //get the pitch number and change it to frequency

};


#endif /* REPO_PITCH_ADJUST_H_ */
