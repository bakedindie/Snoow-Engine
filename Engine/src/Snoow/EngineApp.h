#pragma once
#include "Core.h"


namespace Snoow
{
	class Snoow_API EngineApp
	{
	public:
		EngineApp();
		virtual ~EngineApp();
		void Run();
	};

	EngineApp* CreateApp();
}