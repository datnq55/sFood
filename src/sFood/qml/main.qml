import QtQuick 2.7

Rectangle {
//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            Qt.quit();
//        }
//    }
    anchors.fill: parent

    Rectangle{
        width: 100
        height: 50
        color: "#ff0000"
        y: 10
    }

    Text{
        anchors.centerIn: parent
        text: "Hello world"
    }
}
