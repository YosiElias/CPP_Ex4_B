/**
 * Implementation of Contessa class.
 *
 * @author Yossi Elias
 * @since 2022
 */


#include <iostream>
#include <stdexcept>
#include <utility>
#include <bits/stdc++.h>
//#include "Player.hpp"
#include "Contessa.hpp"
using namespace std;

namespace coup{

    void Contessa::block(Player p) {
        p.income();
        this->income();
    }
}