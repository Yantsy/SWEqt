#pragma once

#include <QWidget>

class player : public QWidget {
  Q_OBJECT

public:
  player(QWidget *parent = nullptr);
  ~player();
  void move();

private:
};