#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("mainwindow.qml"))); // 使用资源路径

  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
