#include "object.h"

namespace coast {

CoastObject::CoastObject() {}
CoastObject::~CoastObject() {}

template <typename T>
T CoastObject::addComponent(const T& component_class) {
    return component_class();
}

} // namespace coast