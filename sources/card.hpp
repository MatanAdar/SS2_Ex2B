#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using namespace std;
namespace ariel{
class Card{

    private:
        int number;
        string shape;

    public:

        Card(){}

        Card(int number, string shape);

        Card getCard();

        int getNum();

        string getShape();

};
}
#endif