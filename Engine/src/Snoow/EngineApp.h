#pragma once
#include "Core.h"
#include "Window.h"

#include "Event/Event.h"

namespace Snoow
{
	class Snoow_API EngineApp
	{
	public:
		EngineApp();
		virtual ~EngineApp();
		void OnEvent();
		void Run();
	private:
		
		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	EngineApp* CreateApp();
}