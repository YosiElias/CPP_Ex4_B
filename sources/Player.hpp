#pragma once
/**
 * Header file for the Player class.
 * 
 * @author Yossi Elias
 * @since 2022
 */
#include "Game.hpp"
#include "Action.hpp"
#include <iostream>
#include <vector>
namespace coup {
    class Game;
//    class Player;

    class Player {

    private:
        std::string _name;
        int _id;
        void check_is_turn();


    protected:
        std::string _role;
        int _coins;
        bool _is_dead;
        Game * _Pgame;
        Action _last_action;
    public:
        Player(Game &g, std::string& name);
        void income();
        void foreign_aid();
        virtual void coup(Player p);    //Todo: virtual - maybe not need
        std::string role();
        int coins();
        void cahnge2dead();
        bool is_dead(){return this->_is_dead;};
        std::string get_name(){return this->_name;};


        Player();
    }; // end of class Player
}