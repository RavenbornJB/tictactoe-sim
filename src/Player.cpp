//
// Created by black on 13-Mar-21.
//
#include <iostream>
#include <ctime>
#include <climits>

#include "Player.h"

Player::Player(int player_symbol_idx, int opponent_symbol_idx, std::string &strat) {
    this->player_symbol_idx = player_symbol_idx;
    this->opponent_symbol_idx = opponent_symbol_idx;
    this->strat = strat;
}

std::pair<int, int> Player::get_move(Board &board) {
    if (strat == "h") return human_get_move(board);
    if (strat == "ma") return minimax_get_move(board);
    if (strat == "ra") return random_get_move(board);
}

std::pair<int, int> Player::human_get_move(Board &board) {
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


std::pair<int, int> Player::minimax_get_move(Board &board) {
    auto free_cells = board.get_all_available_moves();
    std::pair<int, int> best_move = free_cells[0];
    int evaluation_cost = INT_MIN;
    for (auto move: free_cells){
        int move_cost = minimax_evaluate_move(board, move, opponent_symbol_idx, false);
        if (move.second == 0) {
            std::cout << move.first << "---" << move.second << std::endl;
            int x = minimax_evaluate_move(board, move, player_symbol_idx, false);
            std::cout << move_cost << " --cost" << std::endl;
        }
//        if (move.second == 1) {
//            std::cout << move.first << "---" << move.second << std::endl;
//            int x = evaluate_move(board, move, player_symbol_idx, false);
//            std::cout << move_cost << " --cost" << std::endl;
//        }
//        if (move_cost == 4)
//            std::cout << move.first << "-" << move.second << std::endl;
        if (evaluation_cost < move_cost) {
            best_move = move;
            evaluation_cost = move_cost;
        }
    }
    std::cout << "EVALUATION for the best move:: " << evaluation_cost << std::endl;
    return best_move;
}

int Player::minimax_evaluate_move(Board &board, std::pair<int, int> coordinates, int symbol_idx, bool is_maximizer) {
    // making a move first:
    board.insert_symbol(coordinates, symbol_idx);


    auto available_cells = board.get_all_available_moves();
    int depth = 9;
    depth -= available_cells.size(); // how deep in the tree are we


    // checking if it's a win firstly:
    if (board.check_win(coordinates)) {
        board.reset_symbol(coordinates);

        if (symbol_idx == player_symbol_idx)
            return -depth;
        return depth;
//        board.reset_symbol(coordinates);
//        return is_maximizer ? -depth : depth;
    }
    // if it's not a winning situation, and there are no available cells, then it's a draw
    if (available_cells.empty()) {
        board.reset_symbol(coordinates);
        return 0;
    }

    if (is_maximizer) {
//        int best_move_value = INT_MIN;
        int best_move_value = -1000;
        for (auto move: available_cells){
            int move_score = minimax_evaluate_move(board, move, 1  + (symbol_idx % 2), !is_maximizer);
            best_move_value = std::max(move_score, best_move_value);
        }

        board.reset_symbol(coordinates); // clearing the board afterwards, so it is the same as before calling this func
        return best_move_value;
    }
    else {
//        int best_move_value = INT_MAX;
        int best_move_value = 1000;
        for (auto move: available_cells){
            int move_score = minimax_evaluate_move(board, move, (symbol_idx + 1) % 2, !is_maximizer);
            best_move_value = std::min(move_score, best_move_value);
        }

        board.reset_symbol(coordinates); // clearing the board afterwards, so it is the same as before calling this func
        return best_move_value;
    }
}

std::pair<int, int> Player::random_get_move(Board &board) {
    auto available_cells = board.get_all_available_moves();

    std::srand(time(0)); // uh could be much better
    int idx = std::rand() % available_cells.size();

    return available_cells[idx];
}

