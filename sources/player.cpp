#include "player.hpp"

#include <string>

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    Player::Player(){
        this->myName="";
        this->stack = {};
        this->cardsTaken = {};
        this->number_of_wins = 0;
        this->playing_already = false;
    }


    Player::Player(string name){
        this->myName=name;
        this->stack = {};
        this->cardsTaken = {};
        this->number_of_wins = 0;
        this->playing_already = false;
    }

    string Player::getName(){
        return this->myName;
    }

    bool Player::get_playing_status(){
        return this->playing_already;
    }

    void Player::set_playing_status(bool isPlaying){
        this->playing_already = isPlaying;
    }

    void Player::insert_cards_to_stack(Card card){
        this->stack.push_back(card);
    }

    void Player::print_stack(){
        for(size_t i=0; i<stack.size();i++){
            cout << this->stack[i].getCardType() << " of " << this->stack[i].getShape() << endl;
        }
    }

    Card Player::pull_last_card_from_stack(){
        if(this->stack.size()>=0){
            Card to_play = this->stack.back();
            this->stack.pop_back();
            return to_play;
        }
        throw std::runtime_error("There is no more cards in the stack");
    }

    void Player::insert_cards_to_cardsTaken(Card card){
        this->cardsTaken.push_back(card);
    }

    void Player::print_cardesTaken(){
        for(size_t i=0; i<cardsTaken.size();i++){
            cout << this->cardsTaken[i].getCardType() << " of " << this->cardsTaken[i].getShape() << endl;
        }
    }

    int Player::getNumberOfWins(){
        return this->number_of_wins;
    }

    void Player::setNumberOfWins(){
        this->number_of_wins++;
    }


    int Player::stacksize(){
        return this->stack.size();
    }

    int Player::cardesTaken(){
        return this->cardsTaken.size();
    }

    void Player::destructor(){
        this->stack.clear();
        this->cardsTaken.clear();
        this->stack.shrink_to_fit();
        this->cardsTaken.shrink_to_fit();
    }

}
