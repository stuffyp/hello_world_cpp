#include "board.h"
#include <algorithm>

inline Board::Coord operator+(Board::Coord c1, Board::Coord c2)
{
    return Board::Coord{c1.first + c2.first, c1.second + c2.second};
}

Board::Board()
{
    for (int i{0}; i < NUM_ROWS; ++i)
    {
        for (int j{0}; j < NUM_COLS; ++j)
        {
            m_tiles[i][j] = Tile{(NUM_COLS * i + j + 1) % AREA};
        }
    }
}

bool Board::inBounds(Board::Coord coord) const
{
    return 0 <= coord.first && coord.first < NUM_ROWS &&
           0 <= coord.second && coord.second < NUM_COLS;
}

Board::Coord Board::emptySquare() const
{
    for (int i{0}; i < Board::NUM_ROWS; ++i)
    {
        for (int j{0}; j < Board::NUM_COLS; ++j)
        {
            if (m_tiles[i][j].isEmpty())
            {
                return Board::Coord{i, j};
            }
        }
    }
    return Board::Coord{-1, -1}; // error
}

void Board::doMove(UserCommand command)
{
    Board::Coord empty = emptySquare();
    Board::Coord delta{};
    switch (command)
    {
    case UserCommand::Up:
        delta = Board::Coord{1, 0};
        break;
    case UserCommand::Down:
        delta = Board::Coord{-1, 0};
        break;
    case UserCommand::Left:
        delta = Board::Coord{0, 1};
        break;
    case UserCommand::Right:
        delta = Board::Coord{0, -1};
        break;
    default:
        break;
    }
    Board::Coord moveTo{empty + delta};
    if (inBounds(moveTo))
    {
        std::swap(m_tiles[empty.first][empty.second], m_tiles[moveTo.first][moveTo.second]);
    }
}

bool Board::isSolved() const
{
    for (int i{0}; i < NUM_ROWS; ++i)
    {
        for (int j{0}; j < NUM_COLS; ++j)
        {
            if (m_tiles[i][j].getNum() != (NUM_COLS * i + j + 1) % 16)
            {
                return false;
            }
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, const Board &b)
{
    for (int i{0}; i < Board::NUM_ROWS; ++i)
    {
        for (int j{0}; j < Board::NUM_COLS; ++j)
        {
            out << b.m_tiles[i][j];
        }
        out << '\n';
    }
    return out;
}