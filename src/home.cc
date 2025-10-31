#include "home.h"
#include "game.h"
#include <iostream>
home::home(QWidget *parent) : QWidget(parent) {
  // 游戏主逻辑

  setupHomeUI();

  if (startbutton) {
    std::cout << "[v0] startbutton is valid, connecting signal" << std::endl;
    connect(startbutton, &QPushButton::clicked, this, &home::startGame);
  } else {
    std::cerr << "[v0] ERROR: startbutton is nullptr!" << std::endl;
  }
}

home::~home() { std::cout << "program over" << std::endl; };

void home::setupHomeUI() {
  // homepalette settup
  this->resize(2015 / 3, 1365 / 3);
  this->setWindowTitle("Swallow And Escape");
  homebgp = QPixmap(":/assets/bgp.png")
                .scaled(this->size(), Qt::IgnoreAspectRatio,
                        Qt::SmoothTransformation);
  // icon setup
  /*icon.resize(128, 128);
  icon.setPixmap(QPixmap(":/assets/icon.png")
                     .scaled(icon.size(), Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation));
  icon.move(this->width() - icon.width(), 0);
  icon.setParent(this);*/

  movie = new QMovie(":/assets/icon.gif");
  movie->setScaledSize(QSize(128, 128));
  movielabel.setParent(this);
  movielabel.resize(128, 128);
  movielabel.setMovie(movie);
  movielabel.move(this->width() - movielabel.width(), 0);
  // movielabel.show();
  movie->start();
  homepalette.setBrush(this->backgroundRole(), QBrush(homebgp));

  this->setPalette(homepalette);
  // buttons setup
  startbutton = buttonsetup(startbutton, "Start", this, 10, 20, 140, 25);
  continuebutton =
      buttonsetup(continuebutton, "Continue", this, 10, 60, 140, 25);
  settingbutton = buttonsetup(settingbutton, "Setting", this, 10, 100, 140, 25);
  quitgamebutton =
      buttonsetup(quitgamebutton, "Quit Game", this, 10, 140, 140, 25);
}

void home::startGame() {
  std::cout << "[v0] startGame called" << std::endl;
  game *gamepage = new game();

  gamepage->show();
  this->close();
}
QPushButton *home::buttonsetup(QPushButton *button, std::string text,
                               QWidget *parent, int x, int y, int w, int h) {
  button = new QPushButton(QString::fromStdString(text), parent);
  button->setGeometry(x, y, w, h);
  return button;
}
