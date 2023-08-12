
#include "parser/common.h"

#include <gtest/gtest.h>

namespace Notes::Tool::Utils
{

TEST(Common, GetSubstr)
{
    ASSERT_EQ(getSubstr("a", { 0, 0 }), "");
    ASSERT_EQ(getSubstr("a", { 0, 1 }), "a");
    ASSERT_EQ(getSubstr("ab", { 0, 1 }), "a");
}

TEST(Common, isLineBeginning)
{
    ASSERT_TRUE(isLineBeginning("a", 0));
    ASSERT_TRUE(isLineBeginning("a\nb", 2));

    ASSERT_FALSE(isLineBeginning("", 0));
    ASSERT_FALSE(isLineBeginning("a", 1));
    ASSERT_FALSE(isLineBeginning("a\nb", 1));
}

} // namespace Notes::Tool::Utils
