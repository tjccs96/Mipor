#pragma once

#ifdef MP_PLATFORM_WINDOWS

extern Mipor::Application* Mipor::CreateApplication();

int main(int argc, char** argv) 
{
	auto app = Mipor::CreateApplication();
	app->Run();
	delete app;
}

#endif 