#ifndef SDL2WIDGET_H
#define SDL2WIDGET_H

#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QWidget>
class game : public QWidget {
  Q_OBJECT

public:
  game(QWidget *parent = nullptr);
  ~game();

private:
  QTimer *timer;
  QGraphicsScene *scene = nullptr;
  QGraphicsView *view = nullptr;
  QGraphicsItem *player = nullptr, *computer = nullptr, *fruit = nullptr,
                *animationwindow = nullptr, *toolbar = nullptr, *bgp = nullptr,
                *pauseui = nullptr, *maps = nullptr;
  QWidget *gamewindow = nullptr;
  int ratio;
  void setupScene();
  QGraphicsItem *itemsetup(std::string image, QGraphicsItem *item,
                           QGraphicsScene *scene, int w, int h, qreal x,
                           qreal y, int z);

  // private slots:
  // void update();
};

#endif