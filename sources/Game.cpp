/**
 * Implementation of Game class.
 *
 * @author Yossi Elias
 * @since 2022
 */


#include <iostream>
#include <stdexcept>
#include "Game.hpp"
using namespace std;

namespace coup{

    Game::Game() {
        this->_players_names = {};
        this->_players = {};
//        this->_players_ID = {};
//        this->_is_dead = {};
        this->_turn = 0;
//        this->_id = 0;
    }

    string Game::turn() {
        if (this->_players_names.size() == 0){
            throw logic_error("no players");
        }
        while (this->_players.at(this->_turn)->is_dead()){   //remove dead players and loop on it
            this->remove_player(this->_players.at(this->_turn));
            this->end_turn();
        }
        return this->_players_names.at(this->_turn);
    }
    Player* Game::turn_pointer() {
        if (this->_players.size()==0){
            throw logic_error("no players");
        }
        while (this->_players.at(this->_turn)->is_dead()){    //remove dead players and loop on it
            this->remove_player(this->_players.at(this->_turn));
            this->end_turn();
        }
        return this->_players.at(this->_turn);
    }
    vector<string> Game::players() {
        vector<string> ans = {};
        for (size_t i = 0; i < players().size(); ++i) {
            if (!this->_players.at(i)->is_dead()){
                ans.push_back(this->_players.at(i)->get_name());
            }
        }
        return ans;
    }

    string Game::winner() {
        int players_life = 0;
        if (this->_players_names.size() != 1){
            for (size_t i = 0; i < this->_players.size(); ++i) {    //check if there is dead players on the list
                if (!this->_players.at(i)->is_dead()){
                    players_life++;
                }
            }
            if (players_life > 1) {
                throw logic_error("the game not over");
            }
        }
        return this->_players_names.at(0);
    }

//    int Game::add_player(const string &p) {   //Todo: not needed
//        int id = this->_id;
//        this->_id++;
//        this->_players_names.push_back(p);
//        this->_players_ID.push_back(id);
//        this->_is_dead.push_back(false);
//        return id;
//    }

    void Game::remove_player(Player *Pp) {
        int index = find_index_of_player(Pp);
        this->_players_names.erase(this->_players_names.begin() + index);
        this->_players.erase(this->_players.begin() + index);
//        this->_is_dead.erase(this->_is_dead.begin() + index);
    }

    int Game::find_index_of_player(Player *Pp) {
        size_t index=9999;
        for (size_t i = 0; i < this->_players.size(); ++i) {
            if (this->_players.at(i) == Pp){
                index = i;
            }
        }
        if (index == 9999){
            throw std::runtime_error("player not found");
        }
        return index;
    }

//    bool Game::check_player_is_dead(Player *Pp) { //Todo: not needed
//        if (Pp->is_dead()){
//            return true;
//        }
//        return false;
//    }

    void Game::add_player(Player *Pplayer) {
        this->_players.push_back(Pplayer);
//        int id = this->_id;
//        this->_id++;
        this->_players_names.push_back(Pplayer->get_name());
//        this->_players_ID.push_back(id);
//        this->_is_dead.push_back(false);
    }

}