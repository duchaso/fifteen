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

            rowSpacing: 5
            columnSpacing: 5
            Layout.preferredWidth: 600
            Layout.preferredHeight: 600
            columnWidthProvider: function (column) { return (root.width - 200) / boardModel.columnCount()}
            rowHeightProvider: function (row) { return root.height / boardModel.rowCount() }
            interactive: false

            model: Board {
                id: boardModel

                property bool blocked: false
                property string emptyTile: boardModel.rowCount() * boardModel.columnCount()
            }

            delegate: TileDelegate {
                empty: boardModel.emptyTile

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        if(!boardModel.blocked) {
                            boardModel.moveTile(boardModel.index(row, column)) ? winDialog.open() : false;
                        }
                    }
                }
            }
        }


        ColumnLayout {
            id: sideBar

            Layout.preferredWidth: 200
            Layout.preferredHeight: 600
            Layout.alignment: Qt.AlignRight

            Stopwatch {
                id: stopwatch

                Layout.topMargin: 10
                Layout.alignment: Qt.AlignCenter
            }

            Text {
                id: stepCounter

                Layout.alignment: Qt.AlignCenter
                text: "Steps: " + boardModel.stepCounter
                color: "black"
                font.pointSize: 20
            }

            ComboBox {
                id: boardSizeSelector

                Layout.alignment: Qt.AlignCenter
                model: [
                    {name: "3x3", value: 3},
                    {name: "4x4", value: 4},
                    {name: "5x5", value: 5},
                    {name: "6x6", value: 6}
                ]

                textRole: "name"
                valueRole: "value"
                currentIndex: indexOfValue(boardModel.dimension)

                onCurrentValueChanged: boardModel.dimension = currentValue

                Component.onCompleted: currentIndex = indexOfValue(boardModel.dimension)

                onActivated: {
                    stopwatch.reset();
                    boardView.columnWidthProvider = function (column) { return (root.width - 200) / boardModel.columnCount()};
                    boardView.rowHeightProvider = function (row) { return root.height / boardModel.rowCount() };
                    boardModel.emptyTile = boardModel.rowCount() * boardModel.columnCount();
                }
            }
        }
    }
    MessageDialog {
        id: winDialog

        title: "You won!"
        text: "Congrats!"
        standardButtons: StandardButton.Ok | StandardButton.Reset

        onAccepted: boardModel.blocked = true
        onReset: boardModel.reset()

    }
}

