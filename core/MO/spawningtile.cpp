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

void SpawningTile::pushVehicle(const VehicleData& v)
{
    if (vehicleDatas.size())
    {
        std::cerr << "This tile is already occupied" << std::endl;
    }
    else
    {
        ITile::pushVehicle(v);
    }
}
} // namespace TS::core::MO
