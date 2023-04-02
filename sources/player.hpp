#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

namespace ariel{

class Player{

    private:
        string myName;

    public:

        Player(){}

        Player(string name);

        string getName();

        int stacksize();

        int cardesTaken();   

};
}

#endif