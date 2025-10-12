#include "game.h"
#include <iostream>

game::game(QWidget *parent) : QWidget(parent) {
  // 游戏主逻辑
  std::cout << "[v0] game constructor started" << std::endl;
  setupScene();
  std::cout << "[v0] game constructor completed" << std::endl;
  /*timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(1000 / 60);*/
}
void game::setupScene() {

  gamewindow = new QWidget(this);
  //   scene setup
  //  gamewindow->resize(1920, 1080);
  gamewindow->setWindowTitle("Swallow And Escape - Game");

  scene = new QGraphicsScene(gamewindow);
  scene->setSceneRect(0, 0, 1920, 1080);
  scene->setBackgroundBrush(QBrush(QColor(2, 2, 2, 125)));

  // view setup
  view = new QGraphicsView(scene, gamewindow);
  view->setRenderHints(QPainter::Antialiasing |
                       QPainter::SmoothPixmapTransform);
  view->setFixedSize(1920, 1080);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setFrameShape(QFrame::NoFrame);
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);

  // items setup scale: 0.96, 0.915
  itemsetup("maps.png", maps, scene, 1249, 669, 70, 65, 2);
  itemsetup("maps.png", animationwindow, scene, 449, 669, 1364, 65, 2);
  itemsetup("maps.png", toolbar, scene, 1743, 200, 70, 769, 2);
  itemsetup("bgp.jpg", bgp, scene, 3508 * 0.75, 2408 * 0.75, 0, 0, 1);

  view->show();
  gamewindow->show();
}
game::~game() {
  std::cout << "game over" << std::endl;
  // delete timer;
  // delete scene;
  // delete view;
  // delete player;
  // delete computer;
  // delete fruit;
  // delete animationwindow;
  // delete toolbar;
  // delete pauseui;
  // delete maps;
  // delete bgp;
}
QGraphicsItem *game::itemsetup(std::string image, QGraphicsItem *item,
                               QGraphicsScene *scene, int w, int h, qreal x,
                               qreal y, int z) {
  QString imgpath = QString(":/assets/") + QString::fromStdString(image);
  QPixmap preimage(imgpath);
  item = scene->addPixmap(QPixmap(
      preimage.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
  item->setPos(x, y);
  item->setZValue(z);
  return item;
}