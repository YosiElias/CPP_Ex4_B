/**
 * Implementation of Captain class.
 *
 * @author Yossi Elias
 * @since 2022
 */


#include <iostream>
#include <stdexcept>
#include <utility>
#include <bits/stdc++.h>
//#include "Player.hpp"
#include "Captain.hpp"
using namespace std;

namespace coup{

    void Captain::steal(Player &p) {
        this->check_is_turn();
        if (this->_coins >= NEED_COUP){
            throw std::logic_error("have to do a coup!");
        }
        if (p.coins() == 0){
            throw std::logic_error("not have 1 coins to be steal");
        }
        p.less_coin();
        this->add_coin();
        this->_steal_sum=1;
        if (p.coins() >= 1) {
            p.less_coin();
            this->add_coin();
            this->_steal_sum=2;
        }
        this->_steal_from = &p;
        this->_last_action = Action::Captain_steal;
        this->Pgame->end_turn();
    }

    void Captain::block(Player &p) {
        if (p.get_action() != Action::Captain_steal){
            throw std::logic_error("did not did Captain_steal");
        }
        if (p.role() != "Captain"){
            throw std::logic_error("p is not a Captain");
        }
        if (this->role() != "Captain"){
            throw std::logic_error("ONLY CHECK");//y0si
        }
        Captain* capt = dynamic_cast<Captain*>(&p);
        Player* steal_from = capt->get_steal_from();
        if (capt->is_dead() or steal_from->is_dead()){
            throw std::logic_error("there is one dead so can't do block");
        }
        if (capt->coins() < 1){
            throw std::logic_error("steal_from not have 2 coins (*need to check what not right)");
        }
        steal_from->add_coin();
        capt->less_coin();
        if (capt->_steal_sum ==2){
            if (capt->coins() <1){
                throw std::logic_error("spend the coin was steal");
            }
            steal_from->add_coin();
            capt->less_coin();
        }
        capt->_last_action = Action::No_action; //already get blocked
    }
}