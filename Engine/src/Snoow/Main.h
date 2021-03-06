#pragma once

#ifdef SN_PLATFORM_WINDOWS

extern Snoow::EngineApp* Snoow::CreateApp();

int main(int argc, char** argv)
{
	
	Snoow::Log::Init();
	
	SN_CORE_ASSERT("SNOOW CORE");
	SN_INFO("SNOOW APP");

	auto game = Snoow::CreateApp();
	game->Run();
	delete game;

	return 0;
}

#endif // HZ_PLATFORM_WINDOWS
