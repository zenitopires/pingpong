#include <time.h>

#include "structs.h"
#include "defs.h"

Ball ballPosition(Ball ball) {
    srand(time(NULL));
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.speed = STARTBALLSPEED;
    ball.vx = (rand() % 2 == 0)? 1 * ball.speed : -1 * 1 * ball.speed;
    ball.vy = -1.0f;
    return ball;
}
