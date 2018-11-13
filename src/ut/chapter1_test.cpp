#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "dollar.hpp"

namespace Test
{
    TEST(FirstTest, TestMultiplication)
    {
        Dollar* five = new Dollar(5);
        five->times(2);
        ASSERT_EQ(10, five->amount);
    }
} // Test