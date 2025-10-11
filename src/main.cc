#include "../src/game.h"
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
  game game(&mainwindow);
  /*QVBoxLayout *layout = new QVBoxLayout();
  QHBoxLayout *hlayout = new QHBoxLayout();
  hlayout->addWidget(&game);
  layout->addLayout(hlayout);
  mainwindow.setLayout(layout);*/
  mainwindow.show();

  return app.exec(); // 进入事件循环
}
