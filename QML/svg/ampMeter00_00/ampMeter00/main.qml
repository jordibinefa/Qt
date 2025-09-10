import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ampMeter00")

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

               // Centra l'element Image en l'element pare (en aquest cas, el Rectangle `root`).
               anchors.centerIn: parent

               Component.onCompleted: {
                   transformOrigin = Qt.point(width/2, height-10) // Seguir per aqui
               }
               // anchors.verticalCenterOffset: -50  // Compensa movent l'agulla cap amunt
               rotation: 45 // -45 -20 0 20 45
           }
       }
}
