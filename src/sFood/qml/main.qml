import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            Qt.quit();
//        }
//    }

    Rectangle{
        width: 50
        height: 50
        color: "#ff0000"
        //anchors.right: parent.right
        //anchors.bottom: parent.bottom
        anchors.centerIn: parent
    }
}
