// BarraLliscant.qml
import QtQuick

Column {
    id: barraLliscant
    spacing: 10

    // Propietats configurables des del pare
    property real minValue: -60
    property real maxValue: 60
    property real currentValue: 0
    property int sliderWidth: 200
    property int sliderHeight: 30

    // Signal per comunicar el canvi de valor al component pare
    signal valueChanged(real value)

    // Etiquetes del slider
    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: barraLliscant.sliderWidth - 40

        Text {
            text: barraLliscant.minValue.toString()
            color: "black"
            font.pixelSize: 12
            font.bold: true
        }

        Text {
            text: "+" + barraLliscant.maxValue.toString()
            color: "black"
            font.pixelSize: 12
            font.bold: true
        }
    }

    // Slider
    Rectangle {
        width: barraLliscant.sliderWidth
        height: barraLliscant.sliderHeight
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

            MouseArea {
                anchors.fill: parent
                drag.target: sliderHandle
                drag.axis: Drag.XAxis
                drag.minimumX: 0
                drag.maximumX: parent.parent.width - sliderHandle.width

                onPositionChanged: {
                    if (drag.active) {
                        // Calcula el valor del slider (minValue a maxValue)
                        var relativePos = sliderHandle.x / (parent.parent.width - sliderHandle.width)
                        var value = barraLliscant.minValue + (relativePos * (barraLliscant.maxValue - barraLliscant.minValue))
                        barraLliscant.currentValue = value

                        // Emet el signal amb el valor calculat
                        barraLliscant.valueChanged(value)
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
        text: Math.round(barraLliscant.currentValue) + "A"
        color: "black"
        font.pixelSize: 14
        font.bold: true
    }
}
