#pragma once

#ifdef OS_PLATFORM_WINDOWS

int main(int argc. char** argv) {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}

#endif // OS_PLATFORM_WINDOWS
