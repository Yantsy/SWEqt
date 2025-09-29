import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Simple Qt Quick App"

    Button {
        text: "Click me"
        anchors.centerIn: parent
        onClicked: {
            Qt.callLater(() => {
                Qt.toast("Button clicked!")
            })
        }
    }
}


