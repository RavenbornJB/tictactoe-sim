#include <iostream>
#include <string>

#include "GameManager.h"


std::pair<std::string, std::string> GameManager::get_player_type_strings() {
    std::cout << "Player types:\n\"h\" - human\n\"ma\" - minimax AI\n\"ra\" = random AI" << std::endl;
    std::cout << "\nPlease enter the types of both players (formatted as \"p1type p2type\"): ";

    std::string s1, s2;
    std::cin >> s1 >> s2;

    while (!(s1 == "h" || s1 == "ma" || s1 == "ra") || !(s2 == "h" || s2 == "ma" || s2 == "ra")) {
        std::cout << "\nPlease enter valid player types! (\"h\", \"ma\", \"ra\")" << std::endl;
        std::cout << "Enter the types of both players (formatted as \"p1type p2type\"): ";
        std::cin >> s1 >> s2;
        std::cout << std::endl;
    }

    return std::make_pair(s1, s2);
}

void GameManager::play() {
    Board game_board;

    auto player_types = get_player_type_strings();
    std::string p1s = player_types.first, p2s = player_types.second;

    if (p1s == "h") HumanPlayer p1;
    else if (p1s == "ma") MinimaxAIPlayer p1;
    else RandomAIPlayer p1;

    if (p2s == "h") HumanPlayer p2;
    else if (p2s == "ma") MinimaxAIPlayer p2;
    else RandomAIPlayer p2;

    // TODO change oop to strategies and only have 1 player class that executes the given strategy
}
