#include "input.h"

void processDownKey(SDL_KeyboardEvent* event);
void processUpKey(SDL_KeyboardEvent* event);

void getInput(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                app.running = false;
                exit(0);
                break;

            case SDL_KEYDOWN:
                processDownKey(&event.key);
                break;

            case SDL_KEYUP:
                processUpKey(&event.key);
                break;

            default:
                break;
        }
    }
}

void processDownKey(SDL_KeyboardEvent* event)
{
    if (event->repeat == 0) {
        if (event->keysym.scancode == SDL_SCANCODE_UP) {
            app.up = 1;
        }
        if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
            app.down = 1;
        }
    }
}

void processUpKey(SDL_KeyboardEvent* event) {
    if (event->repeat == 0) {
        if (event->keysym.scancode == SDL_SCANCODE_UP) {
            app.up = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
            app.down = 0;
        }
    }
}