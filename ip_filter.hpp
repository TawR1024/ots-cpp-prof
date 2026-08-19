#pragma once

#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <string>
#include <tuple>
#include <vector>

std::vector<std::string> split(const std::string& str, char d);

class IPv4Address
{
   public:
    std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t> address;

    IPv4Address() : address(0, 0, 0, 0) {};
    IPv4Address(std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t d)
        : address(a, b, c, d) {}  // for tests without validation

    IPv4Address(const std::string& str)
    {
        auto parts = split(str, '.');
        if (parts.size() != 4)
            throw std::invalid_argument("IPv4Adress: expected 4 octets");
        // validate each octet
        auto parce = [](const std::string& s) -> std::uint32_t
        {
            int val = std::stoi(s);
            if (val < 0 || val > 255)
                throw std::out_of_range("IPv4Adress: octet value is out of range");
            return static_cast<std::uint32_t>(val);
        };

        address = std::make_tuple(parce(parts[0]), parce(parts[1]), parce(parts[2]), parce(parts[3]));
    }
    bool operator==(const IPv4Address& other) const { return address == other.address; }
    bool operator<(const IPv4Address& other) const { return address < other.address; }
    bool operator>(const IPv4Address& other) const { return address > other.address; }
};

template <typename... Filter>
std::vector<IPv4Address> filter(const std::vector<IPv4Address>& input, Filter... filters)
{
    std::array<std::uint32_t, sizeof...(Filter)> filters_arr{static_cast<std::uint32_t>(filters)...};

    auto matches = [&](const IPv4Address& ip)
    {
        for (std::size_t i = 0; i < filters_arr.size(); ++i)
        {
            auto octet = (i == 0)   ? std::get<0>(ip.address)
                         : (i == 1) ? std::get<1>(ip.address)
                         : (i == 2) ? std::get<2>(ip.address)
                                    : std::get<3>(ip.address);
            if (octet != filters_arr[i])
                return false;
        }
        return true;
    };

    std::vector<IPv4Address> filtered;
    for (const auto& ip : input)
        if (matches(ip))
            filtered.push_back(ip);
    return filtered;
}
std::vector<IPv4Address> filter_any(const std::vector<IPv4Address>& input, uint32_t value);
void                     print(const std::vector<IPv4Address>& ip_pool);
std::ostream&            operator<<(std::ostream& os, const IPv4Address& ip);