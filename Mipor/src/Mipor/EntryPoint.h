#pragma once

#ifdef MP_PLATFORM_WINDOWS

extern Mipor::Application* Mipor::CreateApplication();

int main(int argc, char** argv) 
{
	Mipor::Log::Init();
	MP_CORE_WARN("Initialized Log");
	int a = 5;
	MP_INFO("Hello! Var=(0)", a);

	auto app = Mipor::CreateApplication();
	app->Run();
	delete app;
}

#endif 