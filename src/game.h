#ifndef SDL2WIDGET_H
#define SDL2WIDGET_H
#include <QBrush>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
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
  QGraphicsItem *player, *computer, *map, *fruit;
  QGraphicsSvgItem *maptexture;
  void setupScene();

  // private slots:
  // void update();
};
#endif