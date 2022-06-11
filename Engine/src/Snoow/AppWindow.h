#pragma once
#include "Window.h"


namespace Snoow
{
	class Snoow_API AppWindow : public Window
	{
	public:
		AppWindow(const WindowProps& props);
		virtual ~AppWindow();

		void OnUpdate() override;
		void Eventhandler(SDL_EventFilter e) override;

		inline unsigned int GetWidth() const override { return _data.width; }
		inline unsigned int GetHeight() const override { return _data.height; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		SDL_Window* _window;
		SDL_GLContext glcontext;
		SDL_Event _event;
		SDL_Event w_event;

		struct WindowData
		{
			std::string title;
			int xpos;
			int ypos;
			int width;
			int height;
			SDL_WindowFlags flags;
			bool VSync;
		};
		WindowData _data;
	};
}