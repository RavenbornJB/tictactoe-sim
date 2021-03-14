#include <iostream>
#include <string>

#include "GameManager.h"


std::pair<std::string, std::string> GameManager::get_player_type_strings() {
    std::cout << "Player types:\n\"h\" - human\n\"ma\" - minimax AI\n\"ra\" = random AI" << std::endl;
    std::cout << "\nPlease enter the types of both players (formatted as \"p1type p2type\"): " << std::endl;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    return std::make_pair("1", "1");
}

void GameManager::play() {
    Board game_board;

    auto player_types = get_player_type_strings();
    std::string p1s = player_types.first, p2s = player_types.second;
}
