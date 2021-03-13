#include <iostream>
#include <vector>
#include <ctime>

#include "Board.h"
using std::vector; using std::cout; using std::endl;
using std::pair;


class RandomAlgorithm {
    public:
        void make_move(Board& board, int symbol_idx) { // returns a random cell from available ones.
            vector<pair<int, int>> available_cells = board.get_all_available_cells();
            int rand_int = std::rand() % available_cells.size();
            board.insert_symbol(available_cells[rand_int], symbol_idx); // insert symbol into a random available cell
        }
};



int main() {
    srand((int)time(0));
    Board curr_board;
    RandomAlgorithm random_algorithm;

//    cout << curr_board.check_win(pair<int, int>{1, 1}) << endl;
//    cout << curr_board.check_availability(pair<int, int>{1, 1}) << endl;

    curr_board.print_board();
    random_algorithm.make_move(curr_board, 1);
    curr_board.print_board();
    random_algorithm.make_move(curr_board, 1);
    curr_board.print_board();
    random_algorithm.make_move(curr_board, 1);
    curr_board.print_board();
    random_algorithm.make_move(curr_board, 1);
    curr_board.print_board();
    random_algorithm.make_move(curr_board, 1);
    curr_board.print_board();
    random_algorithm.make_move(curr_board, 1);
    curr_board.print_board();

    return 0;
}
