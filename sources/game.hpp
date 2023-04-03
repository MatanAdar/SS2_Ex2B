#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "iostream"
#include "card.hpp"

namespace ariel{}
class Game{

    private:
        Player *player1;
        Player *player2;
        vector<Card> deck_of_cards;

    public:

        Game(){}

        Game(Player &player1,Player &player2);

        void create_deck();

        void print_cards_of_deck(vector<Card> deck_of_cards);

        vector<Card> getDeck();

        void shuffleDeck(vector<Card> &deck_of_cards);

        void divideDeck(vector<Card> &deck_of_cards);

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        void playTurn();

        void printLastTurn();


};



#endif