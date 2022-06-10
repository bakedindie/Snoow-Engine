#include "pch.h"
#include "Window.h"

namespace Snoow
{
    Window::Window()
	{
        Init();
	}

	Window::~Window()
	{
	}

	void Window::Init()
	{
        SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
        m_window = SDL_CreateWindow(
            "Snoow Engine",                  // window title
            256,           // initial x position
            240,           // initial y position
            1280,                               // width, in pixels
            720,                               // height, in pixels
            SDL_WINDOW_RESIZABLE                  // flags - see below
        );

        // Check that the window was successfully created
        if (m_window == NULL) {
            // In the case that the window could not be made...
            printf("Could not create window: %s\n", SDL_GetError());
            exit(1);
        }

	}

	
}