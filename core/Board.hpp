#pragma once

#include <vector>
#include <memory>

#include "MO/ITile.hpp"


namespace TS::core
{

struct Board
{
    using LineT = MO::TileList;
    using BoardT = std::vector<LineT>;
//    Board();
    Board(const BoardT& board);
    BoardT board;
    const unsigned hight;
    const unsigned width;
};
} // namespace TS::core
