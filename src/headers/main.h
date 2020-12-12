#include "common.h"

extern void CleanUp(void);
extern void Init(char* string);
extern void PrepareScene(void);
extern void PresentScene(void);
//extern void drawTex(SDL_Texture* texture, int x, int y);
//extern SDL_Texture* loadTex(char* filename);
extern Mix_Chunk* LoadSoundEffect(char* filename);
extern void CleanupAudio(Mix_Chunk* soundEffect);
extern void PlayerPositions(Paddle* player1, Paddle* player2);
extern void PlayerBounds(Paddle* player);
extern void CapFramerate(long* then, float* remainder);
extern float calcAngle(float, float, float);
extern char* toString(char str[], int num);
extern Ball BallPosition(Ball ball);
extern void BallProps(SDL_Rect* ball_rect, Ball* ball);
extern void paddleHit(Ball* ball, Paddle* player);

// Utility
extern void CollisionCheck(Ball* ball, SDL_Rect* ball_rect,
                           Paddle* player1, Paddle* player2,
                           Mix_Chunk* pingHit);
extern void TrackBall(Ball* ball, Paddle* bot);
extern void SetSpeed(Paddle* player1, Paddle* player2);
void SetScore(Paddle* player1, Paddle* player2);

// Drawing
extern void BlitRect(SDL_Renderer* renderer, const SDL_Rect* rect);
extern void DrawFont(SDL_Texture* fontTexture, int x, int y);
extern SDL_Texture* LoadFont(char* filename, char buffer[]);

extern void GetInput(void);

App app;

Paddle* player1, *player2;