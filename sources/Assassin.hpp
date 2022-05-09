#pragma once
/**
 * Header file for the Player class.
 * 
 * @author Yossi Elias
 * @since 2022
 */
#include "Player.hpp"

#include <iostream>
#include <vector>
namespace coup {
    class Assassin:public Player  {

    private:
        Player * _killed;

    public:
        Assassin(Game &g, std::string name):Player(g, name){ this->_role="Assassin";};
        void coup (Player &p);
        Player* get_killed(){return this->_killed;};

    }; // end of class Assassin
}