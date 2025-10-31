#pragma once

#include <QBrush>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include <QImageReader>
#include <QMovie>
#include <QPalette>
#include <QPoint>
#include <QPushButton>
#include <QTimer>
#include <QWidget>
#include <QtSvg>
#include <QtSvgWidgets>
class home : public QWidget {
  Q_OBJECT
public:
  home(QWidget *parent = nullptr);
  ~home();

private:
  QTimer *timer = nullptr;
  QPushButton *startbutton = nullptr, *continuebutton = nullptr,
              *loadbutton = nullptr, *settingbutton = nullptr,
              *rankbutton = nullptr, *quitgamebutton = nullptr;
  QLabel icon, movielabel;
  QMovie *movie;
  QPixmap homebgp;
  QPalette homepalette;
  // game *gamepage = new game();

  int ratio;
  void setupHomeUI();
  QPushButton *buttonsetup(QPushButton *button, std::string text,
                           QWidget *parent, int x, int y, int w, int h);
private slots:
  void startGame();
  //  void update();
};
