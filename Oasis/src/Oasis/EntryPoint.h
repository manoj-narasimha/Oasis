#pragma once

#ifdef OS_PLATFORM_WINDOWS

extern Oasis::Application* Oasis::CreateApplication();

int main(int argc, char** argv) {

	printf("Welcome To Oasis Game Engine");
	auto app = Oasis::CreateApplication();
	app->Run();
	delete app;
}

#endif // OS_PLATFORM_WINDOWS
