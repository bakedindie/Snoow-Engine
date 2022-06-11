#pragma once
#include "Event.h"

namespace Snoow
{
    void PushEvent(SDL_EventFilter filter, void* data);

    int MouseMovedEventFilter(void* data, SDL_Event* event) {
        if (event->type == SDL_MOUSEMOTION)
        {
            SDL_Window* win = SDL_GetWindowFromID(event->window.windowID);
            SDL_GetMouseState(&event->motion.x, &event->motion.y);

            if (win == (SDL_Window*)data)
            {
                ;
                SN_INFO("MOUSE MOVED : {0}, {1}", event->motion.x, event->motion.y);
            }

        }
        return 0;
    }

    int MouseButtonDownEventFilter(void* data, SDL_Event* event) {
        if (event->type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_Window* win = SDL_GetWindowFromID(event->window.windowID);
            SDL_GetMouseState(&event->motion.x, &event->motion.y);

            if (win == (SDL_Window*)data)
            {
                ;
                SN_INFO("MOUSE BUTTON : {0}, {1}", event->button.button, event->button.clicks);
            }

        }
        return 0;
    }

    int MouseScrolledEventFilter(void* data, SDL_Event* event) {
        if (event->type == SDL_MOUSEWHEEL)
        {
            SDL_Window* win = SDL_GetWindowFromID(event->window.windowID);
            SDL_GetMouseState(&event->motion.x, &event->motion.y);

            if (win == (SDL_Window*)data)
            {
                ;
                SN_INFO("MOUSE WHEEL : {0}, {1}", event->motion.type, event->button.clicks);
            }

        }
        return 0;
    }
}