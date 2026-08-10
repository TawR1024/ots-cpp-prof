#include <gtest/gtest.h>

#include "lib.h"

class VersionTest : public ::testing::Test
{
};

TEST_F (VersionTest, CheckAppVersion) { EXPECT_GT (version (), 0); }
