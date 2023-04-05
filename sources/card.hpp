#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using namespace std;
namespace ariel{}

class Card{

    private:
        string card_type;
        int number;
        string shape;

    public:

        Card();

        Card(string card_type, int number, string shape);

        Card getCard();

        string getCardType();

        int getNum();

        string getShape();

};

#endif