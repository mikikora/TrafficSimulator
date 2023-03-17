#pragma once

#include <vector>
#include <memory>
#include <string>
#include <map>

namespace TS::core::MO
{
class ITile;
class IVehicle;
using Tile = std::shared_ptr<ITile>;
using TileList = std::vector<Tile>;

struct VehicleData
{
    std::shared_ptr<IVehicle> vehicle;
    Tile startEndpoint;
    Tile endPoint;
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

    ITile(const unsigned x, const unsigned y);
    virtual void pushVehicle(const VehicleData& v);
    std::vector<VehicleData> getVehicleDatas() const;
    VehicleData freeTile(const std::shared_ptr<IVehicle> vehicle);
    virtual bool canBeConnected(const Side side) const = 0;
    void connectEndpoint(const Side side, const std::shared_ptr<ITile> tile);
    virtual ~ITile() = default;

    virtual std::string classname() const = 0;

    const unsigned x;
    const unsigned y;
    const std::map<Side, std::shared_ptr<ITile>> endpoints;
protected:
    std::vector<VehicleData> vehicleDatas;
};
} // namespace TS::core::MO
