#include "../src/SDL2Widget.h"
#include <QApplication>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSizePolicy>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget mainwindow;
  mainwindow.resize(1920, 1080);
  mainwindow.setWindowTitle("Swallow And Escape");
  QWidget *sdlwidgetcontainer = new QWidget(&mainwindow);
  sdlwidgetcontainer->setMinimumSize(1920, 1080);
  SDL2WIDGET *widget = new SDL2WIDGET(sdlwidgetcontainer);
  QGridLayout *gridlayout = new QGridLayout();
  gridlayout->addWidget(widget);
  sdlwidgetcontainer->setLayout(gridlayout);

  mainwindow.show();

  return app.exec(); // 进入事件循环
}
