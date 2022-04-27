#include "board.h"

Board::Board()
{
    auto cnt{1};
    for(auto i = 0; i < BOARD_HEIGHT; ++i)
    {
        QVector<Tile> tmp;
        for(auto j = 0; j < BOARD_WIDTH; ++j)
        {
            tmp.append(cnt);
            ++cnt;
        }
        m_data.append(tmp);
    }

}

int Board::rowCount(const QModelIndex &) const
{
    return m_data.length();
}

int Board::columnCount(const QModelIndex &) const
{
    return m_data[0].length();
}

QVariant Board::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
        case Qt::DisplayRole:
            return QString::number(m_data[index.row()][index.column()].data());
        default:
            break;
    }
    return QVariant();
}

QHash<int, QByteArray> Board::roleNames() const
{
    return {{Qt::DisplayRole, "display"}};
}

void Board::moveTile(const QModelIndex& index)
{
    QPoint index_tile{index.row(), index.column()};
    QPoint empty_tile{};

    if(isMovable(index, empty_tile))
    {
        std::swap( m_data[empty_tile.x()][empty_tile.y()],
                m_data[index_tile.x()][index_tile.y()]
                );
        emit dataChanged(this->index(empty_tile.x(), empty_tile.y()), this->index(empty_tile.x(), empty_tile.y()));
        emit dataChanged(index, index);
    } else {
        qDebug() << "can't move";
    }
}

bool Board::isMovable(const QModelIndex& index, QPoint& to_swap)
{
    using Directions = QVector<QPoint>;

    static const Directions directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    QPoint current(index.row(), index.column());

    for(auto& direction : directions)
    {
        to_swap = current+direction;
        if(to_swap.x() < 0 || to_swap.x() > 3 || to_swap.y() < 0 || to_swap.y() > 3) continue;
        if(m_data[to_swap.x()][to_swap.y()].data() == 16) return true;
    }
    return false;
}

