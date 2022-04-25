#include "tile.h"

Tile::Tile(unsigned int number)
    : m_number{number}
{
}

unsigned int Tile::data() const
{
    return m_number;
}
