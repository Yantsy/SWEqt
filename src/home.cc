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
  this->resize(3140 / 4, 2560 / 4);
  this->setWindowTitle("Swallow And Escape");
  homebgp = QPixmap(":/assets/bgp.png")
                .scaled(this->size(), Qt::IgnoreAspectRatio,
                        Qt::SmoothTransformation);
  homepalette.setBrush(this->backgroundRole(), QBrush(homebgp));
  this->setPalette(homepalette);
  // buttons setup
  startbutton = buttonsetup(startbutton, "Start Game", this, 322, 100, 140, 40);
  continuebutton =
      buttonsetup(continuebutton, "Continue", this, 322, 160, 140, 40);
  loadbutton = buttonsetup(loadbutton, "Load Game", this, 322, 220, 140, 40);
  settingbutton =
      buttonsetup(settingbutton, "Setting", this, 322, 280, 140, 40);
  rankbutton = buttonsetup(rankbutton, "Rank", this, 322, 340, 140, 40);
  quitgamebutton =
      buttonsetup(quitgamebutton, "Quit Game", this, 322, 400, 140, 40);
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