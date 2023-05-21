#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "usercommand.h"
#include <array>
#include <utility>

class Board
{
public:
    using Coord = std::pair<int, int>;

private:
    static constexpr int NUM_ROWS{4};
    static constexpr int NUM_COLS{4};
    static constexpr int AREA{NUM_ROWS * NUM_COLS};
    std::array<std::array<Tile, NUM_COLS>, NUM_ROWS> m_tiles;

    Coord emptySquare() const;
    bool inBounds(Coord coord) const;

public:
    Board();
    void doMove(const UserCommand command);
    bool isSolved() const;
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif