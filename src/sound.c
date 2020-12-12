#include "headers/sound.h"

Mix_Chunk* LoadSoundEffect(char* filePath) {
    log_debug("Loading sound effects.");
    Mix_Chunk* soundEffect;
    soundEffect = Mix_LoadWAV(filePath);

    if (soundEffect == NULL) {
        printf("Failed to load %s sound effect: %s\n", filePath, Mix_GetError());
        exit(1);
    }

    return soundEffect;
}

void CleanupAudio(Mix_Chunk* soundEffect) {
    log_debug("Freeing audio clips.");
    Mix_FreeChunk(soundEffect);
    soundEffect = NULL;
    Mix_Quit();
}