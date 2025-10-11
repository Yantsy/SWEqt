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
  scene->setBackgroundBrush(QBrush(QColor(2, 2, 2, 125)));

  // view setup
  view = new QGraphicsView(scene, this);
  view->setRenderHints(QPainter::Antialiasing |
                       QPainter::SmoothPixmapTransform);
  view->setFixedSize(1920, 1080);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setFrameShape(QFrame::NoFrame);
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);

  // items setup scale: 0.96, 0.915
  itemsetup("maps", maps, scene, 1249, 669, 70, 65);
  itemsetup("maps", animationwindow, scene, 449, 669, 1364, 65);
  itemsetup("maps", toolbar, scene, 1743, 200, 70, 769);

  view->show();
}
void itemsetup(std::string image, QGraphicsItem *item, QGraphicsScene *scene,
               int w, int h, qreal x, qreal y) {
  QString imgpath =
      QString(":/assets/") + QString::fromStdString(image) + QString(".png");
  QPixmap preimage(imgpath);
  item = scene->addPixmap(QPixmap(
      preimage.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
  item->setPos(x, y);
}