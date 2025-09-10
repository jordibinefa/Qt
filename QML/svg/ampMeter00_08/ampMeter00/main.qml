import QtQuick

Window {
    width: 960
    height: 480
    visible: true
    title: qsTr("ampMeter00_08 - Triple")

    Rectangle {
        id: root
        anchors.fill: parent
        color: "white"

        // Fila amb tres components AmpMeter
        Row {
            id: ampMetersRow
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -40  // Mou una mica cap amunt per deixar espai als botons
            spacing: 20

            AmpMeter {
                id: ampMeter1
                width: 280
                height: 280
                scale: 0.5
            }

            AmpMeter {
                id: ampMeter2
                width: 280
                height: 280
                scale: 0.8
            }

            AmpMeter {
                id: ampMeter3
                width: 280
                height: 280
                scale: 0.5
            }
        }

        // Component BarraLliscant per controlar ampMeter2
        BarraLliscant {
            id: barraLliscant
            anchors.bottom: controlButtons.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 30

            minValue: -60
            maxValue: 60
            sliderWidth: 200
            sliderHeight: 30

            onValueChanged: function(value) {
                // Converteix el valor (-60 a +60) a rotació (-45 a +45)
                var rotation = (value / 60) * 45
                ampMeter2.rotation = rotation
            }
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
                // Controla només ampMeter1 i ampMeter3
                ampMeter1.rotation = value
                ampMeter3.rotation = value
            }
        }
    }
}
