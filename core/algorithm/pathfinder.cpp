#include <queue>
#include <set>

#include "pathfinder.hpp"

namespace TS::core::algorithm
{
using namespace MO;

PathFinder::PathFinder()
{
}

MO::TileList PathFinder::getPath(
        const Tile src,
        const Tile dest) const
{
    // bfs algorithm
    std::queue<TileList> q;
    std::set<Tile> seen;

    q.push({src});
    while (q.size())
    {
        const auto& path = q.front();
        const auto tile = path.back();
        q.pop();
        if (seen.find(tile) == seen.end())
            continue;

        if (tile == dest)
            return path;

        for (const auto [side, neighbour] : tile->endpoints)
        {
            TileList newPath = path;
            newPath.push_back(neighbour);
            q.push(newPath);
        }
    }
    return {};
}

} // namespace TS::core::algorithm
