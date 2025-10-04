#ifndef SDL2WIDGET_H
#define SDL2WIDGET_H
#include <QTimer>
#include <QWidget>
#include <SDL2/SDL.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

class SDL2WIDGET : public QWidget {
  Q_OBJECT

public:
  SDL2WIDGET(QWidget *parent = nullptr);
  ~SDL2WIDGET();
  QPaintEngine *paintEngine() const override { return nullptr; }

  void paintEvent(QPaintEvent *event) override { Q_UNUSED(event); }

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Texture *texture;
  Mix_Music *music;
  SDL_Rect map1, map2, block, cblock, food;
  std::vector<SDL_Rect> segments;
  std::vector<SDL_Rect> csegments;
  std::vector<SDL_Rect> foods;

private:
  QTimer *timer;
  int ww, wh;
  int thickness;
  int ndir, pdir, cndir, cpdir;
  int fx, fy;
  int ld, rd, td, bd, md;
  int speed;

private slots:
  void render();
};
#endif