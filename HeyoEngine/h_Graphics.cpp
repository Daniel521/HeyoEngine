#include "h_Graphics.h"
#include "h_Sprite.h"
#include "h_Text.h"

namespace Heyo {

	Graphics::Graphics() : SCREEN_WIDTH(new int (600)), SCREEN_HEIGHT(new int (400))
	{
		if (init())
		{
			SDL_Log("Failed to Initiate Heyo Engine.");
			close();
		}
	}

	Graphics::Graphics(int width, int height, std::string title) : SCREEN_WIDTH(new int (width)), SCREEN_HEIGHT(new int (height)), m_title(title)
	{
		if (!init())
		{
			SDL_Log("Failed to Initiate Heyo Engine.");
			close();
		}
	}


	Graphics::~Graphics()
	{
		close();
	}

	bool Graphics::changeScreenSize(int width, int height)
	{
		if (width <= 0 || height <= 0) {
			delete SCREEN_WIDTH;
			SCREEN_WIDTH = new int(600);
			delete SCREEN_HEIGHT;
			SCREEN_HEIGHT = new int(400);
		}
		else {
			delete SCREEN_WIDTH;
			SCREEN_WIDTH = new int(width);
			delete SCREEN_HEIGHT;
			SCREEN_HEIGHT = new int(height);
		}
		init();
		return true;
	}

	void Graphics::clear()
	{
		SDL_RenderClear(m_renderer);
	}

	void Graphics::update(Sprite & p_sprite, Rect & destin)
	{
		SDL_RenderCopy(m_renderer, p_sprite.m_image.m_texture, &p_sprite.getcurRect(), &destin);  
	}

	void Graphics::update(Text & p_text, Rect & destin)
	{
		SDL_RenderCopy(m_renderer, p_text.m_texture, NULL, &destin);
	}

	void Graphics::update(Image & p_image, Rect & destin)
	{
		SDL_RenderCopy(m_renderer, p_image.m_texture, NULL, &destin);
	}
	

	void Graphics::render()
	{
		SDL_RenderPresent(m_renderer);
	}

	bool Graphics::init()
	{
		close();
		// Make Window
		m_window = SDL_CreateWindow(
			(char*)m_title.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			*SCREEN_WIDTH,
			*SCREEN_HEIGHT,
			SDL_WindowFlags::SDL_WINDOW_SHOWN
		);

		if (!m_window)
		{
			SDL_Log("Window failed to create: %s", SDL_GetError());
			return false;
		}
		else
		{
			// Get window surface
			m_winSurface = SDL_GetWindowSurface(m_window);
		}

		// Make Renderer
		m_renderer = SDL_CreateRenderer(
			m_window,
			-1,
			SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC
		);

		if (!m_renderer)
		{
			SDL_Log("Renderer failed to create: %s", SDL_GetError());
			return false;
		}

		// Make Texture
		m_texture = SDL_CreateTexture(
			m_renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TextureAccess::SDL_TEXTUREACCESS_STREAMING,
			*SCREEN_WIDTH,
			*SCREEN_HEIGHT
		);

		if (!m_texture)
		{
			SDL_Log("Renderer failed to create: %s", SDL_GetError());
			return false;
		}

		return true;

	}

	void Graphics::close()
	{
		if (m_window)
			SDL_DestroyWindow(m_window);

		if (m_renderer)
			SDL_DestroyRenderer(m_renderer);

		if (m_texture)
			SDL_DestroyTexture(m_texture);

		if (m_winSurface)
			SDL_FreeSurface(m_winSurface);
	}

}