#include "../src/home.h"
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
  home home;
  /*QVBoxLayout *layout = new QVBoxLayout();
  QHBoxLayout *hlayout = new QHBoxLayout();
  hlayout->addWidget(&game);
  layout->addLayout(hlayout);
  mainwindow.setLayout(layout);*/
  home.show();

  return app.exec(); // 进入事件循环
}
