#pragma once

#ifdef TGGE_PLATFORM_WINDOWS

extern tgge::Application* tgge::CreateApplication();

int main(int argc, char** argv)
{
	printf("Powered by 'The Good Game Engine'...\n");
	auto application = tgge::CreateApplication();
	application->Run();
	delete application;
}

#endif