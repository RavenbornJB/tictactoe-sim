//
// Created by max on 3/13/21.
//

#ifndef YAREMA_TICTACTOE_BOARD_H
#define YAREMA_TICTACTOE_BOARD_H

#include <vector>
using std::vector;
using std::pair;


class Board{
private:
    vector<vector<int>> board{{0, 0, 0},
                              {1, 0, 2},
                              {1, 0, 0}};
    vector<char> symbols{'_', 'X', 'O'};

public:
    void print_board();
    bool check_win(pair<int, int> last_symbol);
    bool check_availability(pair<int, int> coordinates);
    int insert_symbol(pair<int, int> coordinates, int symbol_idx);
    vector<pair<int, int>> get_all_available_cells();
};



#endif //YAREMA_TICTACTOE_BOARD_H
