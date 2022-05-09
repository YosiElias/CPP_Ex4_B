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
    class Captain:public Player  {

    private:
        Player * _steal_from;

    public:
        Captain(Game &g, std::string name):Player(g, name){ this->_role="Captain";};
        void steal(Player &p);
        void block(Player &p);
        Player * get_steal_from(){return this->_steal_from;};

    }; // end of class Captain
}