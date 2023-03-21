#pragma once

#include "../MO/ITile.hpp"

namespace TS::core::algorithm
{
class PathFinder
{
public:
//    PathFinder();
    static MO::TileList getPath(
            const MO::Tile src,
            const MO::Tile dest);
};

} // namespace TS::core::algorithm
