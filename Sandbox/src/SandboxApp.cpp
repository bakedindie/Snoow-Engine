#include <Snoow.h>

class Sandbox : public Snoow::EngineApp
{
public:
	Sandbox();
	~Sandbox();

private:

};

Sandbox::Sandbox()
{

}

Sandbox::~Sandbox()
{

}

Snoow::EngineApp* Snoow::CreateApp()
{
	return new Sandbox();
}