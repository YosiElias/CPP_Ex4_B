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
#include "Player.hpp"
namespace coup {
    class Player;
//    class Game;

    class Game {

    private:
        std::vector<std::string> _players_names;
        std::vector<Player *> _players;
        unsigned long _turn;
//        int _id;      //Todo: not needed
//        std::vector<int> _players_ID;     //Todo: not needed
//        std::vector<bool> _is_dead;       //Todo: not needed
//        std::string _winner;      //Todo: not needed

    public:
        Game();
        std::string turn();
        Player* turn_pointer();
        std::vector<std::string> players();
        std::string winner();
//        int add_player(const std::string &p);   //Todo: not needed
        int add_player(Player* Pplayer);
        void end_turn(){
            this->_turn = (this->_turn+1)% this->_players_names.size();
        };
        void remove_player(Player * Pp);
        int find_index_of_player(Player* Pp);
//        bool check_player_is_dead(Player *Pp);    //Todo: not needed


    }; // end of class Game
}


//
//#endif //PART_A_GAME_H












////
//// Created by Yossi on 4/28/2022.
////
//
//#ifndef PART_A_GAME_HPP
//#define PART_A_GAME_HPP
//
//#endif //PART_A_GAME_HPP
