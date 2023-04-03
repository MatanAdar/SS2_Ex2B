#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel{

class Player{

    private:
        string myName;
        vector<Card> stack;
        vector<Card> cardsTaken;

    public:

        Player(){}

        Player(string name);

        string getName();

        void insert_cards_to_stack(Card(int number, string shape));

        vector<Card> getStack();

        vector<Card> getCardsTaken();

        int stacksize();

        int cardesTaken();   

};
}

#endif