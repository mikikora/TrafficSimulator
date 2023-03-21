#include "Board.hpp"
#include "MO/IVehicle.hpp"

#include <iostream>
#include <string>
#include <sstream>

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

void Board::print() const
{
    std::stringstream ss;
    for (const auto& v : board)
    {
        for (const auto& t : v)
        {
            ss << "[ " << t->classname() << " ";
            for (const auto& data : t->getVehicleDatas())
            {
                ss << data.vehicle->classname() << " ";
            }
            ss << "] ";
        }
        ss << std::endl;
    }
    std::cout << ss.str() << std::endl;
}
} // namespace TS::core
