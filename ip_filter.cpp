#include "ip_filter.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split (const std::string& str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop  = str.find_first_of (d);
    while (stop != std::string::npos)
    {
        r.push_back (str.substr (start, stop - start));

        start = stop + 1;
        stop  = str.find_first_of (d, start);
    }

    r.push_back (str.substr (start));

    return r;
}

IPv4Address string_to_IPv4 (const std::string str)
{
    auto        parts = split (str, '.');
    IPv4Address ip =
        std::make_tuple (std::stoi (parts[0]), std::stoi (parts[1]), std::stoi (parts[2]), std::stoi (parts[3]));
    return ip;
}

std::vector<IPv4Address> filter_any (const std::vector<IPv4Address>& input, uint32_t filter)
{
    std::vector<IPv4Address> filtered;
    for (const auto& ip : input)
    {
        if (std::get<0> (ip) == filter || std::get<1> (ip) == filter || std::get<2> (ip) == filter ||
            std::get<3> (ip) == filter)
        {
            filtered.push_back (ip);
        }
    }

    return filtered;
}

std::vector<IPv4Address> filter_by_first (const std::vector<IPv4Address>& input, uint32_t filter)
{
    std::vector<IPv4Address> filtered;
    for (const auto& ip : input)
    {
        if (std::get<0> (ip) == filter)
        {
            filtered.push_back (ip);
        }
    }

    return filtered;
}

std::vector<IPv4Address> filter_by_first_and_second (const std::vector<IPv4Address>& input, uint32_t byte0f,
                                                     uint32_t byte1f)
{
    std::vector<IPv4Address> filtered;
    for (const auto& ip : input)
    {
        if (std::get<0> (ip) == byte0f && std::get<1> (ip) == byte1f)
        {
            filtered.push_back (ip);
        }
    }

    return filtered;
}

void print (const std::vector<IPv4Address>& ip_pool)
{
    for (auto ip = ip_pool.cbegin (); ip != ip_pool.cend (); ++ip)
    {
        if (ip != ip_pool.cbegin ())
            std::cout << "\n";
        std::cout << *ip;
    }
}

std::ostream& operator<< (std::ostream& os, const IPv4Address& ip)
{
    return os << std::get<0> (ip) << "." << std::get<1> (ip) << "." << std::get<2> (ip) << "." << std::get<3> (ip);
}