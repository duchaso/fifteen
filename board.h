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
    Q_PROPERTY(int stepCounter READ stepCounter WRITE setStepCounter NOTIFY stepCounterChanged)
    Q_PROPERTY(int dimension READ dimension WRITE setDimension NOTIFY dimensionChanged)

    using TileMatrix = QVector<QVector<Tile>>;

public:
    Board();

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE bool moveTile(const QModelIndex& index);

    int stepCounter();
    int dimension();

public slots:
    void setStepCounter(int value);
    void setDimension(int value);
    void reset();

signals:
    void stepCounterChanged();
    void dimensionChanged();

private:
    bool isMovable(const QModelIndex& index, QPoint& to_swap);
    bool isSolvable(QVector<int>& list);
    bool isWin();
    void generateBoard();

private:
    TileMatrix m_data;
    int m_boardDimension;
    int m_stepCounter;
};

#endif // BOARD_H
