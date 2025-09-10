import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ampMeter00_01")

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
           // Fila de botons de control a la part inferior
           Row {
               id: controlButtons
               anchors.bottom: parent.bottom
               anchors.horizontalCenter: parent.horizontalCenter
               anchors.bottomMargin: 20
               spacing: 20

               // Botó -60A
               Rectangle {
                   width: 60
                   height: 60
                   radius: 30
                   color: "gray"

                   Text {
                       anchors.centerIn: parent
                       text: "-60"
                       color: "white"
                       font.pixelSize: 14
                       font.bold: true
                   }

                   MouseArea {
                       anchors.fill: parent
                       onClicked: agullaSvg.rotation = -45
                       cursorShape: Qt.PointingHandCursor
                   }
               }
               // Botó -30A
               Rectangle {
                   width: 60
                   height: 60
                   radius: 30
                   color: "gray"

                   Text {
                       anchors.centerIn: parent
                       text: "-30"
                       color: "white"
                       font.pixelSize: 14
                       font.bold: true
                   }

                   MouseArea {
                       anchors.fill: parent
                       onClicked: agullaSvg.rotation = -20
                       cursorShape: Qt.PointingHandCursor
                   }
               }
               // Botó 0A
               Rectangle {
                   width: 60
                   height: 60
                   radius: 30
                   color: "gray"

                   Text {
                       anchors.centerIn: parent
                       text: "0"
                       color: "white"
                       font.pixelSize: 14
                       font.bold: true
                   }

                   MouseArea {
                       anchors.fill: parent
                       onClicked: agullaSvg.rotation = 0
                       cursorShape: Qt.PointingHandCursor
                   }
               }
               // Botó 30A
               Rectangle {
                   width: 60
                   height: 60
                   radius: 30
                   color: "gray"

                   Text {
                       anchors.centerIn: parent
                       text: "30"
                       color: "white"
                       font.pixelSize: 14
                       font.bold: true
                   }

                   MouseArea {
                       anchors.fill: parent
                       onClicked: agullaSvg.rotation = 20
                       cursorShape: Qt.PointingHandCursor
                   }
               }
               // Botó 60A
               Rectangle {
                   width: 60
                   height: 60
                   radius: 30
                   color: "gray"

                   Text {
                       anchors.centerIn: parent
                       text: "60"
                       color: "white"
                       font.pixelSize: 14
                       font.bold: true
                   }

                   MouseArea {
                       anchors.fill: parent
                       onClicked: agullaSvg.rotation = 45
                       cursorShape: Qt.PointingHandCursor
                   }
               }
           }
       }
}
