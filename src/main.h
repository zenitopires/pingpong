#include "common.h"

extern void cleanup(void);
extern void init(char* string);
extern void prepareScene(void);
extern void presentScene(void);
//extern void drawTex(SDL_Texture* texture, int x, int y);
//extern SDL_Texture* loadTex(char* filename);
extern Mix_Chunk* loadSoundEffect(char* filename);
extern void cleanup_audio(Mix_Chunk* soundEffect);
extern void playerPositions(Paddle* player1, Paddle* player2);
extern void playerBounds(Paddle* player);
extern void capFramerate(long* then, float* remainder);
extern float calcAngle(float, float, float);
extern Ball new_Ball(Ball ball);
extern void paddleHit(Ball* ball, Paddle* player);
extern void blitRect(SDL_Renderer* renderer, const SDL_Rect* rect);
extern void getInput(void);

App app;

Paddle* player1, *player2;
