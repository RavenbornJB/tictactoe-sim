#include <iostream>
#include <vector>
#include "Board.h"

using std::vector; using std::cout; using std::endl;
using std::pair;


//class RandomAlgorithm {
//    public:
//        int make_move(Board& board)
//};



int main() {
    Board curr_board;
    curr_board.print_board();
    curr_board.insert_symbol(pair<int, int>{1, 1}, 2);
    curr_board.print_board();
    cout << curr_board.check_win(pair<int, int>{1, 1}) << endl;
    cout << curr_board.check_availability(pair<int, int>{1, 1}) << endl;
//    std::cout << curr_board.board[0] << std::endl;
    return 0;
}
