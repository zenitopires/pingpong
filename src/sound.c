#include "sound.h"

Mix_Chunk* loadSoundEffect(char* filePath) {
    Mix_Chunk* soundEffect;
    soundEffect = Mix_LoadWAV(filePath);

    if (soundEffect == NULL) {
        printf("Failed to load %s sound effect: %s\n", filePath, Mix_GetError());
        exit(1);
    }

    return soundEffect;
}

void cleanup_audio(Mix_Chunk* soundEffect) {
    Mix_FreeChunk(soundEffect);
    soundEffect = NULL;
    Mix_Quit();
}