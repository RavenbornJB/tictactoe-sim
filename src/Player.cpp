//
// Created by black on 13-Mar-21.
//
#include <iostream>
#include <ctime>
#include <climits>

#include "Player.h"

Player::Player(int player_symbol_idx, int opponent_symbol_idx) {
    this->player_symbol_idx = player_symbol_idx;
    this->opponent_symbol_idx = opponent_symbol_idx;
}

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
    auto free_cells = board.get_all_available_moves();

    std::pair<int, int> best_move = free_cells[0];
    int evaluation_cost = INT_MIN;
    for (auto move: free_cells){
        int move_cost = evaluate_move(board, move, player_symbol_idx);

        if (evaluation_cost < move_cost) {
            best_move = move;
            evaluation_cost = move_cost;
        }
    }
    std::cout << "EVALUATION for the best move:: " << evaluation_cost << std::endl;
    return best_move;
}

int MinimaxAIPlayer::evaluate_move(Board &board, std::pair<int, int> coordinates, int symbol_idx) {
    // making a move first:
    board.insert_symbol(coordinates, symbol_idx);
    auto available_cells = board.get_all_available_moves();

    if (board.check_win(coordinates)) {
        board.reset_symbol(coordinates);
        if (symbol_idx == player_symbol_idx)
            return (int)available_cells.size() + 1;
        return (-1) * (int)available_cells.size() + 1;
    }

    if (available_cells.empty()) {
        board.reset_symbol(coordinates);
        return 0;
    }

    symbol_idx = 1  + (symbol_idx % 2); // changing the symbol to opposite

    if (symbol_idx == player_symbol_idx) {
        int best_move_value = INT_MIN;
     for (auto move: available_cells){
            int move_score = evaluate_move(board, move, player_symbol_idx);
            best_move_value = std::max(move_score, best_move_value);
        }

        board.reset_symbol(coordinates); // clearing the board afterwards, so it is the same as before calling this func
        return best_move_value;
    }
    else {
        int best_move_value = INT_MAX;
        for (auto move: available_cells){
            int move_score = evaluate_move(board, move, opponent_symbol_idx);
            best_move_value = std::min(move_score, best_move_value);
        }

        board.reset_symbol(coordinates); // clearing the board afterwards, so it is the same as before calling this func
        return best_move_value;
    }
}

std::pair<int, int> RandomAIPlayer::get_move(Board &board) {
    auto available_cells = board.get_all_available_moves();

    std::srand(time(0)); // uh could be much better
    int idx = std::rand() % available_cells.size();

    return available_cells[idx];
}

