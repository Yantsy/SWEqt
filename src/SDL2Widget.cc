#include "../src/SDL2Widget.h"
#include "../src/SwallowAndEscape.h"

#include <iostream>

SDL2WIDGET::SDL2WIDGET(QWidget *parent) : QWidget(parent) {
  setAttribute(Qt::WA_PaintOnScreen);
  setAttribute(Qt::WA_NativeWindow, true);
  setAttribute(Qt::WA_OpaquePaintEvent);
  setMouseTracking(true);
  setUpdatesEnabled(true);
  // initialize SDL video subsystem
  if (SDL_Init(SDL_INIT_VIDEO) != 0 && SDL_Init(SDL_INIT_AUDIO) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
  }
  // initialize SDL_mixer audio subsystem
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
    std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
  }
  // initialize the SDL game controller subsystem
  if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) != 0) {
    std::cerr << "SDL_InitSubSystem Error: " << SDL_GetError() << std::endl;
  }

  window = SDL_CreateWindowFrom((void *)this->winId());

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr) {
    std::cerr << "SDL_CreateRenderer Error:" << SDL_GetError() << std::endl;
  }

  surface = IMG_Load("../assets/food.png");
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  music = Mix_LoadMUS("../assets/bg1.mp3");
  Mix_PlayMusic(music, -1);

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(render()));
  timer->start(1000 / 60);
}
SDL2WIDGET::~SDL2WIDGET() {
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  Mix_FreeMusic(music);
  Mix_Quit();
  SDL_Quit();
}
void keyboard(int *xdir, int *ydir, SDL_Event e) {

  switch (e.key.keysym.scancode) {

  case SDL_SCANCODE_Q: {
    *xdir = 0, *ydir = 0;
    break;
  }

  case SDL_SCANCODE_W:
  case SDL_SCANCODE_UP:
    *ydir = -1, *xdir = 0;
    break;

  case SDL_SCANCODE_S:
  case SDL_SCANCODE_DOWN:
    *ydir = 1, *xdir = 0;
    break;

  case SDL_SCANCODE_A:
  case SDL_SCANCODE_LEFT:
    *xdir = -1, *ydir = 0;
    break;

  case SDL_SCANCODE_D:
  case SDL_SCANCODE_RIGHT:
    *xdir = 1, *ydir = 0;
    break;

  default:
    break;
  }
}
void boundarycheck(SDL_Rect *object, SDL_Rect map) {
  if (object->x < map.x)
    object->x = map.x;
  if (object->x > map.x + map.w - object->w)
    object->x = map.x + map.w - object->w;
  if (object->y < map.y)
    object->y = map.y;
  if (object->y > map.y + map.h - object->w)
    object->y = map.y + map.h - object->w;
};
void SDL2WIDGET::render() {
  SDL_Rect map1, map2, block, cblock, food;
  std::vector<SDL_Rect> segments;
  std::vector<SDL_Rect> csegments;
  std::vector<SDL_Rect> foods;
  std::vector<int> neighbors;
  thickness = 15;
  ww = 1920;
  wh = 1080;
  map1.x = ww / 8;
  map1.y = wh / 16;
  map1.w = ww * 3 / 4;
  map1.h = wh * 3 / 4;

  map2.x = map1.x + thickness;
  map2.y = map1.y + thickness;
  map2.w = map1.w - thickness * 2;
  map2.h = map1.h - thickness * 2;

  pdir = 1;
  ndir = 0;
  cpdir = 1;
  cndir = 0;

  fx = (rand() % (map2.w - map2.x)) + map2.x;
  fy = (rand() % (map2.h - map2.y)) + map2.y;

  block.x = ww / 2;
  block.y = wh / 2;
  block.w = 15;
  block.h = 15;
  speed = block.w / 3;
  segments.push_back(block);
  cblock.x = map2.x;
  cblock.y = map2.y;
  cblock.w = 15;
  cblock.h = 15;
  csegments.push_back(cblock);
  food.x = fx;
  food.y = fy;
  food.w = 15;
  food.h = 15;
  foods.push_back(food);
  SDL_Event e;

  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_KEYDOWN: {
      keyboard(&pdir, &ndir, e);
      break;
    }
    }
  }
  ld = abs(cblock.x - speed - food.x) + abs(cblock.y - food.y);
  rd = abs(cblock.x + speed - food.x) + abs(cblock.y - food.y);
  td = abs(cblock.x - food.x) + abs(cblock.y - speed - food.y);
  bd = abs(cblock.x - food.x) + abs(cblock.y + speed - food.y);

  neighbors = {ld, rd, td, bd};

  md = std::min({neighbors[0], neighbors[1], neighbors[2], neighbors[3]});
  if (md == neighbors[0]) {
    cpdir = -1;
    cndir = 0;
  }
  if (md == neighbors[1]) {
    cpdir = 1;
    cndir = 0;
  }
  if (md == neighbors[2]) {
    cpdir = 0;
    cndir = -1;
  }
  if (md == neighbors[3]) {
    cpdir = 0;
    cndir = 1;
  }
  block.x += pdir * speed;
  block.y += ndir * speed;

  cblock.x += cpdir * speed;
  cblock.y += cndir * speed;

  segments.insert(segments.begin(), block);

  csegments.insert(csegments.begin(), cblock);

  // check for collision with the boundary
  boundarycheck(&block, map2);
  boundarycheck(&cblock, map2);

  // check for collision with food
  if (std::abs(((block.x + 15) / 2) - ((food.x + 15) / 2)) < 5 &&
      std::abs(((block.y + 15) / 2) - ((food.y + 15) / 2)) < 5) {
    // check and start the controller rumble
    /*if (controller != nullptr) {
      SDL_GameControllerRumble(controller, 0x4000, 0x4000, 300);
    } else {
    };*/
    fx = floor(((rand() % (map2.w)) + map2.x) / 15) * 15;
    fy = floor(((rand() % (map2.h)) + map2.y) / 15) * 15;
    food.x = fx;
    food.y = fy;

  } else {
    if (!segments.empty()) {
      segments.pop_back();
    } else {
    }
  }

  if (std::abs(((cblock.x + 15) / 2) - ((food.x + 15) / 2)) < 5 &&
      std::abs(((cblock.y + 15) / 2) - ((food.y + 15) / 2)) < 5) {
    // check and start the controller rumble
    fx = floor(((rand() % (map2.w)) + map2.x) / 15) * 15;
    fy = floor(((rand() % (map2.h)) + map2.y) / 15) * 15;
    food.x = fx;
    food.y = fy;

  } else {
    if (!csegments.empty()) {
      csegments.pop_back();
    } else {
    }
  }

  // check for collision with the boundary of the snake itself
  for (int seg = 0; seg < segments.size(); seg++) {
    if (std::abs(block.x - segments[seg].x) < 15 &&
        std::abs(block.y - segments[seg].y) < 15) {
    }
  }
  for (int seg = 0; seg < csegments.size(); seg++) {
    if (std::abs(block.x - csegments[seg].x) < 15 &&
        std::abs(block.y - csegments[seg].y) < 15) {
    }
  }

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 254, 253, 202, 200);
  SDL_RenderFillRect(renderer, &map1);

  SDL_SetRenderDrawColor(renderer, 224, 249, 181, 255);
  SDL_RenderFillRect(renderer, &map2);

  for (auto &segsheet : segments) {
    if (&segsheet == &segments[0]) {
      SDL_SetRenderDrawColor(renderer, 255, 69, 69, 255);
      SDL_RenderFillRect(renderer, &block);
      continue;
    };
    SDL_SetRenderDrawColor(renderer, 255, 207, 223, 255);
    SDL_RenderFillRect(renderer, &segsheet);
  };

  for (auto &csegsheet : csegments) {
    if (&csegsheet == &csegments[0]) {
      SDL_SetRenderDrawColor(renderer, 47, 79, 79, 255);
      SDL_RenderFillRect(renderer, &cblock);
      continue;
    };
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
    SDL_RenderFillRect(renderer, &csegsheet);
  };

  SDL_RenderCopy(renderer, texture, NULL, &food);
  SDL_RenderPresent(renderer);
}