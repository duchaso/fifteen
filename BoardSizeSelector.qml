import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ComboBox {
    Layout.alignment: Qt.AlignCenter
    property int offset: 3
    model: ["3x3", "4x4", "5x5", "6x6"]

    onActivated: {
        boardModel.reset(currentIndex + offset)
        stepCounter.counter = 0
        stopwatch.sec = 0
        stopwatch.min = 0
        stopwatch.hours = 0
        boardView.columnWidthProvider = function (column) { return (root.width-200) / boardModel.columnCount()}
        boardView.rowHeightProvider = function (row) { return root.height / boardModel.rowCount() }
        boardView.emptyTile = boardModel.rowCount()*boardModel.columnCount()
    }
}
