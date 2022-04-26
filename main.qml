import QtQuick 2.15
import QtQuick.Window 2.15
import board 1.0

Window {
    id: win

    width: 640
    height: 480
    visible: true
    title: qsTr("Fifteen")

    TableView {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        columnWidthProvider: function (column) { return win.width / 4 }
        rowHeightProvider: function (row) { return win.height / 4 }
        interactive: false

        model: Board {
            id: boardModel
        }

        delegate: Rectangle {
            color: bg

            Text {
                text: display
                anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {boardModel.add_item_to_swapping(row, column)}
            }
        }
    }
}
