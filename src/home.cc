#include "home.h"
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
  // home button setup
  this->resize(680, 480);
  this->setWindowTitle("Swallow And Escape");
  homebgp = QPixmap(":/assets/bgp.jpg")
                .scaled(this->size(), Qt::IgnoreAspectRatio,
                        Qt::SmoothTransformation);
  homepalette.setBrush(this->backgroundRole(), QBrush(homebgp));
  this->setPalette(homepalette);
  startbutton = new QPushButton("Start Game", this);
  startbutton->setGeometry(270, 100, 140, 40);
  buttonsetup(continuebutton, "Continue", this, 270, 160, 140, 40);
  buttonsetup(loadbutton, "Load Game", this, 270, 220, 140, 40);
  buttonsetup(settingbutton, "Setting", this, 270, 280, 140, 40);
  buttonsetup(rankbutton, "Rank", this, 270, 340, 140, 40);
  buttonsetup(quitgamebutton, "Quit Game", this, 270, 400, 140, 40);
}

void home::startGame() {
  std::cout << "[v0] startGame called" << std::endl;
  game *gamepage = new game();

  gamepage->show();
  this->showMinimized();
}
QPushButton *home::buttonsetup(QPushButton *button, std::string text,
                               QWidget *parent, int x, int y, int w, int h) {
  button = new QPushButton(QString::fromStdString(text), parent);
  button->setGeometry(x, y, w, h);
  return button;
}