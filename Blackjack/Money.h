//Money.h
#ifndef MONEY_H
#define MONEY_H

#include <iostream>

extern double balance; //Global variable, allows for different games to access the same currency

class Money
{

protected:
	double bets;
public:
	Money();         //default constructor
	Money(double, double);
	void setBet(double b) { bets = b; }    
	double getBet()const { return bets; }
	void win();
	void lose();

	virtual void betVal();
	virtual void noBalance();

};

#endif
