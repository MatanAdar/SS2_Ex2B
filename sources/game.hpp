#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "iostream"
#include "card.hpp"

namespace ariel{
class Game{

    private:
        Player player1;
        Player player2;
        vector<Card> deck_of_cards;

    public:

        Game(){}

        Game(Player player1,Player player2);

        // void create_deck();

        // vector<Card> getDeck();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        void playTurn();

        void printLastTurn();





};
}


#endif