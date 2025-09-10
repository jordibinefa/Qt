// Botonera.qml
import QtQuick

Row {
    id: botonera
    spacing: 20

    // Propietat per rebre el model des del pare
    property alias model: repeater.model

    // Signal per comunicar el clic al component pare
    signal buttonClicked(real value)

    Repeater {
        id: repeater

        Rectangle {
            width: 60
            height: 60
            radius: 30
            color: "gray"

            Text {
                anchors.centerIn: parent
                text: model.label
                color: "white"
                font.pixelSize: 14
                font.bold: true
            }

            MouseArea {
                anchors.fill: parent
                onClicked: botonera.buttonClicked(model.value)
                cursorShape: Qt.PointingHandCursor
            }
        }
    }
}
