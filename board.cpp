#include "board.h"

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
            return QString("%1, %2").arg(index.column()).arg(index.row());
        default:
            break;
    }
    return QVariant();
}

QHash<int, QByteArray> Board::roleNames() const
{
    return {{Qt::DisplayRole, "display"}};
}

