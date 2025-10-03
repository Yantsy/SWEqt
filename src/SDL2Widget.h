#ifndef SDL2WIDGET_H
#define SDL2WIDGET_H
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

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Texture *texture;

private:
  QTimer *timer;
  int ww, wh;
  int thickness = 15;

private slots:
  void render();
};
#endif