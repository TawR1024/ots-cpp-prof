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

/**
 * @brief Type trait that detects container-like types.
 *
 * Matches types iterable with std::begin/std::end that also expose a value_type member.
 * std::string satisfies the trait as well, so it is excluded explicitly at the use site.
 */
template <typename T, typename = void>
struct is_container : std::false_type
{
};

template <typename T>
struct is_container<T, std::void_t<decltype (std::begin (std::declval<T> ())), decltype (std::end (std::declval<T> ())),
                                   typename T::value_type>> : std::true_type
{
};

/** @brief Convenience alias for is_container<T>::value. */
template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;

/**
 * @brief Prints the given value as an IP address followed by a newline.
 *
 * The output format depends on the argument type:
 *  - std::string is printed as is;
 *  - integral types are decomposed into bytes, most significant byte first,
 *    with octets separated by dots;
 *  - other container-like types are printed element by element, separated by dots.
 *
 * @tparam IP The type of the value to print.
 * @param ip_addr The value to print.
 */
template <typename IP>
void print_ip_ce (IP ip_addr)
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

/**
 * @brief Prints tuple elements in order, separated by dots, followed by a newline.
 *
 * @tparam Args The element types of the tuple.
 * @param ip_addr The tuple whose elements are printed.
 */
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

// SFINAE

template <bool cond, class T>
struct enable_if
{
    using type = T;
};

template <class T>
struct enable_if<false, T>
{
};

template <typename IP, typename = typename enable_if<std::is_same<IP, std::string>::value, IP>::type>
void print_ip (IP ip_addr)
{
    std::cout << ip_addr << "\n";
}

template <typename IP,
          typename std::enable_if<std::is_integral<IP>::value && !std::is_same<IP, std::string>::value, int>::type = 0>
void print_ip (IP ip_addr)
{
    for (size_t i = sizeof (IP); i-- > 0;)
    {
        std::cout << (i + 1 == sizeof (IP) ? "" : ".") << static_cast<int> (ip_addr >> (i * 8) & 0xFF);
    }
    std::cout << '\n';
}

template <typename IP, typename enable_if<is_container_v<IP> && !std::is_same<IP, std::string>::value, int>::type = 0>
void print_ip (const IP& ip_addr)
{
    bool first = true;
    for (auto& octet : ip_addr)
    {
        if (!first)
            std::cout << ".";
        std::cout << octet;
        first = false;
    }
    std::cout << '\n';
}