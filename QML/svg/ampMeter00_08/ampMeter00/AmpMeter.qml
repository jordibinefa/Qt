// AmpMeter.qml
import QtQuick

Item {
    id: ampMeter

    // Propietat per controlar la rotació de l'agulla des del pare
    property alias rotation: agullaSvg.rotation

    // Propietats per personalitzar les imatges (opcional)
    property string fondoSource: "qrc:/material/AmpMeterFons_c.svg"
    property string agullaSource: "qrc:/material/AmpMeterAgulla_c.svg"
    property real agullaOpacity: 0.8

    // Imatge de fons
    Image {
        id: fonsSvg
        source: ampMeter.fondoSource
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
    }

    // Imatge de l'agulla
    Image {
        id: agullaSvg
        source: ampMeter.agullaSource
        fillMode: Image.PreserveAspectFit
        opacity: ampMeter.agullaOpacity
        anchors.centerIn: parent

        rotation: 0 // -45 -20 0 20 45

        Behavior on rotation {
            id: rotationBehavior
            NumberAnimation {
                duration: 300
                easing.type: Easing.InOutBack
            }
        }
    }
}
