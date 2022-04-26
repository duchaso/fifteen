#ifndef BOARD_H
#define BOARD_H

#include <qqml.h>
#include <QAbstractTableModel>

#include <QBrush>
#include <QColor>
#include <QDebug>
#include <utility>

#include "tile.h"

#define BOARD_HEIGHT 4
#define BOARD_WIDTH  4
#define FIRST 		 0
#define SECOND 		 1

using TileMatrix = QVector<QVector<Tile>>;
using Coord = QPair<int, int>;

class Board : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    Board();

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    Q_INVOKABLE void add_item_to_swapping(const int row, const int column);
    bool swapping();

private:
    TileMatrix m_data;
    QVector<Coord> items_to_swap;
};

#endif // BOARD_H
