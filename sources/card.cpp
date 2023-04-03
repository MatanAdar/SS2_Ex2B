#include "card.hpp"
#include <string>
using namespace ariel;


Card::Card(int number,string shape){
    this->number = number;
    this->shape = shape;
}

Card Card::getCard(){

    return Card(this->number,this->shape);
}

int Card::getNum(){
    return this->number;
}

string Card::getShape(){
    return this->shape;
}

