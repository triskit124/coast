#ifndef COAST_WINDOW_H_
#define COAST_WINDOW_H_

#include <SDL2/SDL.h>

namespace coast {

class Window {
    public:
        Window();
        ~Window()  { close(); };
        void close();

        static unsigned int m_window_width;
        static unsigned int m_window_height;
    
    protected:
        SDL_Window* m_window = nullptr;
        SDL_Surface* m_screen_surface = nullptr;

    private:
};

} // namespace coast

#endif