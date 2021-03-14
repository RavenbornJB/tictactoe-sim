//
// Created by black on 13-Mar-21.
//

#ifndef TICTACTOE_SIM_PLAYER_H
#define TICTACTOE_SIM_PLAYER_H

#include <ctime>

#include "Board.h"

class Player {
    public:
        int player_symbol_idx;
        int opponent_symbol_idx;
        virtual std::pair<int, int> get_move(Board &board) = 0;
        Player(int player_symbol_idx, int opponent_symbol_idx);
};

class HumanPlayer: public Player {
    public:
        std::pair<int, int> get_move(Board &board) override;
        HumanPlayer(int player_symbol_idx, int opponent_symbol_idx) : Player(player_symbol_idx, opponent_symbol_idx){
        }
};

class MinimaxAIPlayer: public Player {
    private:
//        int evaluate_move(Board &board, std::pair<int, int> coordinates, int symbol_idx, bool is_maximizer);
    public:
        int evaluate_move(Board &board, std::pair<int, int> coordinates, int symbol_idx, bool is_maximizer);
        std::pair<int, int> get_move(Board &board) override;
        MinimaxAIPlayer(int player_symbol_idx, int opponent_symbol_idx) : Player(player_symbol_idx, opponent_symbol_idx){
        }


};

class RandomAIPlayer: public Player {
    public:
        std::pair<int, int> get_move(Board &board) override;
        RandomAIPlayer(int player_symbol_idx, int opponent_symbol_idx) : Player(player_symbol_idx, opponent_symbol_idx){
        }
};

#endif //TICTACTOE_SIM_PLAYER_H
