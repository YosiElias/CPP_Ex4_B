/**
 * Implementation of Matrix class.
 *
 * @author Yossi Elias
 * @since 2022
 */


#include <iostream>
#include <stdexcept>
#include <utility>
#include <bits/stdc++.h>
#include "Player.hpp"
#include "Action.hpp"
using namespace std;

namespace coup{

    Player::Player(Game &g, string& name) {
        this->_name = name;
        this->_coins = 0;
        this->_last_action = Action::No_action;
        g.add_player(this);
        this->_Pgame = &g;
        this->_is_dead = false;
//        this->p_game = &g;
//        this->_id = g.add_player(this->_name);          //Todo: not needed
    }

    void Player::foreign_aid() {
        this->check_is_turn();
        if (this->_coins >= 10){
            throw std::logic_error("have to do a coup!");
        }
        this->_coins = this->_coins +2;
        this->_last_action = Action::foreign_aid;
        this->_Pgame->end_turn();
    }

     void Player::income() {
        this->check_is_turn();
        if (this->_coins >= 10){
            throw std::logic_error("have to do a coup!");
        }
        this->_coins = this->_coins +1;
        this->_last_action = Action::Income;
         this->_Pgame->end_turn();
     }

    void Player::coup(Player &p) {
        this->check_is_turn();
        if (this->_coins < 7){
            throw std::logic_error("not have coins to coup!");
        }
        if (p.is_dead()){
            throw std::logic_error("he is already dead");
        }
        p.cahnge2dead();
        this->_coins -= 7;
        this->_last_action = Action::coup;
        this->_Pgame->end_turn();
    }

    string Player::role() {
        return this->_role;
    }

    int Player::coins() {
        return this->_coins;
    }

    Player::Player() {
        this->_name = "";
        this->_coins = 0;
        this->_last_action = Action::No_action;
    }

    void Player::check_is_turn() {
        if (this->_Pgame->turn_pointer() != this){
            while (this->_Pgame->turn_pointer()->is_dead()){    //remove dead players and loop on it
                this->_Pgame->remove_player(this->_Pgame->turn_pointer());
                this->_Pgame->end_turn();
            }
            if (this->_Pgame->turn_pointer() != this) {   //check again after the loop
                throw std::logic_error("not his turn!");
            }
        }
//        if (this->_is_dead){  //Todo: not needed
//            this->_Pgame.remove_player(this->_id, this->_name);  //remove player in his turn
//            throw std::logic_error("he is dead");
//        }
    }

    void Player::cahnge2dead() {    //Todo: not needed
        this->_is_dead = true;
    }

    void Player::back2life() {
        this->_is_dead = false;
    }

    void Player::block_foreign_aid() {
        this->_coins -= 2;
        this->_last_action = Action::No_action; //because get blocked
    }

}