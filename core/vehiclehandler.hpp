#pragma once

#include <vector>
#include <memory>

#include "MO/IVehicle.hpp"
#include "MO/spawningtile.hpp"
#include "Board.hpp"

namespace TS::core
{
using SpawningTileList = std::vector<std::shared_ptr<MO::SpawningTile>>;
class VehicleHandler
{
public:
    VehicleHandler(const Board board);
    MO::VehicleList createVehicles() const;

private:
    const SpawningTileList spawners;

    std::shared_ptr<MO::IVehicle> createVehicle() const;
//    const SpawningTileList endPoints;
};

} // namespace TS::core
