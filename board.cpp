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

void Board::add_item_to_swapping(const int row, const int col) {
    items_to_swap.append(Coord(row, col));
    if(items_to_swap.length() == 2)
    {
        swapping();
        items_to_swap.clear();
    }
}

bool Board::swapping()
{
    if(items_to_swap[FIRST] == items_to_swap[SECOND])
    {
        qDebug() << "Can't move. Items are the same.";
        return false;
    } else {
        auto f_row = items_to_swap[FIRST].first;
        auto f_col = items_to_swap[FIRST].second;

        auto s_row = items_to_swap[SECOND].first;
        auto s_col = items_to_swap[SECOND].second;

        std::swap(m_data[f_row][f_col], m_data[s_row][s_col]);
//        emit dataChanged(items_to_swap[FIRST], items_to_swap[SECOND]);
        emit dataChanged(index(f_row, f_col), index(s_row, s_col));

        return true;
    }
}


