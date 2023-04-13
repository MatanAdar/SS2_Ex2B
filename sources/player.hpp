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
            int number_of_wins;
            bool playing_already;

        public:

            Player();

            Player(string name);

            string getName();

            bool get_playing_status();

            void set_playing_status(bool isPlaying);

            void insert_cards_to_stack(Card card);

            void print_stack();

            Card pull_last_card_from_stack();

            void insert_cards_to_cardsTaken(Card card);

            void print_cardesTaken();

            int getNumberOfWins();

            void setNumberOfWins();

            int stacksize();

            int cardesTaken();

            void destructor();

    };

}


#endif