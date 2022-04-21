#include "board.h"

Board::Board()
{
    auto cnt{0};
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
    return 4;
}

int Board::columnCount(const QModelIndex &) const
{
    return 4;
}

QVariant Board::data(const QModelIndex &index, int role) const
{
    switch(role) {
        case Qt::DisplayRole:
            return m_data[index.row()][index.column()].data();
//            return QString("%1, %2").arg(index.column()).arg(index.row());
        default:
            break;
    }
    return QVariant();
}

QHash<int, QByteArray> Board::roleNames() const
{
    return {{Qt::DisplayRole, "display"}};
}

