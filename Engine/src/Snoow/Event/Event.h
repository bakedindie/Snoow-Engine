#pragma once
#include "../Core.h"

namespace Snoow
{
	static void SetEventFilter(SDL_EventFilter filter, void* data)
	{
		SDL_SetEventFilter(filter, data);
	}

	static void PushEvent(SDL_EventFilter filter, void* data)
	{
		SDL_SetEventFilter(filter, data);
	}
	
}