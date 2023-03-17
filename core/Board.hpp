#pragma once

#include <vector>
#include <memory>

#include "MO/ITile.hpp"


namespace TS::core
{

struct Board
{
    using LineT = std::vector<std::shared_ptr<MO::ITile>>;
    using BoardT = std::vector<LineT>;
//    Board();
    Board(const BoardT& board);
    BoardT board;
};
} // namespace TS::core
