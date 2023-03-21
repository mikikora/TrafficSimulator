#include "gamemanager.hpp"

#include <algorithm>
#include <iostream>

namespace TS::core {

GameManager::GameManager(Board board)
    : board(board)
    , timer(this)
    , vehicles({})
    , vehiclesToMove({})
    , vehicleHandler(std::make_unique<VehicleHandler>(board))
{
    connect(&timer, &QTimer::timeout, this, &GameManager::calculateTurn);
    timer.start(1000);

    board.print();
}

void GameManager::calculateTurn()
{
    vehiclesToMove.clear();

    std::cerr << "vehiclesMove" << std::endl;
    calculateIfVehiclesMove();

    std::cerr << "UpdateBoard" << std::endl;
    UpdateBoard();

    std::cerr << "createVehicles" << std::endl;
    if (vehicles.empty()) {
    const auto& createdVehicles = vehicleHandler->createVehicles();
    vehicles.insert(vehicles.end(), createdVehicles.begin(), createdVehicles.end());
}

    std::cerr << "board print" << std::endl;
    board.print();
}

void GameManager::calculateIfVehiclesMove()
{
    for (const auto& vehicle : vehicles)
    {
        if (vehicle->canMove())
            vehiclesToMove.push_back(vehicle);
    }
}

void GameManager::UpdateBoard()
{
    moveVehicles();
}

void GameManager::moveVehicles()
{
    for (const auto& vehicle : vehiclesToMove)
    {
        auto currentTile = vehicle->getCurrentPosition();
        currentTile->freeTile(vehicle);
        if (vehicle->reachedDestination())
        {
            const auto& vehiclePosition = std::find(vehicles.begin(), vehicles.end(), vehicle);
            vehicles.erase(vehiclePosition);
        }
    }
    for (const auto& vehicle : vehiclesToMove)
    {
        if (vehicle->reachedDestination())
            continue;
        auto prevTile = vehicle->move();
        auto nextTile = vehicle->getNextPosition();
        vehicle->getCurrentPosition()->pushVehicle({vehicle, prevTile, nextTile});
    }
}

} // namespace TS::core
