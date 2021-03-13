//Money.cpp
#include "Money.h"

double balance = 1000; //Initialize global variable

Money::Money() {   
	bets = 0.0;
}

Money::Money(double bal, double b) {
	balance = bal;
	bets = b;
}
void Money::betVal() {
	double b;
	do {
		std::cout << "You have $" << balance << std::endl;  //Verifies if you have enough money for bet inputted
		std::cout << "Please place a bet: ";
		std::cin >> b;
		if (b > balance)
			std::cout << "Not enough funds to place bet.\n\n"; //will loop if not enough funds
		if (b <= 0)
			std::cout << "That is not a valid bet.\n\n";  //will not accept values less than or equal to 0

	} while (b > balance || b <= 0);

	setBet(b);          //sets bets equal to b
}
void Money::win() {
	balance = balance + bets;    //balance is increased by bet when won
}
void Money::lose() {
	balance = balance - bets;   //balance decreased by bet when lose
}
void Money::noBalance() {
	if (balance <= 0) {
		std::cout << "\nYou no longer have enough funds to play.\n"; //Force close program when balance reaches <=0
		std::cout << "*You have been kicked out of the casino*\n";
		std::exit(0);
	}
}

