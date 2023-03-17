#include "IVehicle.hpp"
#include "ITile.hpp"

namespace TS::core::MO
{
IVehicle::IVehicle(std::vector<std::shared_ptr<ITile>> destinations,
                   std::shared_ptr<ITile> currentPosition)
    : destinations(destinations)
    , currentPosition(currentPosition)
{}

void IVehicle::updatePosition(std::shared_ptr<ITile> newPosition)
{
    currentPosition = newPosition;
}

} // namespace TS::core::MO
