#include "tile.h"
#include <cassert>

Tile::Tile(int number) : m_number{(assert(0 <= number), number)}
{
}

std::ostream &operator<<(std::ostream &out, const Tile &tile)
{
    out << ' ';
    if (tile.isEmpty())
    {
        out << "  ";
    }
    else if (tile.m_number < 10)
    {
        out << tile.m_number << ' ';
    }
    else
    {
        out << tile.m_number;
    }
    out << ' ';
    return out;
}