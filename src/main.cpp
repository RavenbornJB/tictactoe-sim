#include <iostream>
#include <vector>

#include "Board.h"
#include "Player.h"

using std::vector; using std::cout; using std::endl;
using std::pair;



int main() {
    Board curr_board;
    auto p0 = *(new HumanPlayer(2, 1));
    auto p1 = *(new MinimaxAIPlayer(1, 2)); // TODO like an enum 0 - HumanPlayer, 1 - MinimaxAIPlayer, 2 - RandomAIPlayer
    auto p2 = *(new RandomAIPlayer(1, 2)); // TODO like an enum 0 - HumanPlayer, 1 - MinimaxAIPlayer, 2 - RandomAIPlayer
    std::pair<int, int> move;


    curr_board.print_board();
    auto bestMove = p1.get_move(curr_board);
    cout << bestMove.first << "-" << bestMove.second << endl;
    curr_board.insert_symbol(bestMove, 1);

    curr_board.print_board();
//    cout << p1.evaluate_move(curr_board, std::make_pair(1, 1), 1, true) << endl;

//    move = p1.get_move(curr_board);
//    cout << "Player 1 makes their move on the position (" << move.first << "," << move.second << ")" << endl;
//    curr_board.insert_symbol(move, 1); // nu tam idx pleera
//
//    curr_board.print_board();
//    move = p2.get_move(curr_board);
//    cout << "Player 2 makes their move on the position (" << move.first << "," << move.second << ")" << endl;
//    curr_board.insert_symbol(move, 2); // nu tam idx pleera
//
//    curr_board.print_board(); // state after 2 moves, check for in between

    return 0;
}
