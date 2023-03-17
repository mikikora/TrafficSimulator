#include "Board.hpp"

namespace TS::core
{
//Board::Board()
//{
//}

Board::Board(const BoardT& board)
    : board(board)
    , hight(board.size())
    , width(board.size() ? board[0].size() : 0u)
{}
} // namespace TS::core
