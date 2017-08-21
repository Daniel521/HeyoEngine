#include "h_heyo.h"	
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "SDL2\include\SDL_mixer.h"
#include "SDL2\include\SDL_ttf.h"

namespace Heyo {

	bool initHeyo()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			SDL_Log("Failed to initiate video: %s\n", SDL_GetError());
			return false;
		}
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(IMG_INIT_PNG) & imgFlags))
		{
			SDL_Log("Failed to initiate IMG: %s\n", IMG_GetError());
			return false;
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			SDL_Log("Failed to initiate Sound Mixer: %s\n", Mix_GetError());
			return false;
		}
		if (TTF_Init() == -1)
		{
			SDL_Log("Failed to initiate text: %s\n", TTF_GetError());
			return false;
		}

		return true;
	}

	void closeHeyo()
	{
		SDL_Quit();
		IMG_Quit();
		Mix_Quit();
		TTF_Quit();
	}

}

Heyo::Graphics * graphics;

int main(int argc, char * argv[]) { 
	Heyo::initHeyo();
	


	delete graphics;
	Heyo::closeHeyo();
	return 0;
}