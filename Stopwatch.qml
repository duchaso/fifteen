import QtQuick 2.0
import QtQuick.Layouts 1.15

Item {
    property int sec: 0
    property int min: 0
    property int hours: 0
    Layout.topMargin: 20
    Layout.alignment: Qt.AlignCenter

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            parent.sec = parent.sec + 1
            if(parent.sec === 60) {
                parent.min = parent.min + 1
                parent.sec = 0
                if(parent.min === 60) {
                    parent.hours = parent.hours + 1
                    parent.min = 0
                }
            }
            timeText.text = parent.hours + ":" + parent.min + ":" + parent.sec
        }
    }
    Text {
        id: timeText
        text: "0:0:0"
        color: "black"
        font.pointSize: 25
        anchors.centerIn: parent
    }
}
