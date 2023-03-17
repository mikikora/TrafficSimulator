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
    std::shared_ptr<MO::IVehicle> createVehicle() const;

private:
    const SpawningTileList spawners;
//    const SpawningTileList endPoints;
};

} // namespace TS::core
