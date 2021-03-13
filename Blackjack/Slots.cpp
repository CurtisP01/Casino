
#include "Slots.h"
#include <iostream>
#include <iomanip>
#include <string>


void Slots::slots() {

	std::cout << "Welcome to the Slot Machine!\n\n";

	std::cout << std::setw(20) << "Payouts:\n\n";
	std::cout << std::setw(41) << "Two @ and One $ in any position => 1:1\n";
	std::cout << std::setw(41) << "|  |  |  => 2:1\n";
	std::cout << std::setw(41) << "@  @  @  => 3:1\n";     //Shows all possible winnings
	std::cout << std::setw(41) << "Two Z and one $ in any position => 5:1\n";
	std::cout << std::setw(41) << "Z  Z  Z  => 10:1\n";
	std::cout << std::setw(41) << "+  +  +  => 100:1\n";
	std::cout << std::setw(41) << "Two + and One $ in any position => 200:1\n";
	std::cout << std::setw(42) << "$  $  $  => JACKPOT, 1000:1\n\n";

	play(); //call function
}

void Slots::play() {
	while (true) {
		int again = 0;

		srand((unsigned)time(0));

		betVal(); //call from money class
		std::cout << "Spinning...\n\n";

		r1 = (rand() % 15);
		r2 = (rand() % 15); //random numbers between 0-14
		r3 = (rand() % 15);

		std::cout << "-------------------------\n";
		std::cout << "|       |       |       |\n";
		std::cout << "|   " << First[r1] << "   |   " << Second[r2] << "   |   " << Third[r3] << "   |\n";
		std::cout << "|       |       |       |\n"; //displays slot machine
		std::cout << "-------------------------\n";

		Winnings(First, Second, Third); //call function

		while (again != 1 && again != 2) {
			std::cout << "Play again?\n1 - Yes\t2 - No\n";
			std::cin >> again;   //will only accept 1 or 2

		}
		if (again == 2) {      //ends while loop when 2 is entered, return to main function menu
			break;
		}
		else if (again == 1)   //continue game
			std::cout<<"\n";
	}

}

void Slots::Winnings(std::string one[], std::string two[], std::string three[]) {
	if (one[r1] == "@" && two[r2] == "@" && three[r3] == "$") { //conditions for win
		Payout = 1;
		bets = Payout * bets; //bet is multiplied by payout
		std::cout << "You won $" << bets << "!\n"; 
		win();  //multiplied bet is added to balance

	}
	else if (one[r1] == "@" && two[r2] == "$" && three[r3] == "@") {
		Payout = 1;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "$" && two[r2] == "@" && three[r3] == "@") {
		Payout = 1;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();                                                                //All if statements are conditions for wins or losses
		                                                                      //bet ratio is multiplied by bet and added to balance if win
	}                                                                         //bet is subtracted from balance if lose
	else if (one[r1] == "|" && two[r2] == "|" && three[r3] == "|") {
		Payout = 2;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "@" && two[r2] == "@" && three[r3] == "@") {
		Payout = 3;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "Z" && two[r2] == "Z" && three[r3] == "$") {
		Payout = 5;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "Z" && two[r2] == "$" && three[r3] == "Z") {
		Payout = 5;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "$" && two[r2] == "Z" && three[r3] == "Z") {
		Payout = 5;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "Z" && two[r2] == "Z" && three[r3] == "Z") {
		Payout = 10;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "+" && two[r2] == "+" && three[r3] == "+") {
		Payout = 100;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "+" && two[r2] == "+" && three[r3] == "$") {
		Payout = 200;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "+" && two[r2] == "$" && three[r3] == "+") {
		Payout = 200;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "$" && two[r2] == "+" && three[r3] == "+") {
		Payout = 200;
		bets = Payout * bets;
		std::cout << "You won $" << bets << "!\n";
		win();

	}
	else if (one[r1] == "$" && two[r2] == "$" && three[r3] == "$") {
		Payout = 1000;
		bets = Payout * bets;
		std::cout << "JACKPOT!! You won $" << bets << "!\n";
		win();

	}
	else {
		lose();        //subtract bet from balance
		noBalance();                            //check if no balance ->Money class function
		std::cout << "\nYou did not win.";
	}
}
