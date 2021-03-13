#include <iostream>
#include <vector>

#include "Board.h"
#include "Player.h"

using std::vector; using std::cout; using std::endl;
using std::pair;


//class RandomAlgorithm {
//    public:
//        int make_move(Board& board)
//};



int main() {
    Board curr_board;
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

    return 0;
}
