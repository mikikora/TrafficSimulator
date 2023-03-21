#include <queue>
#include <set>
#include <iostream>

#include "pathfinder.hpp"

namespace TS::core::algorithm
{
using namespace MO;

MO::TileList PathFinder::getPath(
        const Tile src,
        const Tile dest)
{
    // bfs algorithm
    std::queue<TileList> q;
    std::set<Tile> seen;

    q.push({src});
    while (q.size())
    {
        const auto path = q.front();
        const auto tile = path.back();
        q.pop();

        if (seen.find(tile) != seen.end())
            continue;

        if (tile == dest)
            return std::move(path);

        seen.insert(tile);

        for (const auto& [side, neighbour] : tile->endpoints)
        {
            if (!neighbour)
                continue;

            TileList newPath = path;
            newPath.push_back(neighbour);
            q.push(newPath);
        }
    }
    return {};
}

} // namespace TS::core::algorithm
