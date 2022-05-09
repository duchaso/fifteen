#ifndef TILE_H
#define TILE_H

class Tile
{
public:
    Tile() = delete;
    Tile(unsigned int number);

    unsigned int data() const;
private:
    unsigned int m_number;
};

#endif // TILE_H
