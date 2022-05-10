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
#include <memory>
namespace coup {
    class Game;
//    class Player;

    class Player {

    private:
        std::string _name;


    protected:
        std::string _role;
        int _coins;
        bool _is_dead;
        Game * Pgame;
        void check_is_turn();;
        Player * _steal_from;
        Player * _killed;
        const size_t NEED_COUP = 10;
        const size_t CAN_COUP = 7;
        const size_t MAX_PLAYERS = 6;


    public:
        Player(Game &g, std::string& name);
        ~Player() = default;
        void income();
        void foreign_aid();
        virtual void coup(Player &p);    //Todo: virtual - maybe not need
        std::string role();
        int coins()const;
        void cahnge2dead();
        void back2life();
        bool is_dead() const{return this->_is_dead;};
        std::string get_name(){return this->_name;};
        Action get_action() const{return this->_last_action;};
        void block_foreign_aid();
        void less_coin(){this->_coins --;};
        void add_coin(){this->_coins ++;};
        Action _last_action;  //deep c0py
        Player * get_steal_from(){return this->_steal_from;}


    }; // end of class Player
}