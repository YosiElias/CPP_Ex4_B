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
    class Contessa:public Player  {

    public:
        Contessa(Game &g, std::string name):Player(g, name){ this->_role="Contessa";};
        void block(Player &p);

    }; // end of class Contessa
}