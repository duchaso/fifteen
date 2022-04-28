import QtQuick 2.0
import QtQuick.Layouts 1.15

Text {
    Layout.alignment: Qt.AlignCenter
    property int counter: 0
    text: "Steps: " + counter
    color: "black"
    font.pointSize: 20
}
