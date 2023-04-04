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
    cout << "player1:" << endl;
    cout << player1->stacksize() << endl;
    player1->print_stack();
    cout << endl;

    cout << "player2:" << endl;
    cout << player2->stacksize() << endl;
    player2->print_stack();


}

void Game::create_deck(){

    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        if(i==1){
            this->deck_of_cards.push_back(Card("Ace",i,"clubs"));
        }
        else if(i==11){
            this->deck_of_cards.push_back(Card("Jack",i,"Clubs"));
        }
        else if(i==12){
            this->deck_of_cards.push_back(Card("Queen",i,"Clubs"));
        }
        else if(i==13){
            this->deck_of_cards.push_back(Card("King",i,"Clubs"));
        }
        else{
            this->deck_of_cards.push_back(Card(std::to_string(i),i,"Clubs"));
        }
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        if(i==1){
            this->deck_of_cards.push_back(Card("Ace",i,"Hearts"));
        }
        else if(i==11){
            this->deck_of_cards.push_back(Card("Jack",i,"Hearts"));
        }
        else if(i==12){
            this->deck_of_cards.push_back(Card("Queen",i,"Hearts"));
        }
        else if(i==13){
            this->deck_of_cards.push_back(Card("King",i,"Hearts"));
        }
        else{
            this->deck_of_cards.push_back(Card(std::to_string(i),i,"Hearts"));
        }
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        if(i==1){
            this->deck_of_cards.push_back(Card("Ace",i,"Spades"));
        }
        else if(i==11){
            this->deck_of_cards.push_back(Card("Jack",i,"Spades"));
        }
        else if(i==12){
            this->deck_of_cards.push_back(Card("Queen",i,"Spades"));
        }
        else if(i==13){
            this->deck_of_cards.push_back(Card("King",i,"Spades"));
        }
        else{
            this->deck_of_cards.push_back(Card(std::to_string(i),i,"Spades"));
        }
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        if(i==1){
            this->deck_of_cards.push_back(Card("Ace",i,"Diamonds"));
        }
        else if(i==11){
            this->deck_of_cards.push_back(Card("Jack",i,"Diamonds"));
        }
        else if(i==12){
            this->deck_of_cards.push_back(Card("Queen",i,"Diamonds"));
        }
        else if(i==13){
            this->deck_of_cards.push_back(Card("King",i,"Diamonds"));
        }
        else{
            this->deck_of_cards.push_back(Card(std::to_string(i),i,"Diamonds"));
        }
    }
}

vector<Card> Game::getDeck(){
        return this->deck_of_cards;
}

// prints each card in the deck
void Game::print_cards_of_deck(vector<Card> deck_of_cards){
    for (size_t i = 0; i < deck_of_cards.size(); i++) {
        cout << deck_of_cards[i].getCardType()<< " of " << deck_of_cards[i].getShape() << endl;
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

void Game::playTurn(){

    Card p1_card = player1->pull_last_card_from_stack(this->player1->getStack());
    Card p2_card = player2->pull_last_card_from_stack(this->player2->getStack());

    if(p1_card.getNum() > p2_card.getNum()){
        player1->insert_cards_to_cardsTaken(p1_card);
        player1->insert_cards_to_cardsTaken(p2_card);
    }
    else if(p1_card.getNum() < p2_card.getNum()){
        player2->insert_cards_to_cardsTaken(p1_card);
        player2->insert_cards_to_cardsTaken(p2_card);
    }
    else{
        vector<Card> temp;
        Card p1_tie;
        Card p2_tie;
        while(p1_tie.getNum() == p2_tie.getNum()){
            temp.push_back(player1->pull_last_card_from_stack(player1->getStack()));
            temp.push_back(player2->pull_last_card_from_stack(player2->getStack()));

            p1_tie = player1->pull_last_card_from_stack(player1->getStack());
            p2_tie = player2->pull_last_card_from_stack(player2->getStack());

            if(p1_tie.getNum() > p2_tie.getNum()){
                player1->insert_cards_to_cardsTaken(p1_card);
                player1->insert_cards_to_cardsTaken(p2_card);
                while(temp.size()>0){
                    player1->insert_cards_to_cardsTaken(temp.back());
                    temp.pop_back();
                }
            }
            else if(p1_tie.getNum() < p2_tie.getNum()){
                player2->insert_cards_to_cardsTaken(p1_card);
                player2->insert_cards_to_cardsTaken(p2_card);
                while(temp.size()>0){
                    player2->insert_cards_to_cardsTaken(temp.back());
                    temp.pop_back();
                }
            }
        }

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

void Game::printLastTurn(){

}