#include "complex.h"
#include "gtest/gtest.h"

namespace {

    TEST(Complex, Basics) {
        Complex a = (Complex ) { 2, 3 },
                 b = (Complex ) { 4, 5 };
        EXPECT_EQ(add(a,b).num,22);
        EXPECT_EQ(add(a,b).den,15);
        EXPECT_EQ(multiply(a,b).num,8);
        EXPECT_EQ(multiply(a,b).den,15);
    }

}
