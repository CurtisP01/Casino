#ifndef HORSERACE_H
#define H0RSERACE_H

#include "Money.h"
#include <stdio.h>
#include <string>
#include <iostream>


class HorseRace: public Money { //inherits from Money class
public:

	void play();
	void shuffleString(std::string option[], int n);
	int Winner();

private:
	std::string Horses[10] = { "Fleetfire", "Pericles", "Frosty", "Skyflash", "Boomerang", "Biscuit", "Hershey", "Arnold", "Gunner", "Gary" };
	std::string Riders[10] = { "Laurie Yates", "Drake Osborne", "Roosevelt Cote", "Violet Robles", "Reo Childs", "Ralph Mackie", "Ffion Mcguire", "Farzana Magana", "Hudson Witt", "Maria Oconnor" };
	int WinPercent[10];           //Initialize string arrays with names
	int Payout;
	int Pay[5];

	int Choice[5] = { 1, 2, 3, 4, 5 }; //initialize in array with choices
	int input;
	int winner;
	int winnings;

};

#endif