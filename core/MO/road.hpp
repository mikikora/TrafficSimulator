#pragma once

#include <memory>
#include <string>

#include "ITile.hpp"

namespace TS::core::MO
{
class Road : public ITile
{
public:
    enum class Direction
    {
        horizontal = 0,
        vertical = 1
    };
    const Direction direction;

    Road(const Direction direction);

    bool canBeConnected(const Side side) const override;
    void pushVehicle(const VehicleData& v) override;
    ~Road() override {};

    std::string classname() const override {return "Road";}
//    std::string classname() const override {return "Road" + std::string(endpoints.size(), 'X');}

private:
    bool endpointContains(const std::shared_ptr<ITile> endpoint) const;
};
} // namepace TS::core::MO
