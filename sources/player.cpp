#include "player.hpp"

#include <string>

#include <iostream>
using namespace std;
using namespace ariel;



Player::Player(string name){
    this->myName=name;
}

string Player::getName(){
    return this->myName;
}

void insert_cards_to_stack(Card(int number, string shape)){
    
}

vector<Card> Player::getStack(){
    return this->stack;
}

vector<Card> Player::getCardsTaken(){
    return this->cardsTaken;
}


int Player::stacksize(){
    return 0;
}

int Player::cardesTaken(){
    return 0;
}  
