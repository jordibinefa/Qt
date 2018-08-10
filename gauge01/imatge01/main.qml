import QtQuick 2.11
import QtQuick.Window 2.11
// How-to at https://wiki.binefa.cat/index.php?title=Making_a_QML_gauge_from_GIMP

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Indicador dissenyat amb GIMP")
    Text {
        anchors.top: parent
        //anchors.centerIn: parent
        //text: "Hello, World!"
        text: valueSource.kph
    }
    ValueSource {
        id: valueSource
    }
    function speed2angle(nV){
        return nV*360/160;
    }
    Indicador00{
        anchors.centerIn: parent
        value: speed2angle(valueSource.kph)
        //transform: Rotation { origin.x: 25; origin.y: 25; angle: valueSource.kph}
    }
}
