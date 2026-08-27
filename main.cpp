#include "custom_allocator/custom_allocator.hpp"
#include "custom_vector/custom_vector.cpp"
#include "iostream"
#include "list"
#include "map"
#include "string"
#include "tools/factorial.cpp"

constexpr std::size_t N = 10;
template <typename T>
using my_allocator = PoolAllocator<T, N>;

using customList = std::list<int, my_allocator<int>>;
using customMap  = std::map<int, int, std::less<>, my_allocator<std::pair<const int, int>>>;

int main ()
{
    std::map<int, int> map_default;
    for (auto i = 0; i < 10; ++i)
    {
        map_default[i] = factorial (i);
    }

    for (const auto& [key, value] : map_default)
    {
        std::cout << key << ' ' << value << '\n';
    }
    std::cout << '\n';

    customMap map_with_alloc;
    for (auto i = 0; i < 10; ++i)
    {
        map_with_alloc[i] = factorial (i);
    }

    for (const auto& [key, value] : map_with_alloc)
    {
        std::cout << key << ' ' << value << '\n';
    }
    std::cout << '\n';

    vector::CustomVector<int> myVector;
    for (auto i = 0; i < 10; ++i)
    {
        myVector.push_back (i);
    }

    for (int i : myVector)
    {
        std::cout << i << '\n';
    }
    std::cout << '\n';

    vector::CustomVector<int, my_allocator<int>> myVector_with_alloc;
    for (auto i = 0; i < 10; ++i)
    {
        myVector_with_alloc.push_back (i);
    }

    for (int i : myVector_with_alloc)
    {
        std::cout << i << '\n';
    }

    return 0;
}
