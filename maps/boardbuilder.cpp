#include <memory>
#include <vector>
#include <iostream>

#include "boardbuilder.hpp"
#include "../core/MO/road.hpp"
#include "../core/MO/emptyfield.hpp"

namespace TS::maps
{
namespace
{
constexpr auto ALL_SIDES = {
    core::MO::ITile::Side::DOWN,
    core::MO::ITile::Side::UP,
    core::MO::ITile::Side::LEFT,
    core::MO::ITile::Side::RIGHT
};
/** Example map
 *  XXXXXXX
 *  XXXXXXX
 *  XXXXXXX
 *  -------
 *  XXXXXXX
 *  XXXXXXX
 *  XXXXXXX
*/
core::Board::BoardT getExampleBoard()
{
    const unsigned size = 7u;
    core::Board::BoardT result;
    for (auto i = 0u; i < size; ++i)
    {
        core::Board::LineT line;
        for (auto j = 0u; j < size; j++)
        {
            if (i == 3)
            {
                const auto r = std::make_shared<core::MO::Road>(core::MO::Road::Direction::horizontal);
                line.push_back(r);
            }
            else
            {
                const auto ef = std::make_shared<core::MO::EmptyField>();
                line.push_back(ef);
            }
        }
        result.push_back(line);
    }
    return result;
}

void connectTiles(core::Board& board)
{
    const auto lineSize = board.board.size();
    if (!lineSize)
    {
        std::cerr << "Board is empty" << std::endl;
        return;
    }
    const auto columnSize = board.board[0].size();
    if (!columnSize)
    {
        std::cerr << "Board is empty" << std::endl;
        return;
    }

    const auto getTileOnSide = [&](const core::MO::ITile::Side side,
            const int i,
            const int j) -> std::shared_ptr<core::MO::ITile> {
        int new_i = i;
        int new_j = j;
        switch(side)
        {
        case core::MO::ITile::Side::UP: new_i--; break;
        case core::MO::ITile::Side::DOWN: new_i++; break;
        case core::MO::ITile::Side::LEFT: new_j--; break;
        case core::MO::ITile::Side::RIGHT: new_j++; break;
        }
        if (new_i < 0 || new_i >= lineSize || new_j < 0 || new_j >= columnSize)
            return nullptr;
        return board.board[new_i][new_j];
    };

    for (auto i = 0u; i < lineSize; ++i)
    {
        for (auto j = 0u; j < columnSize; ++j)
        {
            for (const auto side : ALL_SIDES)
            {
                const auto tile = board.board[i][j];
                if (!tile->canBeConnected(side))
                    continue;

                const auto tileToConnect = getTileOnSide(side, i, j);
                tile->connectEndpoint(side, tileToConnect);
            }
        }
    }
}

} // namespace


BoardBuilder::BoardBuilder()
{
}

core::Board BoardBuilder::operator()() const
{
    core::Board result(getExampleBoard());
    connectTiles(result);
    return result;
}

} // namespace TS::maps
