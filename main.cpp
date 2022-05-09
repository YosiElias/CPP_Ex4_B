#include <iostream>

//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
/**
 * Demo program for Coup exercise
 *
 * @author: Tal Zichlinsky
 * @since: 2022-02
 */

#include "sources/Player.hpp"
#include "sources/Duke.hpp"
#include "sources/Assassin.hpp"
#include "sources/Ambassador.hpp"
#include "sources/Captain.hpp"
#include "sources/Contessa.hpp"
#include "sources/Game.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {
    Game scenario1{};

    Duke PlayerONE{scenario1, "Player ONE"};
    Assassin PlayerTWO{scenario1, "Player TWO"};
    Duke PlayerTHREE{scenario1, "Player THREE"};
    Contessa PlayerFOUR{scenario1, "Player FOUR"};
    vector<Player*> Players = {&PlayerONE, &PlayerTWO, &PlayerTHREE, &PlayerFOUR};

//    CHECK_EQ(PlayerTWO.role(), "Assassin");
//    CHECK_EQ(PlayerONE.role(), PlayerTHREE.role()); // Two players can have the same role

//    CHECK_EQ(scenario1.players().size(), 4);
    (PlayerONE.income());
//    CHECK_THROWS(PlayerTHREE.income()); // Its Player Two's turn

//    CHECK_EQ(PlayerONE.coins(), 1);
//    CHECK_EQ(PlayerTHREE.coins(), 0);
    for (size_t i = 1; i < Players.size(); i++)
    {
        (Players.at(i)->income());
    }
    for (size_t j = 0; j < 2; j++)
    {
        for (size_t i = 0; i < Players.size(); i++)
        {
            (Players.at(i)->income());
        }
    }

    for (size_t i = 0; i < Players.size(); i++)
    {
        if(Players.at(i)->coins() != 3)
            cerr <<  Players.at(i)->coins() << endl; // everyone has 3 coins
    }

//    CHECK_THROWS(PlayerONE.coup(PlayerTWO)); // Player ONE doesn't have enough coins to coup
    PlayerONE.tax();
    PlayerTWO.coup(PlayerONE); // Player TWO is an assassin and can coup with 3 coins
    if(scenario1.players().size() != 3)
        cout <<  scenario1.players().size() << endl;; // Player ONE is out of the game
//    Game game_1{};
//
//    /* This player drew the "Duke" card, his name is Moshe
//    and he is a player in game_1 */
//    Duke duke{game_1, "Moshe"};
//    Assassin assassin{game_1, "Yossi"};
//    Ambassador ambassador{game_1, "Meirav"};
//    Captain captain{game_1, "Reut"};
//    Contessa contessa{game_1, "Gilad"};
//
//    vector<string> players = game_1.players();
//
//    /*
//        prints:
//        Moshe
//        Yossi
//        Meirav
//        Reut
//        Gilad
//    */
//    for(string name : players){
//        cout << name << endl;
//    }
//
//    // prints Moshe
//    cout << game_1.turn() << endl;
//
//    // throws no exceptions
//    duke.income();
//    assassin.income();
//    ambassador.income();
//    captain.income();
//    contessa.income();
//
//    // throws exception, it is duke's turn now
//    try{
//        assassin.income();
//    }catch (const std::exception &e){
//        std::cerr << e.what() << '\n';
//    }
//    duke.income();
//    assassin.foreign_aid();
//
//    // throws exception, the last operation duke performed
//    // is Income, which cannot be blocked by any role
//    try{
//        captain.block(duke);
//    }catch (const std::exception &e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//
//    cout << duke.coins() << endl; // prints 2
//    cout << assassin.coins() << endl; // prints 3
//
//    // throws exception, the last operation assassin performed
//    // is foreign aid, which cannot be blocked by contessa
//    try{
//        contessa.block(assassin);
//    }catch (const std::exception &e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//
//    duke.block(assassin);
//    cout << assassin.coins() << endl; // prints 1
//
//    ambassador.transfer(duke, assassin); //transfers 1 coin from duke to assassin
//    captain.foreign_aid();
//    contessa.foreign_aid();
//
//    duke.tax();
//    assassin.income();
//    ambassador.foreign_aid();
//    captain.steal(contessa);
//    contessa.foreign_aid();
//
//    duke.tax();
//    // no exception, assassin can coup with only 3 coins
//    assassin.coup(duke);
//
//    players = game_1.players();
//    /*
//        prints:
//        Yossi
//        Meirav
//        Reut
//        Gilad
//    */
//    for (string name : players)
//    {
//        cout << name << endl;
//    }
//
//    contessa.block(assassin);
//
//    players = game_1.players();
//    /*
//        prints:
//        Moshe
//        Yossi
//        Meirav
//        Reut
//        Gilad
//    */
//    for (string name : players)
//    {
//        cout << name << endl;
//    }
}
