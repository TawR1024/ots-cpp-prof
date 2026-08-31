#pragma once
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iterator>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include "iostream"

template <typename T, typename = void>
struct is_container : std::false_type
{
};

template <typename T>
struct is_container<T, std::void_t<decltype (std::begin (std::declval<T> ())), decltype (std::end (std::declval<T> ())),
                                   typename T::value_type>> : std::true_type
{
};

template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;

template <typename IP>
void print_ip (IP ip_addr)
{
    if constexpr (std::is_same_v<IP, std::string>)
    {
        std::cout << ip_addr;
    }
    else if constexpr (std::is_integral_v<IP>)
    {
        for (size_t i = sizeof (IP); i-- > 0;)
        {
            auto byte = static_cast<int> (ip_addr >> (i * 8) & 0xFF);
            std::cout << byte;
            if (i != 0)
            {
                std::cout << ".";
            }
        }
    }
    else if constexpr (is_container_v<IP> && !std::is_same_v<IP, std::string>)
    {
        bool first = true;
        for (auto& octet : ip_addr)
        {
            if (!first)
            {
                std::cout << ".";
            }
            std::cout << octet;
            first = false;
        }
    }
    std::cout << '\n';
}

template <typename... Args>
void print_ip (const std::tuple<Args...>& ip_addr)
{
    std::apply (
        [] (const auto&... args)
        {
            size_t i = 0;
            ((std::cout << (i++ == 0 ? "" : ".") << args), ...);
            std::cout << '\n';
        },
        ip_addr);
}