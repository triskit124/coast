#include <iostream>

#include "coast_engine.h"
#include "window.h"
#include "scene.h"
#include "../render/render.h"

namespace coast {

std::unique_ptr<coast::Window> window;
std::unique_ptr<coast::Scene> scene;

void init() {
    std::cout << "init" << std::endl;
    window = std::make_unique<coast::Window>();
}

void run() {
    bool running = true;
    while(running) {
        coast::update();
        coast::render();
        running = false;
    }
}

void update() {
    std::cout << "update" << std::endl;
}

} // namespace coast

int main() {

    coast::init();
    coast::run();

    std::cout << "We made it" << std::endl;
    return 0;
}