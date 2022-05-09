import QtQuick 2.0
import QtQuick.Layouts 1.15

Item {
    id: root

    property alias started: timer.running

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
        timer.totalTime = 0;
        started = false;
        timeText.text = "0:0:0";
    }

    Timer {
        id: timer

        property int totalTime: 0
        interval: 1000
        running: false
        repeat: true

        onTriggered: {
            timer.totalTime += 1;

            time.hours = totalTime / 3600;
            time.min = (totalTime / 60) % 60;
            time.sec = totalTime % 60;

            timeText.text = time.hours + ":" + time.min + ":" + time.sec;
        }
    }
}
