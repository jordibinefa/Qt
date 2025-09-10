import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ampMeter00_03")

    Rectangle {
        id: root
        anchors.fill: parent
        color: "white"

        // Afegeix l'element Image
        Image {
            id: fonsSvg
            source: "qrc:/material/AmpMeterFons_c.svg"

            // `PreserveAspectFit` manté les proporcions originals de la imatge.
            fillMode: Image.PreserveAspectFit

            // Centra l'element Image en l'element pare (en aquest cas, el Rectangle `root`).
            anchors.centerIn: parent
        }
        Image {
            id: agullaSvg
            source: "qrc:/material/AmpMeterAgulla_c.svg"

            // `PreserveAspectFit` manté les proporcions originals de la imatge.
            fillMode: Image.PreserveAspectFit
            opacity: 0.8
            // Centra l'element Image en l'element pare (en aquest cas, el Rectangle `root`).
            anchors.centerIn: parent

            rotation: 0 // -45 -20 0 20 45

            Behavior on rotation {
                NumberAnimation {
                    duration: 300
                    //easing.type: Easing.InOutQuad
                    easing.type: Easing.InOutBack
                }
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

        // Fila de botons de control a la part inferior
        Row {
            id: controlButtons
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 20
            spacing: 20

            Repeater {
                model: buttonModel

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
                        onClicked: agullaSvg.rotation = model.value
                        cursorShape: Qt.PointingHandCursor
                    }
                }
            }
        }
    }
}
