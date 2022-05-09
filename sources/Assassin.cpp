/**
 * Implementation of Assassin class.
 *
 * @author Yossi Elias
 * @since 2022
 */


#include <iostream>
#include <stdexcept>
#include <utility>
#include <bits/stdc++.h>
//#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;

namespace coup{

    void Assassin::coup(Player p) {
        if (this->_coins < 3){
            throw std::logic_error("not have coins to coup!");
        }
        if (this->_coins >= 7){
            if (p.is_dead()){
                throw std::logic_error("he is already dead");
            }
            p.cahnge2dead();
            this->_coins -= 7;
            this->_last_action = Action::coup;
            this->_Pgame->end_turn();
        }
        if (this->_coins < 7 && this->_coins >= 3){
            if (p.is_dead()){
                throw std::logic_error("he is already dead");
            }
            p.cahnge2dead();
            this->_coins -= 3;
            this->_last_action = Action::Assassin_coup;
            this->_Pgame->end_turn();
        }
    }
}