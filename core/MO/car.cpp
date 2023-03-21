#include "car.hpp"

namespace TS::core::MO
{
Car::Car(const std::vector<std::shared_ptr<ITile>>& destinations,
         const std::shared_ptr<ITile> currentPosition)
    : IVehicle(destinations, currentPosition)
{
}
} // namespace TS::core::MO
