
#include <type_traits>

template<typename T>
T factorial(T nuber) { // check that not double
    if (nuber <= 1) {
        return 1;
    }else {
        return nuber * factorial(nuber-1);
    }
}

