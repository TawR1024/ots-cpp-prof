#pragma once

#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <string>
#include <tuple>
#include <vector>

std::vector<std::string> split (const std::string& str, char d);

class IPv4Address
{
   public:
    std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t> address;

    IPv4Address () : address (0, 0, 0, 0) {};
    IPv4Address (std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t d)
        : address (a, b, c, d) {}  // for tests without validation

    IPv4Address (const std::string& str)
    {
        auto parts = split (str, '.');
        if (parts.size () != 4)
            throw std::invalid_argument ("IPv4Adress: expected 4 octets");
        // validate each octet
        auto parce = [] (const std::string& s) -> std::uint32_t
        {
            int val = std::stoi (s);
            if (val < 0 || val > 255)
                throw std::out_of_range ("IPv4Adress: octet value is out of range");
            return static_cast<std::uint32_t> (val);
        };

        address = std::make_tuple (parce (parts[0]), parce (parts[1]), parce (parts[2]), parce (parts[3]));
    }
    bool operator== (const IPv4Address& other) const { return address == other.address; }
};

// std::vector<IPv4Address> filter_any (const std::vector<IPv4Address>& input, uint32_t filter);
// std::vector<IPv4Address> filter_by_first (const std::vector<IPv4Address>& input, uint32_t filter);
// std::vector<IPv4Address> filter_by_first_and_second (const std::vector<IPv4Address>& input, uint32_t byte0f,
//                                                      uint32_t byte1f);
void          print (const std::vector<IPv4Address>& ip_pool);
std::ostream& operator<< (std::ostream& os, const IPv4Address& ip);