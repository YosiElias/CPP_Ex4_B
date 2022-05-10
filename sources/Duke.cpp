/**
 * Implementation of Duke class.
 *
 * @author Yossi Elias
 * @since 2022
 */


#include <iostream>
#include <stdexcept>
#include <utility>
#include <bits/stdc++.h>
//#include "Player.hpp"
#include "Duke.hpp"
using namespace std;

namespace coup{


    void Duke::tax() {
        this->check_is_turn();
        if (this->_coins >= NEED_COUP){
            throw std::logic_error("have to do a coup!");
        }
        this->_coins = this->_coins + 3;
        this->_last_action = Action::Duke_tax;
        this->Pgame->end_turn();
    }

    void Duke::block(Player p) {
        if (p.get_action() != Action::foreign_aid){
            throw std::logic_error("did not did foreign_aid");
        }
        if (this->role() != "Duke"){
            throw std::logic_error("ONLY CHECK");
        }
        p.block_foreign_aid();  //take 2 coins from 'p'
    }
}

