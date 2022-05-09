/**
 * Implementation of Ambassador class.
 *
 * @author Yossi Elias
 * @since 2022
 */


#include <iostream>
#include <stdexcept>
#include <utility>
#include <bits/stdc++.h>
//#include "Player.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"

using namespace std;

namespace coup{

    void Ambassador::transfer(Player &from, Player &to) {
        this->check_is_turn();
        if (this->_coins >= 10){
            throw std::logic_error("have to do a coup!");
        }
        if (from.coins()<1){
            throw std::logic_error("not have coin to give");
        }
        from.less_coin();
        to.add_coin();
        this->_last_action = Action::Ambassador_transfer;
        this->_Pgame->end_turn();
    }

    void Ambassador::block(Player &p) {
        if (p.get_action() != Action::Captain_steal){
            throw std::logic_error("did not did Captain_steal");
        }
        if (p.role() != "Captain"){
            throw std::logic_error("p is not a Captain");
        }
        Captain* capt = dynamic_cast<Captain*>(&p);
        Player* steal_from = capt->get_steal_from();
        if (capt->is_dead() or steal_from->is_dead()){
            throw std::logic_error("there is one dead so can't do block");
        }
        if (capt->coins() < 2){
            throw std::logic_error("steal_from not have 2 coins (*need to check what not right)");
        }
        steal_from->add_coin();
        steal_from->add_coin();
        capt->less_coin();
        capt->less_coin();
        capt->_last_action = Action::No_action; //already get blocked
    }
}