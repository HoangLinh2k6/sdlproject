#include <SDL.h>
#include "sound.h"

Music::Music():
    music( Mix_LoadMUS( MUSIC ) )
{
    if( music == nullptr ){
        SDL_LogMessage( SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
            "Could not load music! SDL_mixer Error: %s", Mix_GetError() );
    }
}

void Music::play(){
    if( music == nullptr ) return;

    if( Mix_PlayingMusic() == 0 ){
        Mix_PlayMusic( music, -1 );
    }
    else if( Mix_PausedMusic() == 1 ){
        Mix_ResumeMusic();
    }
}

void Music::quit(){
    Mix_FreeMusic( music );
    music = nullptr;
}


Sound::Sound():
    chunk( Mix_LoadWAV( JUMPSOUND ) )
{
    if( chunk == nullptr ){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
           "Could not load sound! SDL_mixer Error: %s", Mix_GetError() );
    }
}

void Sound::play(){
    if( chunk != nullptr ){
        Mix_PlayChannel( -1, chunk, 0 );
    }
}

void Sound::quit(){
    Mix_FreeChunk( chunk );
    chunk = nullptr;
}
