//
// Created by black on 13-Mar-21.
//

#ifndef TICTACTOE_SIM_PLAYER_H
#define TICTACTOE_SIM_PLAYER_H

#include <ctime>

#include "Board.h"

class Player {
    public:
        virtual std::pair<int, int> get_move(Board &board) = 0;
};

class HumanPlayer: public Player {
    public:
        std::pair<int, int> get_move(Board &board) override;
};

class MinimaxAIPlayer: public Player {
    public:
        std::pair<int, int> get_move(Board &board) override;
};

class RandomAIPlayer: public Player {
    public:
        std::pair<int, int> get_move(Board &board) override;
};

#endif //TICTACTOE_SIM_PLAYER_H
