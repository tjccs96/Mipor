#include "Mipor.h"

class Sandbox : public Mipor::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Mipor::Application* Mipor::CreateApplication()
{
	return new Sandbox();
}