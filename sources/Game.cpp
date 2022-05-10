/**
 * Implementation of Game class.
 *
 * @author Yossi Elias
 * @since 2022
 */


//#include <iostream>
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
        if (this->_players_names.empty()){
            throw logic_error("no players");
        }
        while (this->_players.at(this->_turn)->is_dead()){   //remove dead players and loop on it
//            this->remove_player(*this->_players.at(this->_turn));
            this->end_turn();
        }
        return this->_players_names.at(this->_turn);
    }
    Player* Game::turn_pointer() {
        if (this->_players.empty()){
            throw logic_error("no players");
        }
        while (this->_players.at(this->_turn)->is_dead()){    //remove dead players and loop on it
//            this->remove_player(*this->_players.at(this->_turn));
            this->end_turn();
        }
        return this->_players.at(this->_turn);
    }
    vector<string> Game::players() {
        vector<string> ans = {};
        for (auto & _player : this->_players) {
            if (!_player->is_dead()){
                ans.push_back(_player->get_name());
            }
        }
        return ans;
    }

    string Game::winner() {
        if (!this->start){
            throw logic_error("the game not started!");
        }
        int players_life = 0;
        string win;
        if (this->_players_names.size() != 1){
            for (size_t i = 0; i < this->_players.size(); ++i) {    //check if there is dead players on the list
                if (!this->_players.at(i)->is_dead()){
                    players_life++;
                    win = this->_players.at(i)->get_name();
                }
            }
            if (players_life > 1) {
                throw logic_error("the game not over");
            }
        }
        return win;
    }

//    int Game::add_player(const string &p) {   //Todo: not needed
//        int id = this->_id;
//        this->_id++;
//        this->_players_names.push_back(p);
//        this->_players_ID.push_back(id);
//        this->_is_dead.push_back(false);
//        return id;
//    }

    void Game::remove_player(Player &Pp) {
        int index = find_index_of_player(Pp);
        this->_players_names.erase(this->_players_names.begin() + index);
        this->_players.erase(this->_players.begin() + index);
//        delete this->_players.at((size_t)index);    //Todo: check deleted
//        this->_is_dead.erase(this->_is_dead.begin() + index);
    }

    int Game::find_index_of_player(Player &Pp) {
        size_t index=INF;
        for (size_t i = 0; i < this->_players.size(); ++i) {
            if (this->_players.at(i) == &Pp){
                index = i;
            }
        }
        if (index == INF){
            throw std::runtime_error("player not found");
        }
        return (int)index;
    }

//    bool Game::check_player_is_dead(Player *Pp) { //Todo: not needed
//        if (Pp->is_dead()){
//            return true;
//        }
//        return false;
//    }

    void Game::add_player(Player & Pplayer) {
        if (this->get_Pp().size() >= MAX_PLAYERS){
            throw std::logic_error("more then 6!");
        }
        if (this->start){
            throw std::logic_error("game was started!");
        }
        this->_players.push_back(&Pplayer);
        this->_players_names.push_back(Pplayer.get_name());
//        int id = this->_id;
//        this->_id++;
//        this->_players_ID.push_back(id);
//        this->_is_dead.push_back(false);
    }

//    Game::~Game() {
////        for (size_t i = 0; i < this->_players.size(); ++i) {
////            free( this->_players.at(i));
////        }
////        Game* pTemp = this;
//        for (Player* p : this->_players)
//            delete p;
//        cout << "delete p for Game" << endl;
//        this->_players.clear();
//        this->_players_names.clear();
////        delete pTemp;
//
//    }

}