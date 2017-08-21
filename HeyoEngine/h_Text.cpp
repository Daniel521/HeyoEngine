#include "h_Text.h"
#include "h_heyo.h"

namespace Heyo {

	Text::Text() : m_font(NULL), m_surface(NULL), m_texture(NULL), m_width(0), m_height(0), m_color({255,255,255})
	{
	}


	Text::~Text()
	{
		if (m_font != NULL)
			TTF_CloseFont(m_font);
		m_font = NULL;
		clear();
	}

	bool Text::loadFont(std::string fontaddress, int textsize)
	{
		if (m_font != NULL)
		{
			TTF_CloseFont(m_font);
			clear();
		}

		m_font = TTF_OpenFont(fontaddress.c_str(), 28);
		if (m_font == NULL)
		{
			SDL_Log("Failed to load font %s, ", fontaddress);
			SDL_Log("error: %s\n", textsize);
			return false;
		}
		return true;
	}

	bool Text::setText(std::string text, Color m_color)
	{
		if (m_surface != NULL)
			clear();

		m_surface = TTF_RenderText_Solid(m_font, text.c_str(), m_color);
		if (m_surface == NULL)
		{
			SDL_Log("Unable to render text surface! SDL_ttf error: %s\n", TTF_GetError());
			return false;
		}
		else
		{
			m_texture = SDL_CreateTextureFromSurface(graphics->m_renderer, m_surface);

			m_width = m_surface->w;
			m_height = m_surface->h;

			SDL_FreeSurface(m_surface);
			m_surface = NULL;
		}

		// $BOOBS!!!!!!!! Delete the surface from all of these!!! no need for it to lay around for a long time

		return true;
	}

	void Text::setColor(Uint8 r, Uint8 g, Uint8 b)
	{
		m_color = { r,g,b };
		SDL_SetTextureColorMod(m_texture,r,g,b);
	}

	void Text::setAlpha(Uint8 value)
	{
		SDL_SetTextureAlphaMod(m_texture, value);
	}

	void Text::clear()
	{
		if (m_surface != NULL) {
			SDL_FreeSurface(m_surface);
			m_surface = NULL;
		}
		if (m_texture != NULL) {
			SDL_DestroyTexture(m_texture);
			m_texture = NULL;
		}
		m_width = 0;
		m_height = 0;
	}

}