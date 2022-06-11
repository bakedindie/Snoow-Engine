#include "pch.h"
#include "EngineApp.h"
#include "Event/AppEvent.h"



namespace Snoow 
{

	EngineApp::EngineApp()
	{
		_window = std::unique_ptr<Window>(Window::Create());
		OnEvent();
	}

	EngineApp::~EngineApp()
	{

	}

	void EngineApp::OnEvent()
	{
		Event_Dispatch(WindowClosedEventFilter);
	}


	void EngineApp::Run()
	{

		while (_running)
		{
			_window->OnUpdate();
		}
	}
}