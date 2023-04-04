#include "player.hpp"

#include <string>

#include <iostream>
#include <vector>

using namespace std;
using namespace ariel;


Player::Player(string name){
    this->myName=name;
    this->stack = {};
    this->cardsTaken = {};
}

string Player::getName(){
    return this->myName;
}

void Player::insert_cards_to_stack(Card c){
    this->stack.push_back(c);
}

void Player::print_stack(){
    for(size_t i=0; i<stack.size();i++){
        cout << this->stack[i].getCardType() << " of " << this->stack[i].getShape() << endl;
    }
}

vector<Card> Player::getStack(){
    return this->stack;
}

Card Player::pull_last_card_from_stack(vector<Card> stack){
    if(stack.size()>=0){
        Card to_play = stack.back();
        stack.pop_back();
        return to_play;
    }
    throw std::exception();
}

void Player::insert_cards_to_cardsTaken(Card c){
    this->cardsTaken.push_back(c);
}

vector<Card> Player::getCardsTaken(){
    return this->cardsTaken;
}


int Player::stacksize(){
    return this->stack.size();
}

int Player::cardesTaken(){
    return this->cardsTaken.size();
}  
