#include <gtest/gtest.h>
#include <utility>

#include "set.hpp"

TEST(Test, t1) {
    Set s;
    ASSERT_EQ(s.size(), 0u);
}