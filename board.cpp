#include "board.h"

Board::Board()
{
    generate_board(3);
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

bool Board::moveTile(const QModelIndex& index)
{
    QPoint index_tile{index.row(), index.column()};
    QPoint empty_tile{};

    if(is_movable(index, empty_tile))
    {
        std::swap( m_data[empty_tile.x()][empty_tile.y()],
                m_data[index_tile.x()][index_tile.y()]
                );
        emit dataChanged(this->index(empty_tile.x(), empty_tile.y()), this->index(empty_tile.x(), empty_tile.y()));
        emit dataChanged(index, index);
        return true;
    } else {
        qDebug() << "can't move";
        return false;
    }
}

bool Board::win()
{
    int prev = m_data.first().first().data()-1;
    for(auto& row : m_data)
        for(auto& current_item : row)
        {
            if(current_item.data() - prev != 1)	return false;
            prev = current_item.data();
        }

    return true;
}

void Board::reset(int board_size)
{
    m_board_size = board_size;
    generate_board(m_board_size);
}

bool Board::is_movable(const QModelIndex& index, QPoint& to_swap)
{
    using Directions = QVector<QPoint>;

    static const Directions directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    QPoint current(index.row(), index.column());

    for(auto& direction : directions)
    {
        to_swap = current+direction;
        if(to_swap.x() < 0 || to_swap.x() > m_data.size()-1 || to_swap.y() < 0 || to_swap.y() > m_data.size()-1) continue;
        if(m_data[to_swap.x()][to_swap.y()].data() == m_data.size()*m_data.size()) return true;
    }
    return false;
}

void Board::generate_board(int size)
{ 
    if(!m_data.isEmpty())
    {
        for(auto& row : m_data)
            row.clear();
        m_data.clear();
    }
//        m_data.clear();

    QVector<int> v;
    for(int i = 1; i <= size*size; ++i)
        v.append(i);

    std::random_device rd;
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(v), std::end(v)-1, rng);
    while(!is_solvable(v))
        std::shuffle(std::begin(v), std::end(v)-1, rng);

    auto cnt{0};
    for(auto i = 0; i < size; ++i)
    {
        QVector<Tile> tmp;
        for(auto j = 0; j < size; ++j)
        {
            tmp.append(v[cnt]);
            ++cnt;
        }
        m_data.append(tmp);
    }
    emit dataChanged(this->index(0,0), this->index(m_board_size-1, m_board_size-1));
}

bool Board::is_solvable(QVector<int>& list)
{
    auto cnt{0};

    for(int i = 0; i < list.size()-1; ++i)
    {
        for(int j = i + 1; j < list.size()-1; ++j)
            if(list[i] > list[j])
                ++cnt;
    }

    return cnt % 2 == 0 ? true : false;
}

