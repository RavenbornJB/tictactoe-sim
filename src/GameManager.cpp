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

    Player p1{1, 2, p1s};
    Player p2{2, 1, p2s};

    int turn = 0;
    std::pair<int, int> move;

    for (;;) {
        int moving_player = turn % 2 + 1;

        game_board.print_board();
        std::cout << "Player " << moving_player << " to move." << std::endl;
        if (moving_player == 1) move = p1.get_move(game_board);
        else move = p2.get_move(game_board); // TODO doable in one line by array of the 2 players?


        game_board.insert_symbol(move, moving_player);
        if (game_board.check_win(move)) {
            std::cout << "Player " << turn % 2 + 1 << " wins! Final board:" << std::endl;
            game_board.print_board();
            break;
        }

        ++turn;
        if (turn == 9) {
            std::cout << "Draw!" << std::endl;
            game_board.print_board();
            break;
        }
    }

    // TODO change oop to strategies and only have 1 player class that executes the given strategy
}
