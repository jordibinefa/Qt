import QtQuick 2.9
import QtQuick.Controls 2.2
// Per a que funcioni he hagut d'anar a Build/Run qmake

Rectangle {
    id: giny
    width:450
    height:450
    property alias value: capabusca.rotation
    Image {
        source:"qrc:/imatges/imatges/fons.png"
        id:fons
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capablanca.png"
        id:capablanca
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capafosca.png"
        id:capafosca
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capavoraexterior.png"
        id:capavoraexterior
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capabisellinterior.png"
        id:capabisellinterior
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capavorainterior.png"
        id:capavorainterior
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capabusca.png"
        id:capabusca
        x:0 ; y:0
        width:450
        height:450
        rotation: 0
    }
    Image {
        source:"qrc:/imatges/imatges/capabrillant.png"
        id:capabrillant
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capaliniesindicador.png"
        id:capaliniesindicador
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capaliniesindicador02.png"
        id:capaliniesindicador02
        x:-1522 ; y:-1522
        width:3494
        height:3494
    }
    Image {
        source:"qrc:/imatges/imatges/capaliniesblanquesindicador02.png"
        id:capaliniesblanquesindicador02
        x:-1522 ; y:-1522
        width:3494
        height:3494
    }
    Image {
        source:"qrc:/imatges/imatges/capabisellexterior.png"
        id:capabisellexterior
        x:0 ; y:0
        width:450
        height:450
    }
    Image {
        source:"qrc:/imatges/imatges/capanumerosindicador.png"
        id:capanumerosindicador
        x:0 ; y:0
        width:450
        height:450
    }
}
