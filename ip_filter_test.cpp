#include "ip_filter.hpp"

#include <gtest/gtest.h>

class IPFilter : public ::testing::Test
{
   public:
    std::vector<std::string> input{"10.20.30.40", "1.1.1.1", "8.8.8.8", "192.168.1.1", "192.168.1.1"};
};

TEST_F (IPFilter, convertStringToIPv4)
{
    EXPECT_EQ (string_to_IPv4 (this->input.at (0)), std::make_tuple (10u, 20u, 30u, 40u));
    EXPECT_EQ (string_to_IPv4 ("1.1.1.1"), std::make_tuple (1u, 1u, 1u, 1u));
}

TEST_F (IPFilter, filter_by_first_octet)
{
    std::vector<IPv4Address> input_ip;
    std::vector<IPv4Address> result{std::make_tuple (1u, 1u, 1u, 1u)};

    for (const auto& s : input)
    {
        input_ip.push_back (string_to_IPv4 (s));
    }

    EXPECT_EQ (filter_by_first (input_ip, 1), result);
}