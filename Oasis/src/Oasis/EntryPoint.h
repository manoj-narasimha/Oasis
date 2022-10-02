#pragma once

#ifdef OS_PLATFORM_WINDOWS

extern Oasis::Application* Oasis::CreateApplication();

int main(int argc, char** argv) {

	Oasis::OasisLog::init();
	HZ_CORE_WARN("Initilized...");
	int a = 5;;
	HZ_CLIENT_INFO("Welcome! var={0}",a);

	auto app = Oasis::CreateApplication();
	app->Run();
	delete app;
}

#endif // OS_PLATFORM_WINDOWS
