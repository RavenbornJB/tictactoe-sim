//
// Created by black on 13-Mar-21.
//
#include <iostream>
#include <ctime>

#include "Player.h"


std::pair<int, int> HumanPlayer::get_move(Board &board) {
    int x, y;

    std::cout << "Please enter your move (formatted as \"x y\"): ";
    std::cin >> x >> y; // TODO handle incorrectly formatted inputs (згадати б як)
    std::cout << std::endl;
    auto move = std::make_pair(x, y);
    while (!board.check_availability(move)) {
        std::cout << "Please enter your move (formatted as \"x y\"): ";
        std::cin >> x >> y;
        std::cout << std::endl;
        move = std::make_pair(x, y);
    }
    return move;
}

std::pair<int, int> MinimaxAIPlayer::get_move(Board &board) {
    // TODO implement minimax
    return std::make_pair(1, 1); // center
}

std::pair<int, int> RandomAIPlayer::get_move(Board &board) {
    auto available_cells = board.get_all_available_moves();

    std::srand(time(0)); // uh could be much better
    int idx = std::rand() % available_cells.size();

    return available_cells[idx];
}
