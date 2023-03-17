#pragma once

#include "../MO/ITile.hpp"

namespace TS::core::algorithm
{
class PathFinder
{
public:
    PathFinder();
    MO::TileList getPath(
            const MO::Tile src,
            const MO::Tile dest) const;
};

} // namespace TS::core::algorithm
