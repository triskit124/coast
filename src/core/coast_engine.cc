#include <iostream>

#include "coast_engine.h"
#include "scene.h"
#include "../render/render.h"

namespace coast {

std::unique_ptr<coast::Scene> scene;

void init() {

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