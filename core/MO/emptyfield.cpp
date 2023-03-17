#include <iostream>

#include "emptyfield.hpp"

namespace TS::core::MO
{
EmptyField::EmptyField(const unsigned x, const unsigned y) : ITile(x, y)
{
}

void EmptyField::pushVehicle(const VehicleData& v)
{
    std::cerr << "Can't push vehicle to empty field" << std::endl;
}

bool EmptyField::canBeConnected(const Side side) const
{
    return false;
}
} // namespace TS::core::MO
