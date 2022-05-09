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
#include "Assassin.hpp"

using namespace std;

namespace coup{

    void Contessa::block(Player &p) {
        if (p.get_action() != Action::Assassin_coup){
            throw std::logic_error("did not did Assassin_coup");
        }
        if (p.role() != "Assassin"){
            throw std::logic_error("p is not a Assassin");
        }
        Assassin* pAssassin = dynamic_cast<Assassin*>(&p);
        Player* was_killed = pAssassin->get_killed();
        if (!was_killed->is_dead()){
            throw std::logic_error("was_killed not dead (Contessa)");
        }
        this->_Pgame->find_index_of_player(was_killed); //check if the players not completely dead if yes throw an error of players not found
        was_killed->back2life();
        pAssassin->_last_action = Action::No_action; //already get blocked
    }
}