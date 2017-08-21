#pragma once

#include "h_Image.h"
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include <string>


namespace Heyo {

	class Sprite;

	typedef Uint32 Uint32;

	class Graphics
	{
	public:
		int const * SCREEN_WIDTH;
		int const * SCREEN_HEIGHT;
		const std::string m_title;

		friend class Image;
		friend class Text;

	private:
		SDL_Window * m_window;
		SDL_Renderer * m_renderer;
		SDL_Texture * m_texture;
		SDL_Surface * m_winSurface;


	public:
		Graphics();
		Graphics(int width, int height, std::string title);
		~Graphics();

		// BUGGY! Does not work well. Avoid!
		bool changeScreenSize(int width = 600, int height = 400);

		// Clears the renderer
		void clear();
		void update(Sprite & p_sprite, Rect & destin);
		void update(Text & p_text, Rect & destin);
		void update(Image & p_image, Rect & destin);

		void render();

	private:
		bool init();
		void close();

	};

}