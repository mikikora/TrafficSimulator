#pragma once

#include <QObject>
#include <QTimer>
#include <memory>
#include <vector>

#include "Board.hpp"
#include "vehiclehandler.hpp"

namespace TS::core {

class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager(Board board);

private:
    const Board board;
    QTimer timer;
    MO::VehicleList vehicles;
    MO::VehicleList vehiclesToMove;
    const std::unique_ptr<VehicleHandler> vehicleHandler;

    void calculateIfVehiclesMove();
    void UpdateBoard();
    void moveVehicles();

public slots:
    void calculateTurn();
};

} // namespace TS::core

