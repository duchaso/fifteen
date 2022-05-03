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
    Q_PROPERTY(int stepCounter READ stepCounter WRITE setStepcounter NOTIFY stepcounterChanged)
    Q_PROPERTY(int boardDimension READ boardDimension WRITE setBoardDimension NOTIFY boardDimensionChanged)

    using TileMatrix = QVector<QVector<Tile>>;

public:
    Board();

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE bool moveTile(const QModelIndex& index);
    Q_INVOKABLE bool win();
    Q_INVOKABLE void reset(int boad_size = 4);

    int stepCounter();
    int boardDimension();

public slots:
    void setStepcounter(int value);
    void setBoardDimension(int value);

signals:
    void stepcounterChanged();
    void boardDimensionChanged();

private:
    bool isMovable(const QModelIndex& index, QPoint& to_swap);
    bool isSolvable(QVector<int>& list);
    void generateBoard(int size);

private:
    TileMatrix m_data;
    int m_boardDimension;
    int m_stepCounter;
};

#endif // BOARD_H
