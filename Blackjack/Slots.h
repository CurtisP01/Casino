
#ifndef SLOTS_H
#define SLOTS_H

#include "Money.h"
#include <stdio.h>
#include <string>


class Slots: public Money  //inheritance from money class
{
public:
	void slots();
	void play();

private:
	std::string First[15] = { "|", "|", "|", "|", "|", "@", "@", "@", "@", "Z", "Z", "Z", "+", "+", "$" };
	std::string Second[15] = { "|", "|", "|", "|", "|", "@", "@", "@", "@", "Z", "Z", "Z", "+", "+", "$" }; //All symbols in slots initialized
	std::string Third[15] = { "|", "|", "|", "|", "|", "@", "@", "@", "@", "Z", "Z", "Z", "+", "+", "$" };

	bool start;
	int r1 = 0, r2 = 0, r3 = 0;;   //declare all variables
	int Payout;

	void Winnings(std::string one[], std::string two[], std::string three[]);
};



#endif /* Slots_hpp */

