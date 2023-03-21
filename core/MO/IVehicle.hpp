#pragma once

#include <memory>
#include <vector>

#include <QObject>

namespace TS::core::MO
{
class ITile;

class IVehicle : public QObject
{
    Q_OBJECT
public:
    IVehicle(const std::vector<std::shared_ptr<ITile>>& destinations,
             const std::shared_ptr<ITile> currentPosition);

    std::shared_ptr<ITile> getCurrentPosition() const;
    std::shared_ptr<ITile> getNextPosition() const;
    bool reachedDestination() const;

    std::shared_ptr<ITile> move();
//    void updatePosition(std::shared_ptr<ITile> newPosition);
    bool canMove();

    virtual std::string classname() const = 0;
    virtual ~IVehicle() = default;
protected:
    enum class MovePossibility
    {
        NotCalculated = 0,
        True,
        False
    };

    std::vector<std::shared_ptr<ITile>> destinations;
    std::shared_ptr<ITile> currentPosition;
    std::vector<std::shared_ptr<ITile>> path;
    MovePossibility movePossibility;

    void calculateMovePossibility();

public slots:
    virtual void onTimeout();
};

using Vehicle = std::shared_ptr<IVehicle>;
using VehicleList = std::vector<Vehicle>;
} // namespace TS::core::MO
