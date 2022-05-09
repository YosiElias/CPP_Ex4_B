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
    class Duke:public Player {

    public:
        Duke(Game &g, std::string name):Player(g, name){ this->_role="Duke";};
        void tax();
        void block(Player p);

    }; // end of class Duke
}