#ifndef COAST_COMPONENT_H_
#define COAST_COMPONENT_H_

#include <string>

namespace coast {

class CoastComponent {

    public:
        CoastComponent();
        ~CoastComponent();
        inline static const std::string COMPONENT_NAME = "BaseComponent";
    
    protected:
    
    private:

};

} // namespace coast

#endif