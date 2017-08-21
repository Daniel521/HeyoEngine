#pragma once

#include "HeyoEngine.h"

namespace Heyo {

	void closeHeyo();


	class Level {
	private:

	public:
		virtual bool init();
		virtual bool loop();
	};

	struct GFXSetttings {
		int width;
		int height;
		std::string title;
	};


}

#define GraphicsSettings Heyo::GFXSetttings gfxset


GraphicsSettings{ 1,2,"blah" };