#ifndef TICTACTOE_SIM_GAMEMANAGER_H
#define TICTACTOE_SIM_GAMEMANAGER_H

#include <string>

#include "Board.h"
#include "Player.h"

class GameManager {
private:
    static std::pair<std::string, std::string> get_player_type_strings();

public:
    void play();
};


#endif //TICTACTOE_SIM_GAMEMANAGER_H
