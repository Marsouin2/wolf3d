#include <vector>

#include "Tile.h"

class MapMgr
{
private:
    std::vector<std::vector<Tile>> vVGameMap;
public:
    MapMgr() = default;
    virtual ~MapMgr() = default;
    /* Check depending on where the player wants to go for his future move if it's an empty space or not */
    bool isPlayerNextMoveValid() const;
};