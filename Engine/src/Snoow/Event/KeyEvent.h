#pragma once
#include "Event.h"

namespace   Snoow
{
    void PushEvent(SDL_EventFilter filter, void* data);

    int KeyDownEventFilter(void* data, SDL_Event* event) {
        if (event->type == SDL_KEYDOWN) 
        {
            SDL_Window* win = SDL_GetWindowFromID(event->window.windowID);
            SDL_GetKeyFromScancode(event->key.keysym.scancode);
           
            if (win == (SDL_Window*)data)
            {
                    ;
                SN_INFO("KEY {0} DOWN", event->key.keysym.scancode);
            }
            
        }
        return 0;
    }

    int KeyUpEventFilter(void* data, SDL_Event* event) {
        if (event->type == SDL_KEYUP)
        {
            SDL_Window* win = SDL_GetWindowFromID(event->window.windowID);
            
            if (win == (SDL_Window*)data)
            {
                SN_INFO("KEY {0} UP", event->key.keysym.scancode);
            }
            
        }
        return 0;
    }

}