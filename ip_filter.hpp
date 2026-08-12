#pragma once

#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <string>
#include <tuple>
#include <vector>

typedef std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t> IPv4Address;

std::ostream& operator<< (std::ostream& os, const IPv4Address& ip);

std::vector<std::string> split (const std::string& str, char d);

IPv4Address              string_to_IPv4 (const std::string str);
std::vector<IPv4Address> filter_any (const std::vector<IPv4Address>& input, uint32_t filter);
std::vector<IPv4Address> filter_by_first (const std::vector<IPv4Address>& input, uint32_t filter);
std::vector<IPv4Address> filter_by_first_and_second (const std::vector<IPv4Address>& input, uint32_t byte0f,
                                                     uint32_t byte1f);
void                     print (const std::vector<IPv4Address>& ip_pool);