#pragma once

#include <memory>

#include "ITile.hpp"
#include "IVehicle.hpp"

namespace TS::core::MO
{
class Crossroads : public ITile
{
public:
    Crossroads(const unsigned x, const unsigned y);

    std::string classname() const override {return "Crossroads";}

private:
    Tile upEndpoint;
    Tile leftEndpoint;
    Tile downEndpoint;
    Tile rightEndpoint;
};

} // namespace TS::core::MO
