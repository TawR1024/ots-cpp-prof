#include "ip_filter.hpp"

#include <gtest/gtest.h>

class IPFilter : public ::testing::Test
{
   public:
    std::vector<std::string> input{"10.20.30.40", "1.1.1.1", "8.8.8.8", "192.168.1.1", "192.168.1.1"};
    std::vector<std::string> bad_input{"234.666.999.1"};
};

TEST_F (IPFilter, convertStringToIPv4)
{
    EXPECT_EQ (IPv4Address (this->input.at (0)), IPv4Address (10u, 20u, 30u, 40u));
    EXPECT_EQ (IPv4Address (this->input.at (2)), IPv4Address (8u, 8u, 8u, 8u));
    EXPECT_THROW (IPv4Address (this->bad_input.at (0)), std::out_of_range);
}

TEST_F (IPFilter, filter_by_first_octet)
{
    std::vector<IPv4Address> input_ip;
    std::vector<IPv4Address> result = {IPv4Address (1u, 1u, 1u, 1u)};

    for (const auto& s : input)
    {
        input_ip.push_back (IPv4Address (s));
    }

    EXPECT_EQ (filter (input_ip, 1u), result);
}