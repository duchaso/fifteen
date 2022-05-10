import QtQuick 2.0

Rectangle {
    id: tile

    radius: 5
    color: display == "0" ? "transparent" : "grey"

    Text {
        id: textTile

        text: display
        font.pointSize: 40
        color: "white"
        anchors.centerIn: parent
    }
}
