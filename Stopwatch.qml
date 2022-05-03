import QtQuick 2.0
import QtQuick.Layouts 1.15

Item {
    id: root

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            time.sec = time.sec + 1;
            if(time.sec === 60) {
                time.min = time.min + 1;
                time.sec = 0;
                if(time.min === 60) {
                    time.hours = time.hours + 1;
                    time.min = 0;
                }
            }
            timeText.text = time.hours + ":" + time.min + ":" + time.sec;
        }
    }
    Text {
        id: timeText
        text: "0:0:0"
        color: "black"
        font.pointSize: 25
        anchors.centerIn: parent
    }
    QtObject {
        id: time

        property int sec: 0
        property int min: 0
        property int hours: 0
    }

    function reset() {
        time.sec = 0;
        time.min = 0;
        time.hours = 0;
        timeText.text = "0:0:0";
    }
}
