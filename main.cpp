//#include "mainwindow.hpp"

#include <QApplication>
#include "maps/boardbuilder.hpp"

#include <iostream>

#include "core/gamemanager.hpp"

using namespace TS;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

//    auto road = std::make_shared<core::MO::Road>(1,1, core::MO::Road::Direction::horizontal);
//    auto roadTile = std::static_pointer_cast<core::MO::ITile>(road);
//    auto car = std::make_shared<core::MO::Car>(std::vector{roadTile}, roadTile);
//    auto timer = std::make_shared<QTimer>();
//    QObject::connect(timer.get(), &QTimer::timeout, car.get(), &core::MO::IVehicle::onTimeout);
//    timer->start(1000);

    const auto board = maps::BoardBuilder()();
//    for (const auto& v : board.board)
//    {
//        for (const auto& t : v)
//        {
//            std::cout << t->classname() << " ";
//        }
//        std::cout << std::endl;
//    }
    std::cout << "START" << std::endl;
    core::GameManager manager(board);

    return a.exec();
}

/*#include <iostream>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));

    // Define points for the center line of the road
    QVector<QPointF> roadPoints;
    roadPoints << QPointF(0, 100) << QPointF(50, 150)
               << QPointF(100, 100) << QPointF(150, 150)
               << QPointF(200, 100) << QPointF(250, 150);

    // Draw the road
    QPainterPath roadPath;
    roadPath.moveTo(roadPoints[0]);
    for (int i = 1; i < roadPoints.size(); ++i) {
        roadPath.lineTo(roadPoints[i]);
    }
    scene.addPath(roadPath);

    // Create the car
    QGraphicsRectItem car(QRectF(0, 0, 20, 40));
    car.setPos(0, 80);
    scene.addItem(&car);

    view.show();
    return app.exec();
}*/
