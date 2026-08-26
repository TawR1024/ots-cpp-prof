#include "custom_allocator/custom_allocator.hpp"
#include "iostream"
#include "list"
#include "map"
#include "math.h"
#include "string"
#include "tools/factorial.cpp"

constexpr std::size_t N = 10;
template <typename T>  // just have a fun with templates
using my_allocator = PoolAllocator<T, N>;
using customList   = std::list<int, my_allocator<int>>;
using customMap    = std::map<int, int, std::less<int>, my_allocator<std::pair<const int, int>>>;

int main ()
{
    customList list_with_alloc;
    for (auto i = 0; i < 10; ++i)
    {
        list_with_alloc.emplace_back (factorial (i));
    }

    customMap map_with_alloc;
    for (auto i = 0; i < 10; ++i)
    {
        map_with_alloc[i] = factorial (i);
    }

    std::cout << "done" << std::endl;

    return 0;
}
