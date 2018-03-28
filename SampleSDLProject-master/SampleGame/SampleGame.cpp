// SampleGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Engine.h>
#include "MainScene.h"

int main(int argc, char* args[])
{
	//std::vector<Scene*> scenes;
	//loadscene();
	core::Engine e(new MainScene);
	if (e.Init()) {
		e.run();
	}
    return 0;
}



