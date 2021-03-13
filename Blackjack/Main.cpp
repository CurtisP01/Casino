#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Blackjack.h"
#include "HorseRace.h" //Including all header files
#include "Slots.h"
#include "Roulette.h"

using namespace std;

int main() 
{
	int game = 0;         //initialize game so while loop can run
	Blackjack blackjack;  //Creating objects for classes
	HorseRace race;
	Slots slots;
	Roulette r;

	while (game != 5) {
		cout << "~~=========================~~\n  Welcome to Casino Royale!\n~~=========================~~\n\n";
		cout << "Which game would you like to play?\n";
		cout << "\t1. Blackjack\n\t2. HorseRaces\n\t3. Slots\n\t4. Roulette\n\t5. Exit\n";
		cin >> game;
		
		switch (game) {       //Menu for the game selection. Default will loop with error message.
			//Blackjack
		case 1:
			cout << "~~=====================~~\n  Welcome to Blackjack!\n~~=====================~~\n\n";
			blackjack.setCards(); //Sets all random values as cards once
			blackjack.print();    

			break;
			//HorseRace
		case 2:
			race.play();

			break;
			//Slots
		case 3:
			slots.slots();
			break;
			//Roulette
		case 4:
			r.print();        //Prints betws and roulette table
			r.play();

			break;
		case 5: 
			cout << "\nThank you for playing at Casino Royale!\n";
			cout << "Your total profit/loss was $" << balance - 1000 << " \n";
			cout << "You have $" << balance<<"\n"; //output total gain/loss and current balance
			break;                                 //End of program
		default:
			cout << "That is not a valid option. Please choose a number from 1-4.\n";
		}
	}
}
