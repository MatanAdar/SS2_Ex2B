#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "iostream"
#include "card.hpp"
#include <string>

namespace ariel{}
class Game{

    private:
        Player *player1;
        Player *player2;
        vector<Card> deck_of_cards;
        string turn_status_print;
        string print_all_log;
        float number_of_turns;
        int number_of_draws;

    public:

        Game();

        Game(Player &player1,Player &player2);

        void create_deck();

        void print_cards_of_deck(vector<Card> deck_of_cards);

        vector<Card> getDeck();

        void shuffleDeck(vector<Card> &deck_of_cards);

        void divideDeck(vector<Card> &deck_of_cards);

        void playTurn();

        void get_turn_status(Card p1_card, Card p2_card);

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        void printLastTurn();


};



#endif