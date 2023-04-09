#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <random>
#include <algorithm>
#include <iostream>
#include <string>

using namespace ariel;
using namespace std;

#define NUMBER_OF_EACH_CARDS 13


// Game Constructor function
Game::Game(Player &p1,Player &p2): player1(p1), player2(p2){
    if(player1.get_playing_status() == true || player2.get_playing_status() == true){
        throw std::runtime_error("PLAYER ALREADY PLAY IN DIFFRENT GAME");
    }

    this->deck_of_cards = {};
    this->number_of_turns = 0;
    this->number_of_draws = 0;

    player1.set_playing_status(true);
    player2.set_playing_status(true);

    //create a deck of 52 cards
    create_deck();

    cout << "Before Shuffle:" << endl;
    // print each card before the shuffle
    print_cards_of_deck(this->deck_of_cards);

    //shuffle the cards
    shuffleDeck(this->deck_of_cards);
    cout << endl;

    cout << "After Shuffle:" << endl;
    // print each card after the shuffle
    print_cards_of_deck(this->deck_of_cards);
    cout << endl;

    //divide the deck to 2 players
    divideDeck(this->deck_of_cards);

    //print players stack and stack size
    cout << "player stack:" << endl;
    cout << "player1:" << endl;
    cout << player1.stacksize() << endl;
    player1.print_stack();
    cout << endl;

    cout << "player2:" << endl;
    cout << player2.stacksize() << endl;
    player2.print_stack();


}


// Create deck function
void Game::create_deck(){

    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        if(i==1){
            this->deck_of_cards.push_back(Card("Ace",i,"clubs"));
        }
        else if(i==11){
            this->deck_of_cards.push_back(Card("Jack",i,"Clubs"));
        }
        else if(i==12){
            this->deck_of_cards.push_back(Card("Queen",i,"Clubs"));
        }
        else if(i==13){
            this->deck_of_cards.push_back(Card("King",i,"Clubs"));
        }
        else{
            this->deck_of_cards.push_back(Card(std::to_string(i),i,"Clubs"));
        }
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        if(i==1){
            this->deck_of_cards.push_back(Card("Ace",i,"Hearts"));
        }
        else if(i==11){
            this->deck_of_cards.push_back(Card("Jack",i,"Hearts"));
        }
        else if(i==12){
            this->deck_of_cards.push_back(Card("Queen",i,"Hearts"));
        }
        else if(i==13){
            this->deck_of_cards.push_back(Card("King",i,"Hearts"));
        }
        else{
            this->deck_of_cards.push_back(Card(std::to_string(i),i,"Hearts"));
        }
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        if(i==1){
            this->deck_of_cards.push_back(Card("Ace",i,"Spades"));
        }
        else if(i==11){
            this->deck_of_cards.push_back(Card("Jack",i,"Spades"));
        }
        else if(i==12){
            this->deck_of_cards.push_back(Card("Queen",i,"Spades"));
        }
        else if(i==13){
            this->deck_of_cards.push_back(Card("King",i,"Spades"));
        }
        else{
            this->deck_of_cards.push_back(Card(std::to_string(i),i,"Spades"));
        }
    }
    for(int i=1;i<=NUMBER_OF_EACH_CARDS;i++){
        if(i==1){
            this->deck_of_cards.push_back(Card("Ace",i,"Diamonds"));
        }
        else if(i==11){
            this->deck_of_cards.push_back(Card("Jack",i,"Diamonds"));
        }
        else if(i==12){
            this->deck_of_cards.push_back(Card("Queen",i,"Diamonds"));
        }
        else if(i==13){
            this->deck_of_cards.push_back(Card("King",i,"Diamonds"));
        }
        else{
            this->deck_of_cards.push_back(Card(std::to_string(i),i,"Diamonds"));
        }
    }
}


// get deck function
vector<Card> Game::getDeck(){
        return this->deck_of_cards;
}


// prints each card in the deck
void Game::print_cards_of_deck(vector<Card> deck_of_cards){
    for (size_t i = 0; i < deck_of_cards.size(); i++) {
        cout << deck_of_cards[i].getCardType()<< " of " << deck_of_cards[i].getShape() << endl;
    }
}


// shuffle deck function
void Game::shuffleDeck(vector<Card> &deck_of_cards){
    srand(time(NULL));
    random_shuffle(deck_of_cards.begin(),deck_of_cards.end());
}


//divide cards to 2 players function
void Game::divideDeck(vector<Card> &deck_of_cards){
    if(deck_of_cards.size() == 0){
        return;
    }
    
    while(deck_of_cards.size() != 0){
        player1.insert_cards_to_stack(deck_of_cards.back());
        deck_of_cards.pop_back();
    
        player2.insert_cards_to_stack(deck_of_cards.back());
        deck_of_cards.pop_back();
    }
}


// divide cards to 2 players to there cardsTaken function(happend when we have a draw and no more cards in stack)
void Game::divideDeck_cardsTaken(vector<Card> &deck_of_cards){
    if(deck_of_cards.size() == 0){
        return;
    }
    // we want it that player2 get the card first because we take from the back of the deck(last card),
    // and then each player will get his cards back if we have a draw
    while(deck_of_cards.size() != 0){
        player2.insert_cards_to_cardsTaken(deck_of_cards.back());
        deck_of_cards.pop_back();

        player1.insert_cards_to_cardsTaken(deck_of_cards.back());
        deck_of_cards.pop_back();
    }
}


// PlayTurn function
void Game::playTurn(){

    // Checking if the game play by one player only(player1 and player 2 is the same)
    if(&player1 == &player2){
        throw std::runtime_error(" THERE ARE THE SAME PLAYER");
    }

    // checking if we have cards in the stack to play turn/if we ended the game already
    if(this->player1.stacksize() == 0 && this->player2.stacksize() == 0){
        throw std::runtime_error("The game is over already. Cant pull from empty deck");
    }

    Card p1_card = player1.pull_last_card_from_stack();
    Card p2_card = player2.pull_last_card_from_stack();

    get_turn_status(p1_card,p2_card);

    // Checking if anyone win
    if(p1_card.getNum() > p2_card.getNum()){
        // Increase number of wins for player1 by 1
        player1.setNumberOfWins();
        // Increase the number of turn by 1
        this->number_of_turns = this->number_of_turns+1;
        player1.insert_cards_to_cardsTaken(p1_card);
        player1.insert_cards_to_cardsTaken(p2_card);
    }
    else if(p1_card.getNum() < p2_card.getNum()){
        // Increase number of wins for player2 by 1
        player2.setNumberOfWins();
        // Increase the number of turn by 1
        this->number_of_turns = this->number_of_turns+1;
        player2.insert_cards_to_cardsTaken(p1_card);
        player2.insert_cards_to_cardsTaken(p2_card);
    }
    else{ // when we have a draw
        vector<Card> temp = {};
        Card p1_tie;
        Card p2_tie;

        // add the even cards to the temporery deck 
        temp.push_back(p1_card);
        temp.push_back(p2_card);

        bool isTie = true;

        while(isTie){
            
            // Checking if we have cards in the stack to continue the while loop
            if(this->player1.stacksize() == 0 && this->player2.stacksize() == 0){
                this->number_of_draws = this->number_of_draws+1;
                isTie=false;
            }

            // increse the number of draws that happend
            this->number_of_draws = this->number_of_draws+1;

            if(this->player1.stacksize() > 0 && this->player2.stacksize() > 0){
                temp.push_back(player1.pull_last_card_from_stack());
                temp.push_back(player2.pull_last_card_from_stack());
                if(this->player1.stacksize() > 0 && this->player2.stacksize() > 0){
                    p1_tie = player1.pull_last_card_from_stack();
                    p2_tie = player2.pull_last_card_from_stack();

                    // checking if someone win the tie-breaker
                    if(p1_tie.getNum() > p2_tie.getNum()){
                        get_turn_status(p1_tie,p2_tie);
                        // Increase number of wins for player1 by 1
                        player1.setNumberOfWins();
                        // Increase the number of turn by 1
                        this->number_of_turns = this->number_of_turns+1;
                        player1.insert_cards_to_cardsTaken(p1_tie);
                        player1.insert_cards_to_cardsTaken(p2_tie);
                        while(temp.size()>0){
                            player1.insert_cards_to_cardsTaken(temp.back());
                            temp.pop_back();
                        }
                        isTie = false;
                    }
                    else if(p1_tie.getNum() < p2_tie.getNum()){
                        get_turn_status(p1_tie, p2_tie);
                        // Increase number of wins for player2 by 1
                        player2.setNumberOfWins();
                        // Increase the number of turn by 1
                        this->number_of_turns = this->number_of_turns+1;
                        player2.insert_cards_to_cardsTaken(p1_tie);
                        player2.insert_cards_to_cardsTaken(p2_tie);
                        while(temp.size()>0){
                            player2.insert_cards_to_cardsTaken(temp.back());
                            temp.pop_back();
                        }
                        isTie = false;
                    }
                    
                    // if no one wins the tie breaker this loop(its mean the cards again the same number),
                    // so we put the tie cards in the temp deck and continue to the next pull(continue the while loop)
                    temp.push_back(p1_tie);
                    temp.push_back(p2_tie);

                    // Checking if we have cards in the stack to continue the while loop
                    if(this->player1.stacksize() ==0 && this->player2.stacksize() == 0){
                        isTie=false;
                    }
                }
                else{ // when we put card upside down and there no more cards in stack to pull card to check who win the tie break
                    shuffleDeck(temp);
                    divideDeck_cardsTaken(temp);
                    isTie=false;
                }
            }
            else{ // when we dont have cards in stack to pull the upside-down card (last pull was the tie cards)
                divideDeck_cardsTaken(temp);
                isTie=false;
            }
        }
        // its mean that the last card is the same the there is no more cards in the stack so its a draw
        if((p1_tie.getNum() == p2_tie.getNum()) && (this->player1.stacksize() == 0 && this->player2.stacksize() == 0)){
            divideDeck_cardsTaken(temp);
            cout << "Draw" << endl;
        }

    }

    if(this->player1.stacksize() ==0 && this->player2.stacksize() == 0){
        player1.set_playing_status(false);
        player2.set_playing_status(false);
    }
}


// save turn status lines(what card each player pull and who win)
void Game::get_turn_status(Card p1_card, Card p2_card){

    if(p1_card.getNum() > p2_card.getNum()){
        // Save as string what happend this turn
        this->turn_status_print = (player1.getName() + " played " + p1_card.getCardType() + " of " + p1_card.getShape() + " " + player2.getName() + " played " + p2_card.getCardType() + " of " + p2_card.getShape() + ". " + player1.getName() +" wins.\n");
        // Save as string including what happend in all turns togheter
        this->print_all_log.append(this->turn_status_print);
    }
    else if(p1_card.getNum() < p2_card.getNum()){
        // Save as string what happend this turn
        this->turn_status_print = (player1.getName() + " played " + p1_card.getCardType() + " of " + p1_card.getShape() + " " + player2.getName() + " played " + p2_card.getCardType() + " of " + p2_card.getShape() + ". " + player2.getName() +" wins.\n");
        // Save as string including what happend in all turns togheter
        this->print_all_log.append(this->turn_status_print);
    }
    else{
        // Save as string what happend this turn
        this->turn_status_print = (player1.getName() + " played " + p1_card.getCardType() + " of " + p1_card.getShape() + " " + player2.getName() + " played " + p2_card.getCardType() + " of " + p2_card.getShape() + ". Draw. ");
        // Save as string including what happend in all turns togheter
        this->print_all_log.append(this->turn_status_print);
    }
}


// print turn status line for the last turn
void Game::printLastTurn(){

    cout << this->turn_status_print << endl;
}


// play all function
void Game::playAll(){
    while(player1.stacksize() > 0 && player2.stacksize() > 0){
        playTurn();
    }
    if(this->player1.stacksize() == 0 && this->player2.stacksize() == 0){
        player1.set_playing_status(false);
        player2.set_playing_status(false);
        // player1.playing_already = false;
        // player2.playing_already = false;
    }
}


// print winner of the game
void Game::printWiner(){
    if(this->player1.stacksize() == 0 && this->player2.stacksize() == 0){
        if(this->player1.cardesTaken() > this->player2.cardesTaken()){
            cout << this->player1.getName() << endl;
        }
        else if(this->player1.cardesTaken() < this->player2.cardesTaken()){
            cout << this->player2.getName() << endl;
        }
        else{
            cout << "Draw" << endl;
        }
    }
    else{

        cout << "-------- GAME IS NOT OVER---------" << endl;
    }
}


// print all turn status that happend all game
void Game::printLog(){

    cout << this->print_all_log << endl;
}


// print stats for each player function
void Game::printStats(){
    cout << "************* Player 1 stats: *****************" << endl;
    //winRate player1
    cout << "WinRate:" << endl;
    float winRate_player1 = (player1.getNumberOfWins() / this->number_of_turns) *100;
    string str_winRate_player1 = std::to_string(winRate_player1) + "%";
    cout << str_winRate_player1 << endl;

    cout << "CardsWon:" << endl;
    int cards_won_player1 = player1.cardesTaken();
    cout << cards_won_player1 << endl;

    cout << "DrawRate:" << endl;
    float drawRate_of_player1 = (this->number_of_draws / this->number_of_turns) *100;
    string str_drawRate_player1 = std::to_string(drawRate_of_player1) + "%";
    cout << str_drawRate_player1 << endl;

    cout << "Amout of draws:" << endl;
    cout << this->number_of_draws << endl;

    cout << "************* Player 2 stats: *****************" << endl;
    //winRate player2
    cout << "WinRate:" << endl;
    float winRate_player2 = (player2.getNumberOfWins() / this->number_of_turns) *100;
    string str_winRate_player2 = std::to_string(winRate_player2) + "%";
    cout << str_winRate_player2 << endl;

    cout << "CardsWon:" << endl;
    int cards_won_player2 = player2.cardesTaken();
    cout << cards_won_player2 << endl;

    cout << "DrawRate:" << endl;
    float drawRate_of_player2 = (this->number_of_draws / this->number_of_turns) *100;
    string str_drawRate_player2 = std::to_string(drawRate_of_player2) + "%";
    cout << str_drawRate_player2 << endl;

    cout << "Amout of draws:" << endl;
    cout << this->number_of_draws << endl;

}