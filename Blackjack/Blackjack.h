//Blackjack.h
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Money.h"
#include <string>
#include <ctime>

class Blackjack: public Money  //Blackjack class inherits from Money class
{
private:
	int numCard;
	int numCards;
	int playerSum;
	int dealerSum;      //Declare all variables

	int temp[52];
	int playHand[7];
	int dealHand[7];
	int num, nums, nums1, dr;
	std::string cards[52];

public:
	Blackjack();
	Blackjack(int, int, int, double, double);

	void setCards(); //assigns random values a card
	void shuffle(); //resets all variables

	int draw();     //draws card, prevents from drawing the same card more than 4 times
	int convert(int dr);  //converts random number into a card
	int playerAddSum(int dr);
	int dealSum(int dr);
	void hit();             //
	void playerStartCard();
	void dealerStart();
	void dealerDraw();
	void choice();
	void print();


	//Increment operators
	void operator ++(); 
	void operator--();

	~Blackjack() {};
};

#endif