
#include "Roulette.h"
#include <time.h>

void Roulette::print() {
	//Welcome
	std::cout << " Hello Welcome to Casino Royale's Roulette Table" << std::endl;
	std::cout << " Please choose from the possible betting options below" << std::endl;
	std::cout << " With respect to the presented option enter it in the console to pick it" << std::endl
		<< std::endl;
	//Table
	std::cout << " Table: " << std::endl << std::endl;
	std::cout
		<< " ___________________"
		<< " \n |        0        | "
		<< " \n |_________________|_________________"
		<< " \n |  1  |  2  |  3  |        |       |"
		<< " \n |_________________|        | 1-18  |"
		<< " \n |  4  |  5  |  6  |        |       |"
		<< " \n |_________________| 1st 12 |_______|"
		<< " \n |  7  |  8  |  9  |        |       |"
		<< " \n |_________________|        | Even  |"
		<< " \n |  10 |  11 |  12 |        |       |"
		<< " \n |_________________|________|_______|"
		<< " \n |  13 |  14 |  15 |        |       |"
		<< " \n |_________________|        |  Red  |"
		<< " \n |  16 |  17 |  18 |        |       |"
		<< " \n |_________________| 2nd 12 |_______|"
		<< " \n |  19 |  20 |  21 |        |       |"      //Display roulette table
		<< " \n |_________________|        | Black |"
		<< " \n |  22 |  23 |  24 |        |       |"
		<< " \n |_________________|________|_______|"
		<< " \n |  25 |  26 |  27 |        |       |"
		<< " \n |_________________|        |  Odd  |"
		<< " \n |  28 |  29 |  30 |        |       |"
		<< " \n |_________________| 3rd 12 |_______|"
		<< " \n |  31 |  32 |  33 |        |       |"
		<< " \n |_________________|        | 19-36 |"
		<< " \n |  34 |  35 |  36 |        |       |"
		<< " \n |_________________|________|_______|"
		<< " \n |  C1 |  C2 | C3  |        |       "
		<< " \n |_________________|________|       ";
	std::cout << std::endl << std::endl;
	//Betting options
	std::cout << " 0: Specific Number -- Pays out 35 : 1 " << std::endl;
	std::cout << " 1: Odd -- Pays out 1 : 1 " << std::endl;
	std::cout << " 2: Even -- Pays out 1 : 1 " << std::endl;
	std::cout << " 3: Red -- Pays out 1 : 1 " << std::endl;
	std::cout << " 4: Black -- Pays out 1 : 1 " << std::endl;   //display all bet ratios
	std::cout << " 5: 1 - 18 --Pays out 1 : 1 " << std::endl;
	std::cout << " 6: 19 - 36 --Pays out 1 : 1 " << std::endl;
	std::cout << " 7: Column 1 --Pays out 2 : 1 " << std::endl;
	std::cout << " 8: Column 2 --Pays out 2 : 1 " << std::endl;
	std::cout << " 9: Column 3 --Pays out 2 : 1 " << std::endl;
	std::cout << " 10: Leave " << std::endl;

}

// PLAYING THE GAME
void Roulette::play() {
	int choice = 0;

	while (true) {
		std::cout << "Please enter your choice" << std::endl;
		std::cin >> betType;

		//Leave
		if (betType == 10) {            //exit to main function menu
			break;                      //infront of all other if statements since it has priority
		}

		betVal();         //call from Money class

		srand(time(NULL));
		int randomNumber = (rand() % 36) + 1;     //generate a random number to land on between 1-36

		// Specific Number //
		if (betType == 0) {
			std::cout << "Specific Number (1-36)-- Pays out 35 : 1" << std::endl;
			std::cout << "Please choose an number to bet on " << std::endl;
			std::cin >> specificNum;

			if (specificNum == randomNumber) {
				std::cout << "You WON!! \n" << std::endl;
				bets = bets * 35; //bet is multiplied by pay ratio
				win();             //balance + bet
			}

			else {
				std::cout << "Try again next time " << std::endl;
				std::cout << "Rolled: " << randomNumber << std::endl;
				std::cout << "You lost!! \n" << std::endl;
				lose();    //balance = bet
				noBalance(); //check if no balance
			}



		}
		// ODD //
		else if (betType == 1) {
			std::cout << "You choose ODD" << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl;
			for (int i = 0; i < 18; i++) {
				if (odd[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;
					win();
					break;                                                  //win if you chose an odd number
				}                                                           //lose if you chose an even number
				else if (even[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}

		// EVEN //
		else if (betType == 2) {
			std::cout << "You choose EVEN" << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl;
			for (int i = 0; i < 18; i++) {
				if (even[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;                  //lose if you chose an odd number
					win();                                                   //win if you chose an even number
					break;
				}
				else if (odd[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}

		// RED //
		else if (betType == 3) {
			std::cout << "You choose RED" << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl;
			for (int i = 0; i < 18; i++) {
				if (red[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;   //win if you chose a number that was red 
					win();										//lose if you chose a number that was black
					break;
				}
				else if (black[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}

		// BLACK //
		else if (betType == 4) {
			std::cout << "You choose BLACK" << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl;
			for (int i = 0; i < 18; i++) {
				if (black[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;
					win();												//lose if you chose a number that was red
					break;												//win if you chose a number that was black
				}
				else if (red[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}

		// 1-18 //
		else if (betType == 5) {
			std::cout << "You choose 1-18" << std::endl << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl << std::endl;
			for (int i = 0; i < 18; i++) {
				if (one_eighteen[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;
					win();										//win if you chose a number from 1-18
					break;										//other wise lose
				}
				else if (nineteen_thirtysix[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}

		// 19-36 //
		else if (betType == 6) {
			std::cout << "You choose 19-36" << std::endl << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl << std::endl;
			for (int i = 0; i < 18; i++) {
				if (nineteen_thirtysix[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;
					win();
					break;										//win if you chose a number from 19-36, else lose
				}
				else if (one_eighteen[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}

		// Column 1 //
		else if (betType == 7) {
			std::cout << "You choose C1" << std::endl << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl << std::endl;
			for (int i = 0; i < 12; i++) {
				if (c1[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;
					bets = bets * 2;
					win();
					break;
				}
				else if (c2[i] == randomNumber) {                //win if you chose a number in column 1, else lose
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}

				else if (c3[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}

		// Column 2 //
		else if (betType == 8) {
			std::cout << "You choose C2" << std::endl << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl << std::endl;
			for (int i = 0; i < 12; i++) {
				if (c2[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;
					bets = bets * 2;
					win();
					break;
				}
				else if (c3[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();					//win if you chose a number in column 2, else lose
					break;
				}
				else if (c1[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}

		// Column 3 //
		else if (betType == 9) {
			std::cout << "You choose C3" << std::endl << std::endl;
			std::cout << "And the number is: " << randomNumber << std::endl << std::endl;
			for (int i = 0; i < 12; i++) {
				if (c3[i] == randomNumber) {
					std::cout << "You win \n" << std::endl;
					bets = bets * 2;
					win();
					break;
				}
				else if (c2[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();							//win if you chose a number in column 3, else lose
					break;
				}

				else if (c1[i] == randomNumber) {
					std::cout << "You lost \n" << std::endl;
					lose();
					noBalance();
					break;
				}


			}

		}
		else
		std::cout << "Please enter a valid choice.\n";
		while (choice != 1 && choice != 2) {
			std::cout << "Would you like to play again?\n";
			std::cout << "1. Yes          2.No :(" << std::endl;
			std::cin >> choice;   //looping question, only accepts 1 or 2

		}
		if (choice == 2)
			break;            //exit to main function menu
		else if (choice == 1)
			"\n";             //continue playing game
	}
}