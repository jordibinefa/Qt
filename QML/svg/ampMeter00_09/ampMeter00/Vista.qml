// Vista.qml
import QtQuick

Row {
    id: vista
    spacing: 20

    // Propietats per controlar les rotacions dels AmpMeters des del pare
    property alias ampMeter1Rotation: ampMeter1.rotation
    property alias ampMeter2Rotation: ampMeter2.rotation
    property alias ampMeter3Rotation: ampMeter3.rotation

    // Propietats per personalitzar els AmpMeters (opcional)
    property real ampMeter1Scale: 0.5
    property real ampMeter2Scale: 0.8
    property real ampMeter3Scale: 0.5

    AmpMeter {
        id: ampMeter1
        width: 280
        height: 280
        scale: vista.ampMeter1Scale
        easingType: Easing.InOutQuad
    }

    AmpMeter {
        id: ampMeter2
        width: 280
        height: 280
        scale: vista.ampMeter2Scale
        easingType: Easing.InOutBack
    }

    AmpMeter {
        id: ampMeter3
        width: 280
        height: 280
        scale: vista.ampMeter3Scale
        easingType: Easing.InOutCubic
    }
}
