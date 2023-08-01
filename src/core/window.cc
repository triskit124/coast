#include <iostream>

#include "window.h"

namespace coast {

// default window size
unsigned int Window::m_window_width = 1280;
unsigned int Window::m_window_height = 720;

Window::Window() {

    // initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
	} 
    
    // create the window
    m_window = SDL_CreateWindow("coast", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window::m_window_width, Window::m_window_height, SDL_WINDOW_SHOWN);
    if (!m_window) {
        std::cout << "Failed to open window: " << SDL_GetError() << std::endl;
        exit(1);
    } 
        
    // get window surface
    m_screen_surface = SDL_GetWindowSurface(m_window);

    // fill the surface white
    SDL_FillRect(m_screen_surface, NULL, SDL_MapRGB(m_screen_surface->format, 0xFF, 0xFF, 0xFF));
    
    // update the surface
    SDL_UpdateWindowSurface(m_window);

    // hack to get window to stay up
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
}

void Window::close() {
    // destroy window
    SDL_DestroyWindow(m_window);
    m_window = nullptr;

    // quit SDL subsystems
    SDL_Quit();
}


} // namespace coast
