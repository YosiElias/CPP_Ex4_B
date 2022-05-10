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
    Game scenario2{};

    Duke PlayerONE{scenario2, "Player ONE"};
    Assassin PlayerTWO{scenario2, "Player TWO"};
    Captain PlayerTHREE{scenario2, "Player THREE"};
    vector<Player*> Players = {&PlayerONE, &PlayerTWO, &PlayerTHREE};

    //(PlayerTHREE.role(), "Captain");

    //(scenario2.players().size(), 3);
    (PlayerONE.tax()); // 3 (COINS)
    //(PlayerTHREE.income());  // Player TWO's turn. Not THREE's
    (PlayerTWO.income());// 1 (COINS)
    //(PlayerTWO.coins(), 1);
    (PlayerTHREE.steal(PlayerTWO));  // THREE 1, TWO 0 (COINS)
    //(PlayerONE.coins(), 3);
    //(PlayerTHREE.coins(), 1);
    //(PlayerTWO.coins(), 0);
    for (size_t j = 0; j < 5; j++)
    {
        for (size_t i = 0; i < Players.size(); i++)
        {
            (Players.at(i)->income()); // ADD 5 COINS TO EACH PLAYER
        }
    }
    //(PlayerTHREE.coins(), 6);
    //(PlayerTWO.coins(), 5);
    //(PlayerONE.coins(), 8);
    (PlayerONE.coup(PlayerTHREE));
    //(scenario2.winner()); // Game not over
    //(PlayerONE.coins(), 1);
    //(scenario2.players().size(), 2);
    //(PlayerTWO.coup(PlayerTHREE)); // PLAYER THREE ALREADY DEAD
    //(scenario2.players().size(), 2);
    (PlayerTWO.coup(PlayerONE));
    //(scenario2.players().size(), 1);
    //(PlayerONE.coup(PlayerTWO)); // PLAYER ONE ALREADY DEAD
    //(scenario2.winner(), "Player TWO");


    cout << "END" << endl;
}
