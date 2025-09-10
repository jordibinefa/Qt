import QtQuick

Window {
    width: 960
    height: 480
    visible: true
    title: qsTr("ampMeter00_09 - Modular")

    Rectangle {
        id: root
        anchors.fill: parent
        color: "white"

        // Model de dades per als botons
        ListModel {
            id: buttonModel
            ListElement { label: "-60"; value: -45 }
            ListElement { label: "-30"; value: -20 }
            ListElement { label: "0"; value: 0 }
            ListElement { label: "30"; value: 20 }
            ListElement { label: "60"; value: 45 }
        }

        // Component Vista amb els tres AmpMeters
        Vista {
            id: vista
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -40
        }

        // Component Controlador amb BarraLliscant i Botonera
        Controlador {
            id: controlador
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 20

            model: buttonModel

            onSliderValueChanged: function(value) {
                // Converteix el valor (-60 a +60) a rotació (-45 a +45)
                var rotation = (value / 60) * 45
                vista.ampMeter2Rotation = rotation
            }

            onButtonClicked: function(value) {
                // Controla ampMeter1 i ampMeter3
                vista.ampMeter1Rotation = value
                vista.ampMeter3Rotation = value
            }
        }
    }
}
