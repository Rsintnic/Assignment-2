// SampleGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Engine.h>
#include "MainScene.h"

int main(int argc, char* args[])
{
	
	core::Engine e(new MainScene);
	if (e.init() == 0) {
		e.run();
	}
    return 0;
}

