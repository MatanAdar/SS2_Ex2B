#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <random>
#include <algorithm>
#include <iostream>

using namespace ariel;
using namespace std;

#define NUMBER_OF_EACH_CARDS 13


Game::Game(Player &p1,Player &p2){
    this->player1 = &p1;
    this->player2 = &p2;

    //create a deck of 52 cards
    create_deck();

    cout << "Before Shuffle:" << endl;
    // print each card before the shuffle
    print_cards_of_deck(this->deck_of_cards);

    //shuffle the cards
    shuffleDeck(this->deck_of_cards);
    cout << endl;

    cout << "After Shuffle:" << endl;
    // print each card after the shuffle
    print_cards_of_deck(this->deck_of_cards);
    cout << endl;

    //divide the deck to 2 players
    divideDeck(this->deck_of_cards);

    cout << "player stack:" << endl;
    player1->print_stack();


}

void Game::create_deck(){

    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        this->deck_of_cards.push_back(Card(i,"clubs"));
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
            this->deck_of_cards.push_back(Card(i,"hearts"));
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
            this->deck_of_cards.push_back(Card(i,"spades"));
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
            this->deck_of_cards.push_back(Card(i,"diamonds"));
    }
}

vector<Card> Game::getDeck(){
        return this->deck_of_cards;
}

// prints each card in the deck
void Game::print_cards_of_deck(vector<Card> deck_of_cards){
    for (size_t i = 0; i < deck_of_cards.size(); i++) {
        cout << deck_of_cards[i].getNum()<< " of " << deck_of_cards[i].getShape() << endl;
    }
}


 void Game::shuffleDeck(vector<Card> &deck_of_cards){

    srand(time(NULL));
	random_shuffle(deck_of_cards.begin(),deck_of_cards.end());
    
    // random_device rd;
    // mt19937 g(rd());
    // shuffle(deck_of_cards.begin(), deck_of_cards.end(), g);

 }

 void Game::divideDeck(vector<Card> &deck_of_cards){

    // vector<Card> player1_cards(deck_of_cards.begin(), deck_of_cards.begin() + 26);
    // vector<Card> player2_cards(deck_of_cards.begin() + 26, deck_of_cards.end());

    // // assign the vectors to the players
    // player1.setStack(player1_cards); 
    // player2.setStack(player2_cards);


    size_t i=0;
    while(i<52){
        if(i%2 == 0){
            player1->insert_cards_to_stack(deck_of_cards[i]);
        }
        else{
            player2->insert_cards_to_stack(deck_of_cards[i]);
        }
        i++;
    }
 }


void Game::playAll(){

}

void Game::printWiner(){

}

void Game::printLog(){

}

void Game::printStats(){

}

void Game::playTurn(){

}

void Game::printLastTurn(){

}