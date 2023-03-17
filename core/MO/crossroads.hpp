#pragma once

#include <memory>

#include "ITile.hpp"
#include "IVehicle.hpp"

namespace TS::core::MO
{
class Crossroads : public ITile
{
public:
    Crossroads();

    std::string classname() const override {return "Crossroads";}

private:
    std::shared_ptr<ITile> upEndpoint;
    std::shared_ptr<ITile> leftEndpoint;
    std::shared_ptr<ITile> downEndpoint;
    std::shared_ptr<ITile> rightEndpoint;
};

} // namespace TS::core::MO
