#include "headers/draw.h"

void PrepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderClear(app.renderer);
}


void PresentScene(void) {
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

SDL_Texture* LoadFont(char* filename, char buffer[]) {
    TTF_Font* font;
    SDL_Color color = {255, 255, 255};

    font = TTF_OpenFont(filename, 24);
    if (!font) {
        log_debug("Could not open font: %s.", TTF_GetError());
    }

    SDL_Surface* surfaceFont;
    surfaceFont = TTF_RenderText_Solid(font, buffer, color);
    if (!surfaceFont) {
        log_debug("Surface could not be initialized: %s.", SDL_GetError());
    }

    SDL_Texture* message;
    message = SDL_CreateTextureFromSurface(app.renderer, surfaceFont);
    if (!message) {
        log_debug("Texture could not be initialized: %s.", SDL_GetError());
    }

    SDL_FreeSurface(surfaceFont);
    TTF_CloseFont(font);

    return message;
}

void DrawFont(SDL_Texture* fontTexture, int x, int y) {
    SDL_Rect message_rect;

    message_rect.x = x;
    message_rect.y = y;
    SDL_QueryTexture(fontTexture, NULL, NULL, &message_rect.w, &message_rect.h);

    SDL_RenderCopy(app.renderer, fontTexture, NULL, &message_rect);
}

void BlitRect(SDL_Renderer* renderer, const SDL_Rect* rect) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, rect);
        SDL_RenderDrawRect(renderer, rect);
}
