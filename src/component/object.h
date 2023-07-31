#ifndef COAST_OBJECT_H_
#define COAST_OBJECT_H_

#include <string>
#include <unordered_map>

namespace coast {

class CoastObject {

    public:
        CoastObject();
        ~CoastObject();

        template <typename T>
        T addComponent(const T& component_class);
    
    protected:
        // std::unordered_map<std::string, coast::CoastComponent> _components;
    
    private:

};

} // namespace coast

#endif