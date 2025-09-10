import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ampMeter00_05")

    Rectangle {
        id: root
        anchors.fill: parent
        color: "white"

        // Component AmpMeter que conté les dues imatges
        AmpMeter {
            id: ampMeter
            anchors.centerIn: parent
            width: parent.width
            height: parent.height
        }

        // Model de dades per als botons
        ListModel {
            id: buttonModel
            ListElement { label: "-60"; value: -45 }
            ListElement { label: "-30"; value: -20 }
            ListElement { label: "0"; value: 0 }
            ListElement { label: "30"; value: 20 }
            ListElement { label: "60"; value: 45 }
        }

        // Component Botonera a la part inferior
        Botonera {
            id: controlButtons
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 20

            model: buttonModel

            onButtonClicked: function(value) {
                ampMeter.rotation = value
            }
        }
    }
}
