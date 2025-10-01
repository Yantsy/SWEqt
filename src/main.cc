#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QWidget>
#include <qdrawutil.h>
int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.resize(1920, 1080);                   // 设置窗口大小
  window.setWindowTitle("Swallow And Escape"); // 设置标题
  window.show();                               // 显示窗口

  QPushButton *button = new QPushButton("Start", &window);
  button->setFixedSize(window.width() / 4, window.height() / 20);
  button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

  QLabel *label = new QLabel("Type in your name:");

  QLineEdit *lineedit = new QLineEdit("have fun");

  QVBoxLayout *mainlayout = new QVBoxLayout(&window);

  QHBoxLayout *layout = new QHBoxLayout();

  layout->addWidget(label);
  layout->addWidget(lineedit);
  mainlayout->addLayout(layout);
  mainlayout->addWidget(button, 0, Qt::AlignCenter);

  return app.exec(); // 进入事件循环
}
