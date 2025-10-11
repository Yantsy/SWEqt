#ifndef SDL2WIDGET_H
#define SDL2WIDGET_H
#include <QBrush>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include <QPoint>
#include <QTimer>
#include <QWidget>
#include <QtSvg>
#include <QtSvgWidgets>

class game : public QWidget {
  Q_OBJECT

public:
  explicit game(QWidget *parent = nullptr);
  ~game();

private:
  QTimer *timer;
  QGraphicsScene *scene;
  QGraphicsView *view;
  QGraphicsItem *player, *computer, *fruit, *animationwindow, *toolbar,
      *pauseui, *maps;
  int ratio;
  void setupScene();

  // private slots:
  // void update();
};
void itemsetup(std::string image, QGraphicsItem *item, QGraphicsScene *scene,
               int w, int h, qreal x, qreal y);
#endif