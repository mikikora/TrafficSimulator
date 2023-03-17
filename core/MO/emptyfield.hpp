#pragma once

#include "ITile.hpp"

namespace TS::core::MO
{
class EmptyField : public ITile
{
public:
    EmptyField();
    void pushVehicle(const VehicleData& v) override;
    bool canBeConnected(const Side side) const override;
    ~EmptyField() override {}

    std::string classname() const override {return "EmptyField";}
};

} // namespace TS::core::MO

