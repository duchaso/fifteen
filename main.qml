import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import board 1.0

Window {
    id: root

    width: 800
    height: 600
    visible: true
    title: qsTr("Fifteen")

    RowLayout {
        TableView {
            id: boardView

            property string emptyTile: boardModel.rowCount()*boardModel.columnCount()
            Layout.preferredWidth: 600
            Layout.preferredHeight: 600
            columnWidthProvider: function (column) { return (root.width-200) / boardModel.columnCount()}
            rowHeightProvider: function (row) { return root.height / boardModel.rowCount() }
            interactive: false

            model: Board {
                id: boardModel
                property bool blocked: false
            }

            delegate: TileDelegate {}
        }


        ColumnLayout {
            id: sideBar

            Layout.preferredWidth: 200
            Layout.preferredHeight: 600
            Layout.alignment: Qt.AlignRight

            Stopwatch {
                id: stopwatch
            }

            StepCounter {
                id: stepCounter
            }

            BoardSizeSelector {
                id: boardSizeSelector
            }
        }
    }
    MessageDialog {
        id: winDialog

        title: "You won!"
        text: boardModel.rowCount()
        standardButtons: StandardButton.Ok | StandardButton.Reset

        onAccepted: boardModel.blocked = true
        onReset: boardModel.reset()

    }
}

