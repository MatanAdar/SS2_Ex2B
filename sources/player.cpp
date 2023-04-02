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

int Player::stacksize(){
    return 0;
}

int Player::cardesTaken(){
    return 0;
}  
