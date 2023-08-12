
#include "range.h"

#include <gtest/gtest.h>

namespace Notes::Tool
{

TEST(Range, Creation)
{
    ASSERT_ANY_THROW(Range(1, 0));
    ASSERT_NO_THROW(Range(0, 0));
    ASSERT_NO_THROW(Range(0, 1));
    ASSERT_NO_THROW(Range(0, 2));
}

TEST(Range, Contained)
{
    ASSERT_TRUE(Range(0, 0).isContainedInString({}));
    ASSERT_TRUE(Range(0, 0).isContainedInString({"a"}));
    ASSERT_TRUE(Range(0, 1).isContainedInString({"a"}));

    ASSERT_FALSE(Range(0, 1).isContainedInString({}));
    ASSERT_FALSE(Range(0, 2).isContainedInString({"a"}));
    ASSERT_FALSE(Range(1, 2).isContainedInString({"a"}));

    ASSERT_TRUE(Range(0, 2).isContainedInString({"aaa"}));
    ASSERT_TRUE(Range(1, 2).isContainedInString({"aaa"}));
    ASSERT_TRUE(Range(2, 3).isContainedInString({"aaa"}));
    ASSERT_FALSE(Range(2, 4).isContainedInString({"aaa"}));
}

} // namespace Notes::Tool
