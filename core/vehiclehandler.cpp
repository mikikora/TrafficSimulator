#include <memory>
#include <iostream>

#include "vehiclehandler.hpp"
#include "MO/spawningtile.hpp"
#include "MO/car.hpp"

namespace TS::core
{
namespace
{
SpawningTileList getSpawningPoints(const Board board)
{
    SpawningTileList result;
    for (const auto& line : board.board)
    {
        for (const auto& tile : line)
        {
            if (const auto spawningPoint = std::dynamic_pointer_cast<MO::SpawningTile>(tile))
            {
                result.push_back(spawningPoint);
            }
        }
    }
    return result;
}

} // namespace

VehicleHandler::VehicleHandler(const Board board)
    : spawners(getSpawningPoints(board))
{
}

MO::VehicleList VehicleHandler::createVehicles() const
{
    if (const auto& vehicle = createVehicle())
        return {vehicle};

    return {};
}

std::shared_ptr<MO::IVehicle> VehicleHandler::createVehicle() const
{
    const auto chosenSpawner = std::static_pointer_cast<MO::ITile>(spawners[1]);
    if (chosenSpawner->getVehicleDatas().size())
        return nullptr;

    const auto chosenDestination = std::static_pointer_cast<MO::ITile>(spawners[0]);
    const auto vehicle = std::make_shared<MO::Car>(std::vector{chosenDestination}, chosenSpawner);

    spawners[1]->pushVehicle({vehicle, vehicle->getNextPosition(), nullptr});
    return vehicle;
}

} // namespace TS::core
