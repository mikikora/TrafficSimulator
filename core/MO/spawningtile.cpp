#include <iostream>

#include "spawningtile.hpp"

namespace TS::core::MO
{
SpawningTile::SpawningTile(const unsigned x, const unsigned y) : ITile(x, y)
{
}

bool SpawningTile::canBeConnected(const Side side) const
{
    return true;
}
} // namespace TS::core::MO
