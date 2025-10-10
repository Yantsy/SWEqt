#include "../src/game.h"
#include <iostream>

game::game(QWidget *parent) : QWidget(parent) {
  // 游戏主逻辑
  setupScene();

  /*timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(1000 / 60);*/
}
game::~game() {
  std::cout << "game over" << std::endl;
  // delete timer;
  delete scene;
  delete view;
  // delete player;
  // delete computer;
  // delete fruit;
  // delete animationwindow;
  // delete toolbar;
  // delete pauseui;
  // delete maps;
}

void game::setupScene() {

  // scene setup
  scene = new QGraphicsScene(this);
  scene->setSceneRect(0, 0, 1920, 1080);
  scene->setBackgroundBrush(QBrush(QColor(177, 226, 255, 125)));

  // items setup
  maps = new QGraphicsPixmapItem(QPixmap(":/assets/m1.png"));

  // view setup
  view = new QGraphicsView(scene, this);
  view->setRenderHints(QPainter::Antialiasing |
                       QPainter::SmoothPixmapTransform);
  view->resize(scene->sceneRect().width(), scene->sceneRect().height());
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setFrameShape(QFrame::NoFrame);
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

  // add items to the scene
  scene->addItem(maps);

  // set item scale
  retransform(maps, view->transform(), 1920, 1080, 20, 0);

  view->show();
}

void retransform(QGraphicsItem *item, QTransform t, int w, int h, qreal dx,
                 qreal dy) {
  QTransform t1;
  qreal rx = w / item->boundingRect().width();
  qreal ry = h / item->boundingRect().height();

  item->setTransform(QTransform().scale(rx, ry).translate(dx, dy));
}