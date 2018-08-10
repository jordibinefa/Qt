#include <QGuiApplication>
#include <QQmlApplicationEngine>
// How-to at https://wiki.binefa.cat/index.php?title=Making_a_QML_gauge_from_GIMP

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
