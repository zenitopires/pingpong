#include "common.h"

float calcAngle(float paddleY, float ballY, float paddleH) {
   float relativeY = (paddleY + (paddleH / 2)) - ballY;
   float normalized_relY = (relativeY / (paddleH / 2));
   float bounceAngle = normalized_relY * MAXANGLE;
   return bounceAngle;
}
