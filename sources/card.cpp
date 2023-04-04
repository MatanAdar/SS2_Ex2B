#include "card.hpp"
#include <string>
using namespace ariel;


Card::Card(string card_type, int number,string shape){
    this->card_type = card_type;
    this->number = number;
    this->shape = shape;
}

Card Card::getCard(){

    return Card(this->card_type,this->number,this->shape);
}

string Card::getCardType(){
    return this->card_type;
}

int Card::getNum(){
    return this->number;
}

string Card::getShape(){
    return this->shape;
}

