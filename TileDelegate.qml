import QtQuick 2.0

Item {
    Rectangle {
        id: tile

        width: parent.width * 0.95
        height: parent.height * 0.95
        radius: 5
        anchors.centerIn: parent
        color: display === boardView.emptyTile ? "transparent" : "grey"

        Text {
            id: textTile

            text: display === boardView.emptyTile ? "" : display
            font.pointSize: 40
            color: "white"
            anchors.centerIn: parent
        }
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
