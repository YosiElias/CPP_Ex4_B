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
        this->_coins = this->_coins +3;
        this->_last_action = Action::Duke_tax;
    }

    void Duke::block(Player p) {
        p.income();
        this->income();
    }
}