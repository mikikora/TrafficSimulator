#include "car.hpp"

namespace TS::core::MO
{
//Car::Car(const ITile& destination) : destinations({destination})
//{
//}

Car::Car(const TileList& destinationst) : IVehicle(destinationst)
{
}
} // namespace TS::core::MO
