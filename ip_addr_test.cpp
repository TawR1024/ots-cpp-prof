#include "ip_addr.hpp"

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"

class IPPrinter : public testing::Test
{
};

TEST_F (IPPrinter, print_string)
{
    testing::internal::CaptureStdout ();
    print_ip (std::string{"test_string"});
    EXPECT_EQ (testing::internal::GetCapturedStdout (), "test_string\n");
}

TEST_F (IPPrinter, print_int8)
{
    testing::internal::CaptureStdout ();
    print_ip (int8_t{1});
    EXPECT_EQ (testing::internal::GetCapturedStdout (), "1\n");
}

TEST_F (IPPrinter, print_int64)
{
    testing::internal::CaptureStdout ();
    print_ip (int64_t{8875824491850138409});
    EXPECT_EQ (testing::internal::GetCapturedStdout (), "123.45.67.89.101.112.131.41\n");
}

TEST_F (IPPrinter, print_vector)
{
    testing::internal::CaptureStdout ();
    print_ip (std::vector<int>{10, 20, 40, 40});
    EXPECT_EQ (testing::internal::GetCapturedStdout (), "10.20.40.40\n");
}
