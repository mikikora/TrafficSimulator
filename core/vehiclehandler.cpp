#include <memory>

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

std::shared_ptr<MO::IVehicle> VehicleHandler::createVehicle() const
{
    const auto chosenSpawner = spawners[1];
    const auto chosenDestination = spawners[0];
    const auto vehicle = std::make_shared<MO::Car>(std::vector{chosenDestination}, chosenSpawner);
    return vehicle;
}

} // namespace TS::core
