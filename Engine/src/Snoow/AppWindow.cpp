#include "pch.h"
#include "AppWindow.h"

#include "Event/AppEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

namespace Snoow
{
	static bool _SDLInit = false;
	
	Window* Window::Create(const WindowProps& props)
	{
		return new AppWindow(props);
	}

	AppWindow::AppWindow(const WindowProps& props)
	{
		Init(props);
	}

	AppWindow::~AppWindow()
	{
		Shutdown();
	}

	void AppWindow::Init(const WindowProps& props)
	{

		_data.title = props.title;
		_data.xpos = props.xpos;
		_data.ypos = props.ypos;
		_data.width = props.width;
		_data.height = props.height;
		_data.flags = props.flags;
		
		SN_CORE_INFO("Created Window : \"{0}\" {1} x {2}", props.title, props.width, props.height);
		
		if (!_SDLInit)
		{
			int success = SDL_Init(SDL_INIT_EVERYTHING);
			SN_CORE_ASSERT(success, "FAILED");

			_SDLInit = true;
		}
		/*----------------OPENGL WINDOW INTIALIZATION-----------------*/
		_window = SDL_CreateWindow(props.title.c_str(), props.xpos, props.ypos, props.width, props.height, props.flags);
		SetVSync(true);
		glcontext = SDL_GL_CreateContext(_window);

	}
	

	void AppWindow::Shutdown()
	{
		SDL_DestroyWindow(_window);
	}

	

	/*
	Event Handler Function to be implemented in the EngineApp
	*/
	void AppWindow::Eventhandler(SDL_EventFilter e)
	{
		PushEvent(e, _window);
	}

	void AppWindow::OnUpdate()
	{
		
		SDL_PollEvent(&_event);
		SDL_GL_SwapWindow(_window);
		glClearColor(0, 0, 160, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void AppWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			SDL_GL_SetSwapInterval(1);
		}
		else
		{
			SDL_GL_SetSwapInterval(0);
			_data.VSync = enabled;
		}
	}

	bool AppWindow::IsVSync() const
	{
		return _data.VSync;
	}

}