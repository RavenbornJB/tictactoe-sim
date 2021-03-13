//
// Created by black on 13-Mar-21.
//
#include <iostream>
#include <ctime>

#include "Player.h"


std::pair<int, int> HumanPlayer::get_move(Board &board) {
    std::string x_ipt, y_ipt;
    int x, y;

    while (true) {
        std::cout << "Please enter coordinates for your next move (formatted as \"x y\", 0 <= x, y <= 2): ";
        std::cin >> x_ipt >> y_ipt; // TODO handle incorrectly formatted inputs (згадати б як)
        if (x_ipt.size() == 1 | y_ipt.size() == 1){
            if (std::isdigit(x_ipt[0]) && std::isdigit(y_ipt[0])){
                x = std::stoi(x_ipt);
                y = std::stoi(y_ipt);
                if ((0 <= x) && (x <= 2) && (0 <= y) && (y <= 2)){
                    auto move = std::make_pair(x, y);
                    if (board.check_availability(move)) {
                        return move; // that's a valid move
                    } else{
                        std::cout << std::endl << "That cell is occupied, please, choose a spare one!" << std::endl;
                        continue;
                    }
                }
            }
        }
        std::cout << std::endl << "Please, write the proper input from numbers 0, 1, and 2, separated by spaces" << std::endl;
    }
}

std::pair<int, int> MinimaxAIPlayer::get_move(Board &board) {
    // TODO implement minimax
    // я можу зробити
    return std::make_pair(1, 1); // center
}

std::pair<int, int> RandomAIPlayer::get_move(Board &board) {
    auto available_cells = board.get_all_available_moves();

    std::srand(time(0)); // uh could be much better
    int idx = std::rand() % available_cells.size();

    return available_cells[idx];
}
