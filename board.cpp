#include "board.h"

#include <QBrush>
#include <QColor>
#include <QDebug>

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

    return;
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
    switch(role) {
        case Qt::DisplayRole: {
            if(m_data[index.row()][index.column()].data() == 0)
                return " ";
            else
                return QString::number(m_data[index.row()][index.column()].data());
        }
        case Qt::BackgroundRole: {
            if(m_data[index.row()][index.column()].data() == 0)
                return QBrush(Qt::white);
            else
                return QBrush(Qt::gray);
        }
        default:
            break;
    }
    return QVariant();
}

QHash<int, QByteArray> Board::roleNames() const
{
    return {{Qt::DisplayRole, "display"}, {Qt::BackgroundRole, "bg"}};
}

Qt::ItemFlags Board::flags(const QModelIndex &index) const
{
    if(index.isValid())
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
    else
        return Qt::ItemIsDropEnabled;
}

void Board::testFunction(const QModelIndex& index)
{
    qDebug() << index.data().toString();
}

void Board::testFunction(QString &str)
{
    qDebug() << str;
}

