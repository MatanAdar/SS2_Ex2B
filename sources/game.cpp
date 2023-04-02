#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace ariel;
using namespace std;

#define NUMBER_OF_EACH_CARDS 13


Game::Game(Player p1,Player p2){
    this->player1 = p1;
    this->player2 = p2;
}

//  void Game::create_deck(){

//     for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
//         this->deck_of_cards.push_back(Card(i,"clubs"));
//     }
//     for(int i=1;i<NUMBER_OF_EACH_CARDS;i++){
//          this->deck_of_cards.push_back(Card(i,"hearts"));
//     }
//     for(int i=1;i<NUMBER_OF_EACH_CARDS;i++){
//          this->deck_of_cards.push_back(Card(i,"spades"));
//     }
//     for(int i=1;i<NUMBER_OF_EACH_CARDS;i++){
//          this->deck_of_cards.push_back(Card(i,"diamonds"));
//     }
//  }

//  vector<Card> Game::getDeck(){
//         return this->deck_of_cards;
//     }

void Game::playAll(){

}

void Game::printWiner(){

}

void Game::printLog(){

}

void Game::printStats(){

}

void Game::playTurn(){

}

void Game::printLastTurn(){

}