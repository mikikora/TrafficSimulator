#pragma once

#include <vector>
#include <string>
#include <memory>

#include "ITile.hpp"
#include "IVehicle.hpp"

namespace TS::core::MO
{
class Car : public IVehicle
{
public:
    Car(const std::vector<std::shared_ptr<ITile>>& destinations,
        const std::shared_ptr<ITile> currentPosition);
//    Car(const TileList& destinationst);
    ~Car() override {}

    std::string classname() const override {return "Car";}
};
} // namespace TS::core::MO
