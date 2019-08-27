#include "main.h"

int main()
{
    long then;
    float remainder, bounceAngle;
    char buffer[512];

    SDL_Texture* scorePlayer1;
    SDL_Texture* scorePlayer2;

    memset(&app, 0, sizeof(App));
    memset(&player1, 0, sizeof(Paddle));
    memset(&player2, 0, sizeof(Paddle));

    init("Ping Pong by Zenito Pires");

    // Setup FPS
    then = SDL_GetTicks();
    remainder = 0;

    player1 = malloc(sizeof(Paddle));
    player2 = malloc(sizeof(Paddle));

    Ball ball;
    ball = ballPosition(ball);

    // Set ball rect properties
    SDL_Rect ball_rect;
    ball_rect.w = 10;
    ball_rect.h = 10;
    ball_rect.x = ball.x;
    ball_rect.y = ball.y;

    // Set paddle positions
    playerPositions(player1, player2);

    // Set speed
    player1->speed = 15;
    player2->speed = 5;

    // Set initial scores
    player1->score = 0;
    player2->score = 0;

    // Set up sound effect
    Mix_Chunk* pingHit;
    pingHit = malloc(sizeof(Mix_Chunk));
    pingHit = loadSoundEffect("sounds/ping_hit.wav");

    // Game loop
    app.running = true;
    app.paused = false;
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

        // Ball collision detection
        if (ball.y < 0) {
            ball.y = 0;
            ball.vy *= -1;
        }

        if (ball.y + 10 >= SCREEN_HEIGHT) {
            ball.y = SCREEN_HEIGHT - 10;
            ball.vy *= -1;
        }

        if (ball.x + 10 < 0) {
            ball.speed = STARTBALLSPEED;
            ball.x = player1->position.x + player1->position.w;
            ball.y = player1->position.y + player1->position.h/2;
            ball.vx = STARTBALLSPEED;
            player2->score++;
        }

        if (ball.x >= SCREEN_WIDTH) {
            ball.speed = STARTBALLSPEED;
            ball.x = player2->position.x - player2->position.w;
            ball.y = player2->position.y + player2->position.h/2;
            ball.vx = STARTBALLSPEED;
            player1->score++;
        }

        if (SDL_HasIntersection(&ball_rect, &player1->position)) {
            Mix_PlayChannel(-1, pingHit, 0);
            ball.speed += 0.5;
            if (ball.speed >= MAXBALLSPEED) {
                ball.speed = MAXBALLSPEED;
            }
            bounceAngle = calcAngle(player1->position.y, ball.y, player1->position.h);
            ball.vy = sin(bounceAngle) * ball.speed;
            ball.vx = cos(bounceAngle) * ball.speed;
        }


        if (SDL_HasIntersection(&ball_rect, &player2->position)) {
            Mix_PlayChannel(-1, pingHit, 0);
            ball.speed += 0.5;
            if (ball.speed >= MAXBALLSPEED) {
                ball.speed = MAXBALLSPEED;
            }
            bounceAngle = calcAngle(player2->position.y, ball.y, player1->position.h);
            ball.vy = sin(bounceAngle) * ball.speed * -1;
            ball.vx = cos(bounceAngle) * ball.speed * -1;
        }

        // Paddle for bot
        if (ball.y < player2->position.y + player2->position.y/2) {
            player2->position.y -= player2->speed;
        }

        if (ball.y > player2->position.y + player2->position.y/2) {
            player2->position.y += player2->speed;
        }

        // score text update
        sprintf(buffer, "%d", player1->score);
        scorePlayer1 = loadFont("fonts/arial.ttf", buffer);
        sprintf(buffer, "%d", player2->score);
        scorePlayer2 = loadFont("fonts/arial.ttf", buffer);


        // blit rects
        drawFont(scorePlayer1, SCREEN_WIDTH/4, 10);
        drawFont(scorePlayer2, SCREEN_WIDTH/4 + SCREEN_WIDTH/2, 10);
        blitRect(app.renderer, &ball_rect);
        blitRect(app.renderer, &player1->position);
        blitRect(app.renderer, &player2->position);

        playerBounds(player1);

        presentScene();

        capFramerate(&then, &remainder);
    }

    cleanup();

    cleanup_audio(pingHit);

    free(player1);
    free(player2);

    return 0;
}
