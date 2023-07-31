#ifndef COAST_TRANSFORM_H_
#define COAST_TRANSFORM_H_

#include <string>

#include "component.h"

namespace coast {

class Transform: public CoastComponent {

    public:
        Transform();
        ~Transform();
        inline static const std::string COMPONENT_NAME = "TransformComponent";
    
    protected:
    
    private:

};

} // namespace coast

#endif