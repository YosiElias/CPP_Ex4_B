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
    class Ambassador:public Player  {

    public:
        Ambassador(Game &g, std::string name):Player(g, name){ this->_role="Ambassador";};
        void transfer(Player from, Player to);
        void block(Player p);

    }; // end of class Ambassador
}