#!/usr/bin/env python3
import sys
import os
from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine
from PySide6.QtCore import QUrl

# Importar els recursos compilats
# pyside6-rcc recursos.qrc -o rc_recursos.py
import rc_recursos

def main():
    app = QGuiApplication(sys.argv)
    
    engine = QQmlApplicationEngine()
    
    # Afegir el directori actual al path de cerca de QML
    current_dir = os.path.dirname(os.path.abspath(__file__))
    engine.addImportPath(current_dir)
    
    # Carregar el fitxer QML principal des del sistema de fitxers
    qml_file = os.path.join(current_dir, "main.qml")
    engine.load(QUrl.fromLocalFile(qml_file))
    
    # Verificar que el QML s'ha carregat correctament
    if not engine.rootObjects():
        print("Error: No s'ha pogut carregar main.qml")
        return -1
    
    return app.exec()

if __name__ == "__main__":
    sys.exit(main())
