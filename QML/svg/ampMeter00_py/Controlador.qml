// Controlador.qml
import QtQuick

Column {
    id: controlador
    spacing: 30

    // Propietat per rebre el model des del pare
    property alias model: botonera.model

    // Signals per comunicar els canvis al component pare
    signal sliderValueChanged(real value)
    signal buttonClicked(real value)

    // Component BarraLliscant
    BarraLliscant {
        id: barraLliscant
        anchors.horizontalCenter: parent.horizontalCenter

        minValue: -60
        maxValue: 60
        sliderWidth: 200
        sliderHeight: 30

        onValueChanged: function(value) {
            controlador.sliderValueChanged(value)
        }
    }

    // Component Botonera
    Botonera {
        id: botonera
        anchors.horizontalCenter: parent.horizontalCenter

        onButtonClicked: function(value) {
            controlador.buttonClicked(value)
        }
    }
}
