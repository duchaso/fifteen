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
    Q_INVOKABLE bool win();
    Q_INVOKABLE void reset();

private:
    bool is_movable(const QModelIndex& index, QPoint& to_swap);
    bool is_solvable(QVector<int>& list);
    void generate_board(int size);

private:
    TileMatrix m_data;
};

#endif // BOARD_H
