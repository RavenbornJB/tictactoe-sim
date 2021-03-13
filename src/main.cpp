#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <ctime>
=======

#include "Board.h"
#include "Player.h"
>>>>>>> c32c806931901467c16b1942927f94a1d810d6ae

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
<<<<<<< HEAD
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
=======
    auto p1 = *(new RandomAIPlayer); // TODO like an enum 0 - HumanPlayer, 1 - MinimaxAIPlayer, 2 - RandomAIPlayer
    auto p2 = *(new HumanPlayer);
    std::pair<int, int> move;

    curr_board.insert_symbol(pair<int, int>{1, 1}, 2);

    curr_board.print_board();
    move = p1.get_move(curr_board);
    cout << "Player 1 makes their move on the position (" << move.first << "," << move.second << ")" << endl;
    curr_board.insert_symbol(move, 1); // nu tam idx pleera

    curr_board.print_board();
    move = p2.get_move(curr_board);
    cout << "Player 2 makes their move on the position (" << move.first << "," << move.second << ")" << endl;
    curr_board.insert_symbol(move, 2); // nu tam idx pleera

    curr_board.print_board(); // state after 2 moves, check for in between
>>>>>>> c32c806931901467c16b1942927f94a1d810d6ae

    return 0;
}
