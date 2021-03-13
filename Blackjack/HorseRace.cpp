#include "HorseRace.h"
#include<algorithm>         //allows for sort function
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>


void HorseRace::play() {

	while (true) {
		int again = 0;
	srand((unsigned)time(0));

	shuffleString(Horses, 10);
	shuffleString(Riders, 10);

	std::cout << "Welcome to Horse Racing!\n\n";

	/*Show options*/
	//Lists Horses and racers
		std::cout << std::setw(2) << "#:" << "\t" << std::setw(9) << "Horse:" << "\t" << std::setw(14) << "Rider:" << "\t" << std::setw(6) << "Win %:" << "\t" << std::setw(7) << "Payout:\n";

		for (int i = 0; i < 10; i++) {
			WinPercent[i] = (rand() % 100) + 1;       //Randomize win percentage
		}

		for (int i = 0; i < 5; i++) {
			std::sort(WinPercent, WinPercent + 5, std::greater<int>()); //Sort win percentages

			std::cout << std::setw(2) << Choice[i] << "\t" << std::setw(9) << Horses[i] << "\t" << std::setw(14) << Riders[i] << "\t" << std::setw(6) << WinPercent[i] << "\t";

			if (WinPercent[i] >= 80) {
				Pay[i] = 2;
			}
			else if (WinPercent[i] < 80 && WinPercent[i] >= 70) {
				Pay[i] = 4;
			}
			else if (WinPercent[i] < 70 && WinPercent[i] >= 60) {
				Pay[i] = 5;
			}
			else if (WinPercent[i] < 60 && WinPercent[i] >= 50) {     //Lower the win percentage, higher payout
				Pay[i] = 7;
			}
			else if (WinPercent[i] < 50 && WinPercent[i] >= 40) {
				Pay[i] = 8;
			}
			else if (WinPercent[i] < 40 && WinPercent[i] >= 30) {
				Pay[i] = 10;
			}
			else if (WinPercent[i] < 30 && WinPercent[i] >= 20) {
				Pay[i] = 13;
			}
			else if (WinPercent[i] < 20 && WinPercent[i] >= 10) {
				Pay[i] = 15;
			}
			else {
				Pay[i] = 20;
			}

			std::cout << std::setw(5) << Pay[i] << ":1\n";  //lists payout next to options
		}

		/*choose a horse*/

		std::cout << "\nChoose a horse: #";
		std::cin >> input;                          //Choose who to bet on
		while (input > 5) {
			std::cout << "Invalid input! Choose a horse: #";
			std::cin >> input;                              //wont accept values greater than 5
		}

		betVal();       //call function from money class-> displays current balance and asks for bet

		std::cout << "Racing...\n";

		/*find winner*/

		Winner();   //call function

		std::cout << "Horse #" << Choice[winner - 1] << ", " << Horses[winner - 1] << ", wins.\n";


		/*declare payout*/

		if (winner == input) {
			winnings = Pay[winner - 1] * bets;           //bet is multiplied by payout
			win();                                         //call function from money class
			std::cout << "You won $" << winnings << "!\n";
				while (again != 1 && again != 2) {
					std::cout << "Would you like to play again ? \n1 - Yes\t2 - No\n";
					std::cin >> again;                       //loop question, must input 1 or 2
				}
			if (again == 2) {          //exits to main function menu
				break;
			}
			else if (again ==1) {            //continue playing game
				std::cout << "\n";
			}
		}
		else {
			lose();         //call function from money class
			noBalance();    //call function from money class
			std::cout << "You lost.\n";
			while (again != 1 && again != 2) {
				std::cout << "Try again?\n1 - Yes\t2 - No\n";
				std::cin >> again;     //loop question
			}
			if (again == 2) {
				break;      //exit to main function menu
			}
			else if (again == 1) {
				std::cout << "\n";  //continur game
			}
		}
	}
}

void HorseRace::shuffleString(std::string option[], int n) {
	srand((unsigned)time(0));

	for (int i = 0; i < n; i++) {
		int r = i + (rand() % (10 - i));  //shuffles horse and rider
		swap(option[i], option[r]);
	}
}

int HorseRace::Winner() {
	srand((unsigned)time(0));

	int r;

	r = (rand() % 100) + 1;

	if (r <= 50) {
		winner = 1;
	}
	else if (r > 50 && r <= 75) {        //determines winner through precentages
		winner = 2;
	}
	else if (r + 1 > 75 && r + 1 <= 90) {
		winner = 3;
	}
	else if (r + 1 > 90 && r + 1 <= 97) {
		winner = 4;
	}
	else if (r + 1 > 97 && r + 1 <= 100) {
		winner = 5;
	}

	return winner;
}

