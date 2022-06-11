#pragma once
#include "Event.h"

namespace Snoow
{
	static int WindowClosedEventFilter(void* data, SDL_Event* event)
	{
		if ((event->type == SDL_WINDOWEVENT) && (event->window.event == SDL_WINDOWEVENT_CLOSE))
		{
			SDL_Window* window = SDL_GetWindowFromID(event->window.windowID);

			if (window == (SDL_Window*)data)
			{
				SN_INFO("WINDOW CLOSED");
			}

		}
		return 0;
	}
}