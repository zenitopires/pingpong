#include "draw.h"

void prepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 48, 48, 48, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void) {
    SDL_RenderPresent(app.renderer);
}

/*
SDL_Texture* loadTex(char* filename) {
    SDL_Texture* texture;

    texture = IMG_LoadTexture(app.renderer, filename);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
    "Loading textures %s", filename);

    return texture;
}

void drawTex(SDL_Texture* texture, int x, int y) {
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}
*/

void blitRect(SDL_Renderer* renderer, const SDL_Rect* rect) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, rect);
        SDL_RenderDrawRect(renderer, rect);
}