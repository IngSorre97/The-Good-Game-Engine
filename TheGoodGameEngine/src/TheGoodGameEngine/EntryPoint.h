#pragma once

#ifdef TGGE_PLATFORM_WINDOWS

extern tgge::Application* tgge::CreateApplication();

int main(int argc, char** argv)
{
	tgge::Log::Init();
	TGGE_CORE_INFO("Initializing Log system...");

	TGGE_INFO("Powered by 'The Good Game Engine'...");

	auto application = tgge::CreateApplication();
	application->Run();
	delete application;
}

#endif