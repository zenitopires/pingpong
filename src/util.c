#include "headers/common.h"

float calcAngle(float paddleY, float ballY, float paddleH) {
   float relativeY = (paddleY + (paddleH / 2)) - ballY;
   float normalized_relY = (relativeY / (paddleH / 2));
   float bounceAngle = normalized_relY * MAXANGLE;
   return bounceAngle;
}

void TrackBall(Ball* ball, Paddle* bot) {
    if (ball->y < bot->position.y + bot->position.y/2) {
        bot->position.y -= bot->speed;
    }
    if (ball->y > bot->position.y + bot->position.y/2) {
        bot->position.y += bot->speed;
    }
}

// Set speed of paddles
void SetSpeed(Paddle* player1, Paddle* player2) {
    player1->speed = 15;
    player2->speed = 5;
}

void SetScore(Paddle* player1, Paddle* player2) {
    player1->score = 0;
    player2->score = 0;
}