#include "tile.h"

Tile::Tile(unsigned int number)
    : m_number{number}
{
}

QString Tile::data() const
{
    return QString::number(m_number);
}
