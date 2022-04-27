import QtQuick 2.15
import QtQuick.Window 2.15
import board 1.0

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("Fifteen")

    TableView {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        columnWidthProvider: function (column) { return root.width / 4 }
        rowHeightProvider: function (row) { return root.height / 4 }
        interactive: false

        model: Board {
            id: boardModel
        }

        delegate: Rectangle {
            color: display === "16" ? "transparent" : "grey"

            Text {
                text: display === "16" ? "" : display
                anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                onClicked: boardModel.moveTile(boardModel.index(row, column))
            }
        }
    }
}
