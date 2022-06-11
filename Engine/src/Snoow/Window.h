#pragma once
#include "pch.h"
#include "Core.h"



namespace Snoow
{
	struct WindowProps
	{
		std::string title;
		int xpos;
		int ypos;
		int width;
		int height;
		SDL_WindowFlags flags;

		WindowProps(const std::string& _title =
			"Snoow Engine",
			int _xpos = SDL_WINDOWPOS_CENTERED,
			int _ypos = SDL_WINDOWPOS_CENTERED,
			int _width = 1280,
			int _height = 720,
			SDL_WindowFlags _flags = SDL_WINDOW_OPENGL
			)
			:title(_title), xpos(_xpos), ypos(_ypos), width(_width), height(_height), flags(_flags)
		{
		}
	};

	class Snoow_API Window
	{
	public:
		
		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		virtual void Eventhandler(SDL_EventFilter e) = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};

	
}