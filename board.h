#ifndef BOARD_H
#define BOARD_H

#include <qqml.h>
#include <QAbstractTableModel>

#include "tile.h"

#define BOARD_HEIGHT 4
#define BOARD_WIDTH  4

using TileMatrix = QVector<QVector<Tile>>;

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

    Q_INVOKABLE void testFunction(const QModelIndex& index);
    Q_INVOKABLE void testFunction(QString& str);
private:
    TileMatrix m_data;
};

#endif // BOARD_H
