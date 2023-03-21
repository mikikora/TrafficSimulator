#pragma once

#include <string>

#include "ITile.hpp"

namespace TS::core::MO
{

class SpawningTile : public ITile
{
public:
    SpawningTile(const unsigned x, const unsigned y);

    void pushVehicle(const VehicleData& v) override;

    bool canBeConnected(const Side side) const override;

    ~SpawningTile(){}

    std::string classname() const override {return "SpawningTile"; }
};

} // namespace TS::core::MO
