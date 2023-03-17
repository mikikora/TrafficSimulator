//This is a stub class for now that will create maps
//int the future
#pragma once

#include "../core/Board.hpp"

namespace TS::maps
{

class BoardBuilder
{
public:
    BoardBuilder();
    core::Board operator()() const;
};

} // namespace TS::maps
