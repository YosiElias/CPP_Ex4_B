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


    protected:
        std::string _role;
        int _coins;
        bool _is_dead;
        Game * _Pgame;
        void check_is_turn();

    public:
        Player(Game &g, std::string& name);
        void income();
        void foreign_aid();
        virtual void coup(Player &p);    //Todo: virtual - maybe not need
        std::string role();
        int coins();
        void cahnge2dead();
        void back2life();
        bool is_dead() const{return this->_is_dead;};
        std::string get_name(){return this->_name;};
        Action get_action() const{return this->_last_action;};
        void block_foreign_aid();
        void less_coin(){this->_coins --;};
        void add_coin(){this->_coins ++;};
        Action _last_action;


        Player();
    }; // end of class Player
}