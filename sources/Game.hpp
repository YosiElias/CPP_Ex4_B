//
// Created by Yossi on 4/28/2022.
//

//#ifndef PART_A_GAME_H
//#define PART_A_GAME_H

#pragma once
/**
 * Header file for the Player class.
 *
 * @author Yossi Elias
 * @since 2022
 */
//#include "Player.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include "Player.hpp"
namespace coup {
    class Player;
//    class Game;

    class Game {

    private:
        std::vector<std::string> _players_names;
        std::vector<Player *> _players;
        unsigned long _turn;
        const size_t INF = 9999;
        const size_t MAX_PLAYERS = 6;


    public:
        Game();
        ~Game() = default;
        std::string turn();
        Player* turn_pointer();
        std::vector<std::string> players();
        std::string winner();
        void add_player(Player &Pplayer);
        void end_turn(){
            this->_turn = (this->_turn+1)% this->_players_names.size();
        };
        void remove_player(Player &Pp);
        int find_index_of_player(Player &Pp);
        std::vector<Player *> get_Pp(){return this->_players;};
        bool start = false;


    }; // end of class Game
}


//
//#endif //PART_A_GAME_H












////
//// Created by Yossi on 4/28/2022.
////
//
//#ifndef PART_A_GAME_HPP
//#define PART_A_GAME_HPP  //deep c0py
//
//#endif //PART_A_GAME_HPP
