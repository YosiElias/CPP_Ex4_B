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
using namespace std;

namespace coup{

    void Ambassador::transfer(Player from, Player to) {
        from.income();
        to.income();
        this->income();
    }

    void Ambassador::block(Player p) {
        p.income();
        this->income();
    }
}