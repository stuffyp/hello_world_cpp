#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
private:
    int m_number;

public:
    Tile() = default;
    explicit Tile(int number);
    friend std::ostream &operator<<(std::ostream &out, const Tile &tile);

    bool isEmpty() const { return m_number == 0; }
    int getNum() const { return m_number; }
};

#endif