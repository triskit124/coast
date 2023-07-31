#include <cassert>

#include "math.h"

namespace coast::math {

template <typename T>
std::vector<T> vec_add(const std::vector<T>& a, std::vector<T>& b) {
    assert(a.size() == b.size());
    std::vector<T> c = std::vector<T>(a.size());
    for (size_t i; i < a.size(); ++i) {
        c[i] = a[i] + b[i];
    }
    return c;
}

} // namespace coast::math