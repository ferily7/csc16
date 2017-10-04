/* Author: Farrah Lee
Program: Playing Blackjack */
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function prototypes
int deal(vector<int> & deck);
int player_plays(vector<int> & player_hand, vector<int> & deck);
int dealer_plays(vector<int> & dealer_hand, vector<int> & deck);
void initialize(vector<int> & deck);
void play_game();
int value(vector<int> & hand);
void print_hand(string who, vector<int> & hand);
void print_rank(int c);

int main(){
	//Initializes the game
	play_game();

	char answer;
	//Asks the player if they would like to play again
	cout << "Would you like to take a challenge and play Blackjack again? Y or N? ";
	cin >> answer;

	while (answer == 'Y' || answer == 'y'){
		play_game();
		cout << "Play again? ";
		cin >> answer;
	}
	cout << "Thank you for playing!! Good-bye!!!!" << endl;
	return 0;
}

void play_game(){
	//Initialization of variables
	vector<int> deck;
	initialize(deck);
	vector<int> player_hand;
	vector<int> dealer_hand;

	//Deals cards to the player and the dealer
	for(int i=0;i<2;i++){
		player_hand.push_back(deal(deck));
	}
	dealer_hand.push_back(deal(deck));

	//This prints out the Player and Dealer's current hand
	print_hand("Player", player_hand);
	print_hand("Dealer", dealer_hand);

	//This gets the value of the player and dealer's hand
	int player_value, dealer_value;
	player_value = player_plays(player_hand, deck);
	dealer_value = dealer_plays(dealer_hand, deck);

	cout << "**********************\n" << "Game Over!\n"<< "**********************" << endl;
	print_hand("Player", player_hand);
	print_hand("Dealer", dealer_hand);

	//This if statement declares who wins the match
	if (player_value > 21 && dealer_value > 21){
		cout << "**********************\n" << "Bust for both Players! No one wins!\n" << "**********************" << endl;
	}	
	else if (dealer_value > 21 || ((player_value > dealer_value) && player_value <= 21)){
		cout << "**********************\n" << "Congratulations Player wins!!\n" <<"**********************" << endl;
	}
	else if (player_value > 21){
		cout << "**********************\n" << "Dealer wins!\n" << "**********************" << endl;
	}
	else if (player_value == dealer_value){
		cout << "**********************\n" << "Push! No one wins, try again!\n"<< "**********************" << endl;
	}
	else{
		cout << "**********************\n" << "Dealer wins!\n"<< "**********************" << endl;
	}
}

//This function deals a card from the deck 
int deal(vector<int> & deck){
	int r;
	r = rand() % 13;
	while (deck[r] == 0){
		r = rand() % 13;		
	}
	deck[r] -= 1;
	return r;
}

//This function initializes the deck
void initialize(vector<int> & deck){
	for(int i=0;i<12;i++){
		deck.push_back(4);
	}
}

 //This function is where the player is playing Blackjack
int player_plays(vector<int> & player_hand, vector<int> & deck){
	char answer;
	while (value(player_hand) < 21){
		cout << "Would you like to hit or stop? Type H or S: ";
		cin >> answer;
		if (answer == 'h' || answer == 'H'){
			player_hand.push_back(deal(deck));
			print_hand("Player", player_hand);
		}
		else{
			return value(player_hand);
		}
	}
	return value(player_hand);
}

//This function is where the Dealer makes its move
int dealer_plays(vector<int> & dealer_hand, vector<int> & deck){
    cout << "**********************\n" << "Dealer's Turn\n" << "**********************" << endl;
	while (value(dealer_hand) < 17){	
    	dealer_hand.push_back(deal(deck));
    	print_hand("Dealer", dealer_hand);
    }

    return value(dealer_hand);
}

int value(vector<int> & hand){
    int val = 0;
    for (int i = 0; i < hand.size(); i ++){
        int c_val = hand[i] + 1;
        if ( c_val > 10 ){
            c_val = 10;
		}
        val = val + c_val;
    }
    for (int i = 0; i < hand.size(); i ++){
        if (val <= 11  &&  hand[i] == 0 ){
            val = val + 10;
		}
    }
    return val;
}

//This function displays the player's hand
void print_hand(string who, vector<int> & hand){
    cout << who << "'s hand: " ;
    for(int i = 0; i < hand.size(); i ++){
        print_rank(hand[i]);
    }
    cout << endl;
    cout << "Value: " << value(hand) << endl;
}

void print_rank(int c){
    c = c + 1;
    if ( c >= 2 && c <= 10 ){
        cout << c << " ";
    }
    else switch(c){
        case 1: cout << "A "; break;
        case 11: cout << "J "; break;
        case 12: cout << "Q "; break;
        case 13: cout << "K "; break;
    }
}