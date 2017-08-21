#pragma once
#include "SDL2\include\SDL_ttf.h"
#include <string>


namespace Heyo {
	typedef SDL_Color Color;


	class Text
	{
	private:
		TTF_Font * m_font;
		SDL_Surface * m_surface;
		SDL_Texture * m_texture;
		Color m_color;
		int m_width;
		int m_height;

	public:
		Text();
		~Text();

		bool loadFont(std::string fontaddress, int textsize = 8);

		bool setText(std::string text, Color m_color = { 255,255,255 });

		void setColor(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255);

		// For later!!
		void setAlpha(Uint8 value = 255);

		void clear();

		int getWidth() { return m_width; }
		int getHeight() { return m_height; }
		Color getColor() { return m_color; }

		friend class Graphics;

	};

}