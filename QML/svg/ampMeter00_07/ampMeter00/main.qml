import QtQuick

Window {
    width: 960
    height: 480
    visible: true
    title: qsTr("ampMeter00_07 - Triple")

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

        // Slider per controlar ampMeter2
        Column {
            id: sliderContainer
            anchors.bottom: controlButtons.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 30
            spacing: 10

            // Etiquetes del slider
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 140

                Text {
                    text: "-60"
                    color: "black"
                    font.pixelSize: 12
                    font.bold: true
                }

                Text {
                    text: "+60"
                    color: "black"
                    font.pixelSize: 12
                    font.bold: true
                }
            }

            // Slider
            Rectangle {
                width: 200
                height: 30
                color: "lightgray"
                radius: 15
                anchors.horizontalCenter: parent.horizontalCenter

                Rectangle {
                    id: sliderHandle
                    width: 20
                    height: 20
                    radius: 10
                    color: "darkgray"
                    anchors.verticalCenter: parent.verticalCenter
                    x: (parent.width - width) / 2  // Posició inicial al centre

                    property real value: 0  // Valor del slider (-60 a +60)

                    MouseArea {
                        anchors.fill: parent
                        drag.target: sliderHandle
                        drag.axis: Drag.XAxis
                        drag.minimumX: 0
                        drag.maximumX: parent.parent.width - sliderHandle.width

                        onPositionChanged: {
                            if (drag.active) {
                                // Calcula el valor del slider (-60 a +60)
                                var relativePos = sliderHandle.x / (parent.parent.width - sliderHandle.width)
                                sliderHandle.value = -60 + (relativePos * 120)

                                // Converteix a rotació (-45 a +45)
                                var rotation = -45 + (relativePos * 90)
                                ampMeter2.rotation = rotation
                            }
                        }
                    }
                }

                // Línia central de referència
                Rectangle {
                    width: 2
                    height: parent.height
                    color: "gray"
                    anchors.centerIn: parent
                }
            }

            // Valor actual del slider
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: Math.round(sliderHandle.value) + "A"
                color: "black"
                font.pixelSize: 14
                font.bold: true
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
