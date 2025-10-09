#include "../src/game.h"
#include <iostream>

game::game(QWidget *parent) : QWidget(parent) {
  // 游戏主逻辑
  setupScene();

  /*timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(1000 / 60);*/
}
game::~game() { std::cout << "game over" << std::endl; }

void game::setupScene() {
  scene = new QGraphicsScene(this);
  scene->setSceneRect(0, 0, 1920 * 0.75, 1080 * 0.75);
  scene->setBackgroundBrush(QBrush(QColor(177, 226, 255, 0)));
  maptexture = new QGraphicsSvgItem(":/assets/m1.svg");

  scene->addItem(maptexture);

  view = new QGraphicsView(scene, this);
  view->setRenderHints(QPainter::Antialiasing |
                       QPainter::SmoothPixmapTransform);
  view->resize(scene->sceneRect().width(), scene->sceneRect().height());
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setFrameShape(QFrame::NoFrame);
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
  maptexture->setTransform(
      QTransform().scale(scene->width() / maptexture->boundingRect().width() /
                             view->transform().m11(),
                         scene->height() / maptexture->boundingRect().height() /
                             view->transform().m22()));

  view->show();
}
