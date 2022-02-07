#include "src/core/engine.h"


int main(int argc, char **argv)
{
	Engine* engine = Engine::GetInstance();
	engine->Init();

	while (engine->IsRunning())
	{
		engine->Events();
		engine->Update();
		engine->Render();


	}
	engine->Clean();
	return 0;
}