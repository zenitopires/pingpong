#include <time.h>

#include "structs.h"
#include "defs.h"

Ball new_Ball(Ball ball) {
    srand(time(NULL));
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.speed = 5;
    ball.vx = (rand() % 2 == 0)? 1 : -1 * 1 * ball.speed;
    ball.vy = -1.0f;
    return ball;
}
