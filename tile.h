#ifndef TILE_H
#define TILE_H

#include <QString>

class Tile
{
public:
    Tile() = delete;
    Tile(unsigned int number);

    QString data() const;
private:
    unsigned int m_number;
};

#endif // TILE_H