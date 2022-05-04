import QtQuick 2.0

Rectangle {
    id: tile

    property string empty: ""
    radius: 5
    color: display === empty ? "transparent" : "grey"
//    width: parent.width * 0.95
//    height: parent.height * 0.95
//    anchors.centerIn: parent

    Text {
        id: textTile

        text: display === empty ? "" : display
        font.pointSize: 40
        color: "white"
        anchors.centerIn: parent
    }
}
