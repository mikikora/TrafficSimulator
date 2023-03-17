#pragma once

#include <vector>
#include <memory>
#include <string>
#include <map>

#include "IVehicle.hpp"

namespace TS::core::MO
{
class ITile;

struct VehicleData
{
    std::shared_ptr<IVehicle> vehicle;
    std::shared_ptr<ITile> startEndpoint;
    std::shared_ptr<ITile> endPoint;
};

class ITile
{
public:
    enum class Side
    {
        UP = 0,
        LEFT = 1,
        DOWN = 2,
        RIGHT = 3
    };

    virtual void pushVehicle(const VehicleData& v);
    std::vector<VehicleData> getVehicleDatas() const;
    VehicleData freeTile(const std::shared_ptr<IVehicle> vehicle);
    virtual bool canBeConnected(const Side side) const = 0;
    void connectEndpoint(const Side side, const std::shared_ptr<ITile> tile);
    virtual ~ITile() = default;

    virtual std::string classname() const = 0;

protected:
    std::vector<VehicleData> vehicleDatas;
    std::map<Side, std::shared_ptr<ITile>> endpoints;
};
} // namespace TS::core::MO
