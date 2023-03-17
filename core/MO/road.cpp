#include <iostream>
#include <algorithm>

#include "road.hpp"

namespace TS::core::MO
{
namespace
{

} // namespace

Road::Road(const unsigned x,
           const unsigned y,
           const Direction direction)
    : ITile(x, y)
    , direction(direction)
{
}

bool Road::canBeConnected(const Side side) const
{
    if (direction == Direction::horizontal)
    {
        switch(side)
        {
        case Side::LEFT:
        case Side::RIGHT: return true;
        default: return false;
        }
    }
    else
    {
        switch(side)
        {
        case Side::UP:
        case Side::DOWN: return true;
        default: return false;
        }
    }
}

void Road::pushVehicle(const VehicleData& v)
{
    if (endpointContains(v.startEndpoint) && endpointContains(v.endPoint))
    {
        ITile::pushVehicle(v);
    }
    else
    {
        std::cerr << "Vehicle has endpoints that aren't part of the road" << std::endl;
    }
}

bool Road::endpointContains(const Tile endpoint) const
{
    return std::any_of(endpoints.begin(), endpoints.end(), [&](const auto& e){return e.second == endpoint;});
}

} // namespace TS::core::MO
