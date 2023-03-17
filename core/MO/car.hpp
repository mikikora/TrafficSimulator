#pragma once

#include <vector>
#include <string>

#include "ITile.hpp"
#include "IVehicle.hpp"

namespace TS::core::MO
{
class Car : public IVehicle
{
public:
    Car();
//    Car(const ITile& destination);
//    Car(const std::vector<ITile>& destinationList);
    ~Car() override {}

    std::string classname() const override {return "Car";}
private:
    std::vector<ITile> destinations;
};
} // namespace TS::core::MO
