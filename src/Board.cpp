//
// Created by max on 3/13/21.
//
#include <iostream>
#include <vector>
#include "Board.h"

using std::vector; using std::cout; using std::endl;
using std::pair;



void Board::print_board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "|" << symbols[board[i][j]];
        }
        cout <<  '|' << endl;
    }
    cout << endl;
}

bool Board::check_win(pair<int, int> last_symbol) { // returns 1 if it is a winning move, 0 otherwise
    int column = last_symbol.first;
    int row = last_symbol.second;
    // checking horizontal:
    int win = 1;
    for (int i = 0; i < 3; ++i) {
        if (board[column][i] != board[column][row])
            win = 0;
    }
    if (win)
        return true;
    // checking vertical:
    win = 1;
    for (int i = 0; i < 3; ++i) {
        if (board[i][row] != board[column][row])
            win = 0;
    }
    if (win)
        return true;

    // checking diagonal if it's (0,0), (1,1), or (2,2):
    if (column == row){
        win = 1;
        for (int i = 0; i < 3; ++i) {
            if (board[i][i] != board[column][row])
                win = 0;
        }
        if (win)
            return true;
    }
    // checking diagonal if it's (2,0), (1,1), or (2,0):
    if (column == 2 - row){
        win = 1;
        for (int i = 0; i < 3; ++i) {
            if (board[2 - i][i] != board[column][row])
                win = 0;
        }
        if (win)
            return true;
    }
    return false;
}
bool Board::check_availability(pair<int, int> coordinates){
    return board[coordinates.first][coordinates.second] == 0;
}
int Board::insert_symbol(pair<int, int> coordinates, int symbol_idx){
    if (check_availability(coordinates)){
        board[coordinates.first][coordinates.second] = symbol_idx;
        return 0;
    }else{
        // TODO handle this error somewhere
        return 1;
    }
}
vector<pair<int, int>> Board::get_all_available_cells() {
    vector<pair<int, int>> result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            pair<int, int> point {i, j};
            if (check_availability(point))
                result.push_back(point);
        }
    }
    return result;
}
