//Blackjack.cpp
#include "Blackjack.h"

Blackjack::Blackjack() {
	numCards = 0;
	numCard = 0;
	playerSum = 0;
	dealerSum = 0;
	num = 0, nums = 0, nums1 = 0, dr = 0;    //Initialize all private variables
	for (int i = 0; i < 52; i++) {
		temp[i] = -1;
		cards[i] = "";
	}
	for (int i = 0; i < 7; i++) {
		playHand[i] = 0;
		dealHand[i] = 0;
	}
}
Blackjack::Blackjack(int num, int ps, int ds, double bal, double b) :Money(bal, b) {
	numCard = num;                          //Constructor including Money class variables
	playerSum = ps;
	dealerSum = ds;
}

void Blackjack::setCards() {
	int z = 0;
	for (int i = 0; i < 13; i++) {
		std::string temp;
		switch (i) {
		case 0: temp = "Ace";
			break;
		case 1: temp = "2";
			break;
		case 2: temp = "3";
			break;
		case 3: temp = "4";
			break;
		case 4: temp = "5";      //Assigning each value 1-52 a card
			break;               //There are 4 cards of each kind
		case 5: temp = "6";
			break;
		case 6: temp = "7";
			break;
		case 7: temp = "8";
			break;
		case 8: temp = "9";
			break;
		case 9: temp = "10";
			break;
		case 10: temp = "Jack";
			break;
		case 11: temp = "Queen";
			break;
		case 12: temp = "King";

		}
		for (int x = 0; x < 4; x++) {
			cards[z] = temp;
			z++;
		}
	}
}
void Blackjack::shuffle() {
	num = numCard = numCards = playerSum = dealerSum = nums = nums1 =0; //All variables are reset
	for (int i = 0; i < 52; i++)               //All previously drawn cards are now eligible to be redrawn
		temp[i] = -1;
}
int Blackjack::draw() {
	srand(time(NULL));
	int ran = rand() % 52;

	while (true) {
		for (int i = num; i < 52; i++) {

			ran = rand() % 52;
			for (int x = 0; x < 52; x++) {  //Ensures that the exact same card and suit is not drawn twice
				while (ran == temp[x]) {
					ran = rand() % 52;
					x = 0;
				}
			}
			temp[i] = ran;
			num++;                         //num increases each time so that the for loop will pick up where it left off
			break;
		}
		operator++();                      //Number of cards in players hand increases
		return ran;
		break;
	}
}
int Blackjack::convert(int dr) {
	int number;                         //variable dr is the randomly generated number that is put into cards array
	cards[dr];                          //Converts all random generated numbers into a card
	if (cards[dr] == "Ace") {           //ex. numbers 0 to 3 are Aces, 4 to 7 are 2's, 8-11 are 3's etc.
		number = 1;
		return number;
	}
	else if (cards[dr] == "King" || cards[dr] == "Queen" || cards[dr] == "Jack") {
		number = 10;                   //All kings queens and jacks are assigned a value of 10
		return number;
	}
	else {
		number = std::stoi(cards[dr]); //numbers are converted from string to ints
		return number;
	}
}
int Blackjack::playerAddSum(int dr) { //accepts variable dr from draw();
	for (int i = nums; i < numCard; i++) {
		playHand[i] = convert(dr);    //convert(dr) gives the value of the drawn card and stored in playHand[i]
		playerSum += playHand[i];     //adds up all cards in hand and stored in playerSum
		nums++;                      //nums increases so that the same card will not be added more than once
	}
	return playerSum;
}
int Blackjack::dealSum(int dr) {
	for (int i = nums1; i < numCards; i++) {
		dealHand[i] = convert(dr);        //separate array for dealer, same method as for player
		dealerSum += dealHand[i];
		nums1++;
	}
	return dealerSum;
}
void Blackjack::hit() {

	dr = draw();             //Randomly generated nunmber stored in variable dr

	std::cout << "You drew a " << cards[dr] << std::endl; //outputs card name
	std::cout << "Your cards add up to " << playerAddSum(dr) << std::endl; //outputs total card value

}
void Blackjack::playerStartCard() {
	dr = draw();
	std::cout << "You have a " << cards[dr];
	playerAddSum(dr);                                  //Function draws twice with different cout messages
	dr = draw();
	std::cout << " and a " << cards[dr] << std::endl;
	std::cout << "Your cards add up to " << playerAddSum(dr) << std::endl;
}
void Blackjack::dealerStart() {
	dr = draw();                                
	operator--();                               //operator-- since the draw function adds number of cards for player
	numCards++;                                 //number of cards for dealer increases
	std::cout << "The dealers first card is a " << cards[dr] << std::endl;

}
void Blackjack::dealerDraw() {
	dr = draw();
	operator--();                         //same as dealerStart with different cout messages
	numCards++;
	std::cout << "The dealers draws a " << cards[dr] << std::endl;
	std::cout << "The dealers cards add up to " << dealSum(dr) << "\n\n";
}
void Blackjack::choice() {
	int choice;
	Blackjack w;
	Money x;
	std::cout << "Would you like to hit or stay?\n";      
	while (true){
		std::cout << "\t1. Hit\n\t2. Stay\n";         //choice to hit or stay will loop until:
		std::cin >> choice;                             //A. user enters 2 for stay -> break from loop
		                                                //B. user busts from having a total sum of over 21
		if (choice == 1) {
			hit(); 
			if (playerAddSum(dr) > 21) {
				std::cout << "You Lose!";              //Player loses if sum is greater than 21
				lose();
				std::cout<<"You lost $"<<bets << std::endl;
				break;
			}
			else if (playerAddSum(dr) == 21) {         //Player wins if sum is equal to 21
				std::cout << "You Win!";
				win();
				std::cout << "You won $" << bets << std::endl;
				break;
			}
		}
		else if (choice == 2) {                        //Player chooses to stay
			while (dealSum(dr) <= 16)                 //Dealer will draw until 16, will not draw >=17
				dealerDraw();
			if (dealSum(dr) > 21) {                   //If dealer sum is greater than 21, player wins
				std::cout << "You Win!";
				win();
				std::cout << "You won $" << bets << std::endl;
			}
			else if (dealSum(dr) == 21) {              //If dealer gets 21, player loses
				std::cout << "You Lose!"; 
				lose();
				std::cout << "You lost $" << bets << std::endl;
			}
			else if (dealSum(dr) > playerAddSum(dr)) { //If dealer has a higher sum than player without going over 21, player loses
				std::cout << "You Lose!";
				lose();
				std::cout << "You lost $" << bets << std::endl;
			}
			else if (dealSum(dr) == playerAddSum(dr)) { //If dealer gets same sum as player, player loses
				std::cout << "You Lose!";
				lose();
				std::cout << "You lost $" << bets << std::endl;
			}
			else if (dealSum(dr) < playerAddSum(dr)) { //If player has higher sum than dealer without going over 21, player wins
				std::cout << "You Win!";
				win();
				std::cout << "You won $" << bets << std::endl;
			}
			break;
		}
		else {
			std::cout << "That is not a valid input. Please choose 1 or 2.\n";
		}                      // if input is not 1 or 2, loop continues


	}

}


void Blackjack::print() {
	char replay;
	while (true) {
		betVal();           //call from money class
		shuffle();
		std::cout << "\n   Shuffling Cards...\n~-----------------------~\n\n";
		playerStartCard(); //calls function -> player draws 2 cards
		std::cout << "\n";
		dealerStart();     // calls function -> dealer draws, player can see one card
		std::cout << "------------------------------\n";
		choice();          //calls function-> hit or stay loop
		noBalance();       //call from money calss

		std::cout << "\n........................" << std::endl;
		do {
			std::cout << "Play Again? (Y/N)"; //Prompt play again
			std::cin >> replay;
			replay = toupper(replay);     //accepts both lower and upper case
		} while (replay != 'Y' && replay != 'N');
		if (replay == 'N')  //exit game class, returns to main function
			break;
		else
			"\n";

	}
}

//increment operator
void Blackjack::operator ++() {
	++numCard;                   //increases number of cards in players hand

}

void Blackjack::operator--() {
	numCard--;               //decreases number of cards in players hand
}