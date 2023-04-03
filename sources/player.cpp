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
        cout << this->stack[i].getNum() << " of " << this->stack[i].getShape() << endl;
    }
}

vector<Card> Player::getStack(){
    return this->stack;
}

void Player::setStack(vector<Card> other){
    this->stack = other;
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
