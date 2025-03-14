#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <SDL.h>

void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}


#endif // EXCEPTION_H
