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

    void Captain::steal(Player p) {
        p.income();
        this->income();
    }

    void Captain::block(Player p) {
        p.income();
        this->income();
    }
}