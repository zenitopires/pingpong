#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "init.h"
#include "defs.h"

void init(char* string) {
    int windowFlags, rendererFlags;

    windowFlags = 0;
    rendererFlags = SDL_RENDERER_ACCELERATED;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_Log("Cannot initialize SDL: %s", SDL_GetError());
        exit(1);
    }
    else {
        printf("SDL Initiliazed...\n");
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        exit(1);
    }
    else {
        printf("SDL_mixer initialized...\n");
    }

    if (TTF_Init() == -1) {
        printf("SDL_ttf could not be initialized: %s\n", TTF_GetError());
        exit(1);
    }
    else  {
        printf("SDL_ttf initialized...\n");
    }

    app.window = SDL_CreateWindow(
        string,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        windowFlags
    );

    if (app.window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (app.renderer == NULL) {
        printf("Could not create renderer: %s\n", SDL_GetError());
        exit(1);
    }
    printf("All systems fine... Starting game\n");
}

void cleanup(void) {
    SDL_DestroyRenderer(app.renderer);

    SDL_DestroyWindow(app.window);

    SDL_Quit();
}
