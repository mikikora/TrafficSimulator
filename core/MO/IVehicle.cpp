#include "IVehicle.hpp"
#include "ITile.hpp"
#include "../algorithm/pathfinder.hpp"

#include <iostream>

namespace TS::core::MO
{
IVehicle::IVehicle(const std::vector<std::shared_ptr<ITile>>& destinations,
                   const std::shared_ptr<ITile> currentPosition)
    : destinations(destinations)
    , currentPosition(currentPosition)
    , path(algorithm::PathFinder::getPath(currentPosition, destinations[0]))
    , movePossibility(MovePossibility::NotCalculated)
{
    path.erase(path.begin());
}

std::shared_ptr<ITile> IVehicle::move()
{
    const auto result = currentPosition;
    currentPosition = getNextPosition();
    path.erase(path.begin());
    movePossibility = MovePossibility::NotCalculated;
    return result;
}

void IVehicle::onTimeout()
{
    std::cerr << "onTimeout" << std::endl;
}

std::shared_ptr<ITile> IVehicle::getCurrentPosition() const { return currentPosition; }
std::shared_ptr<ITile> IVehicle::getNextPosition() const { return path.front(); }
bool IVehicle::reachedDestination() const { return path.empty(); }

bool IVehicle::canMove()
{
    if (movePossibility == MovePossibility::NotCalculated)
    {
        calculateMovePossibility();
    }
    return movePossibility == MovePossibility::True;
}

void IVehicle::calculateMovePossibility()
{
    movePossibility = MovePossibility::True;
}

} // namespace TS::core::MO
