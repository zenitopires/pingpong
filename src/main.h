#include "common.h"

extern void cleanup(void);
extern void init(char* string);
extern void prepareScene(void);
extern void presentScene(void);
//extern void drawTex(SDL_Texture* texture, int x, int y);
//extern SDL_Texture* loadTex(char* filename);
extern Ball new_Ball(Ball ball);
extern void paddleHit(Ball* ball, Paddle* player);
extern void blitRect(SDL_Renderer* renderer, const SDL_Rect* rect);
extern void getInput(void);

App app;

Paddle* player1, *player2;