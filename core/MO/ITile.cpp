#include <iostream>

#include "ITile.hpp"

namespace TS::core::MO
{
ITile::ITile(const unsigned x, const unsigned y) : x(x), y(y) {}

void ITile::pushVehicle(const VehicleData& v) {vehicleDatas.push_back(v);}

std::vector<VehicleData> ITile::getVehicleDatas() const {return vehicleDatas;}

VehicleData ITile::freeTile(const std::shared_ptr<IVehicle> vehicle)
{
    for (auto it = vehicleDatas.begin(); it != vehicleDatas.end(); ++it)
    {
        if (it->vehicle == vehicle)
        {
            vehicleDatas.erase(it);
            return *it;
        }
    }
    std::cerr << "No vehicle found on the tile" << std::endl;
    return VehicleData{};
}

void ITile::connectEndpoint(const Side side, const Tile tile)
{
    if (!canBeConnected(side))
    {
        std::cerr << "Can't connect to this side" << std::endl;
        return;
    }
    endpoints[side] = tile;
}

} // namespace TS::core::MO
