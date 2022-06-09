#pragma once

#ifdef SN_PLATFORM_WINDOWS

extern Snoow::EngineApp* Snoow::CreateApp();

int main(int argc, char** argv[])
{
	auto game = Snoow::CreateApp();
	game->Run();
	delete game;
}

#endif // HZ_PLATFORM_WINDOWS
