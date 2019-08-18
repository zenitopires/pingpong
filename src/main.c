#include "init.h"
#include "main.h"

static void playerBounds(void);
static void playerPositions(Paddle* player1, Paddle* player2);

int main()
{
    memset(&app, 0, sizeof(App));
    memset(&player1, 0, sizeof(Paddle));
    memset(&player2, 0, sizeof(Paddle));

    init("Ping Pong by Zenito Pires");

    player1 = malloc(sizeof(Paddle));
    player2 = malloc(sizeof(Paddle));

    Ball ball;
    ball = new_Ball(ball);

    SDL_Rect ball_rect;
    ball_rect.w = 10;
    ball_rect.h = 10;
    ball_rect.x = ball.x;
    ball_rect.y = ball.y;

    playerPositions(player1, player2);

    player1->speed = 15;
    player2->speed = 3.5;

    // Game loop
    app.running = true;
    while (app.running) {
        prepareScene();

        getInput();

        if (app.up) {
            player1->position.y -= player1->speed;
        }
        if (app.down) {
            player1->position.y += player1->speed;
        }

        ball.x += ball.vx;
        ball.y += ball.vy;
        ball_rect.x = (int) ball.x;
        ball_rect.y = (int) ball.y;

        if (ball.y < 0) {
            ball.y = 0;
            ball.vy *= -1;
        }

        if (ball.y + 10 >= SCREEN_HEIGHT) {
            ball.y = SCREEN_HEIGHT - 10;
            ball.vy *= -1;
        }

        if (ball.x + 10 < 0) {
            //ball.x = ball_rect.w + 10;
            //ball.x = player1->position.x + player1->position.h;
            //ball.y = player1->position.y + player1->position.h/2;
            ball.vx *= -1;
        }

        if (ball.x >= SCREEN_WIDTH) {
            ball.x = SCREEN_WIDTH;
            //ball.x = player2->position.x - player2->position.h;
            //ball.y = player2->position.y + player2->position.h/2;
            ball.vx *= -1;
        }

        if (ball.y < player2->position.y + player2->position.y/2) {
            player2->position.y -= player2->speed;
        }

        if (ball.y > player2->position.y + player2->position.y/2) {
            player2->position.y += player2->speed;
        }

        if (SDL_HasIntersection(&ball_rect, &player1->position)) {
            ball.vx *= -1;
        }

        if (SDL_HasIntersection(&ball_rect, &player2->position)) {
            ball.vx *= -1;
        }

        blitRect(app.renderer, &ball_rect);
        blitRect(app.renderer, &player1->position);
        blitRect(app.renderer, &player2->position);

        playerBounds();

        presentScene();

        SDL_Delay(16);
    }

    cleanup();

    return 0;
}

static void playerPositions(Paddle* player1, Paddle* player2) {
    player1->position.x = 20;
    player1->position.y = SCREEN_HEIGHT/2 - 80;
    player1->position.h = 150;
    player1->position.w = 20;

    player2->position.x = SCREEN_WIDTH - 40;
    player2->position.y = SCREEN_HEIGHT/2 - 80;
    player2->position.h = 150;
    player2->position.w = 20;
}

static void playerBounds(void) {
    if (player1 != NULL) {
        if (player1->position.y < 15) {
            player1->position.y = 0;
        }
        if (player1->position.y > SCREEN_HEIGHT - player1->position.h) {
            player1->position.y = SCREEN_HEIGHT - player1->position.h;
        }
    }
}