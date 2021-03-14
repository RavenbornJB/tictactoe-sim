#ifndef TICTACTOE_SIM_PLAYER_H
#define TICTACTOE_SIM_PLAYER_H

#include <ctime>
#include <string>

#include "Board.h"

class Player {
    private:
        int player_symbol_idx;
        int opponent_symbol_idx;
        std::string strat;

        std::pair<int, int> human_get_move(Board &board);
        std::pair<int, int> minimax_get_move(Board &board);
        std::pair<int, int> random_get_move(Board &board);
        int minimax_evaluate_move(Board &board, std::pair<int, int> coordinates, int symbol_idx);

    public:
        Player(int player_symbol_idx, int opponent_symbol_idx, std::string &strat);
        std::pair<int, int> get_move(Board &board);
};

#endif //TICTACTOE_SIM_PLAYER_H
