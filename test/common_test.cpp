
#include "common.h"

#include <gtest/gtest.h>

namespace Notes::Tool::Utils
{

TEST(Common, GetSubstr)
{
    ASSERT_EQ(getSubstr("a", { 0, 0 }), "");
    ASSERT_EQ(getSubstr("a", { 0, 1 }), "a");
    ASSERT_EQ(getSubstr("ab", { 0, 1 }), "a");
}

} // namespace Notes::Tool::Utils
