#pragma once

#include <memory>
#include <vector>

namespace TS::core::MO
{
class ITile;

class IVehicle
{
public:
    IVehicle(std::vector<std::shared_ptr<ITile>> destinations,
             std::shared_ptr<ITile> currentPosition);

    void updatePosition(std::shared_ptr<ITile> newPosition);

    virtual std::string classname() const = 0;
    virtual ~IVehicle() = default;
protected:
    std::vector<std::shared_ptr<ITile>> destinations;
    std::vector<std::shared_ptr<ITile>> path;
    std::shared_ptr<ITile> currentPosition;
};

using Vehicle = std::shared_ptr<IVehicle>;
using VehicleList = std::vector<Vehicle>;
} // namespace TS::core::MO
