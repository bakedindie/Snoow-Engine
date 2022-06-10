#pragma once
#include "SDL.h"
#include "Core.h"

namespace Snoow
{
	class Snoow_API Window
	{
	public:
		Window();
		~Window();

		void Init();
		void Update();
		void ShutDown();

	private:
		SDL_Window* m_window;
		const char* _title;
		int _xpos;
		int _ypos;
		int _w;
		int _h;
		bool _flags;

	};

	
}