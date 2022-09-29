#include <Oasis.h>

class Sandbox : public Oasis::Application {
public:
	Sandbox(){}
	~Sandbox(){}
};

int main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}