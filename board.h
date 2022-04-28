#ifndef BOARD_H
#define BOARD_H

#include <qqml.h>
#include <QAbstractTableModel>

#include <QBrush>
#include <QColor>
#include <QDebug>
#include <QtMath>

#include <utility>
#include <algorithm>
#include <random>

#include "tile.h"

#define BOARD_HEIGHT 4
#define BOARD_WIDTH  4


class Board : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT

    using TileMatrix = QVector<QVector<Tile>>;

public:
    Board();

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void moveTile(const QModelIndex& index);

private:
    bool is_movable(const QModelIndex& index, QPoint& to_swap);
    void generate_board(int size);
    bool is_solvable(QVector<int>& list);

private:
    TileMatrix m_data;
};

#endif // BOARD_H
