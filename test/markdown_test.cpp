
#include "parser/markdown/markdown.h"

#include <gmock/gmock.h>

namespace Notes::Parser::Markdown
{

static constexpr std::string_view correctTitles = R"(
# Title 1
## Title 2
### Title 3
)";

static constexpr std::string_view incorrectTitles = R"(
#tag
 #tag2
 # Not title
)";

TEST(IsTitleTest, Success)
{
    ASSERT_EQ(Title::isTitle("# Title 1"), Title::Level::First);
    ASSERT_EQ(Title::isTitle("## Title 1"), Title::Level::Second);
    ASSERT_EQ(Title::isTitle("### Title 1"), Title::Level::Third);
    ASSERT_EQ(Title::isTitle("#### Title 1"), Title::Level::Fours);
    ASSERT_EQ(Title::isTitle("##### Title 1"), Title::Level::Fivth);
    ASSERT_EQ(Title::isTitle("###### Title 1"), Title::Level::Sixth);
}

TEST(IsTitleTest, Fail)
{
    ASSERT_EQ(Title::isTitle(""), Title::Level::None);
    ASSERT_EQ(Title::isTitle("#"), Title::Level::None);
    ASSERT_EQ(Title::isTitle("# "), Title::Level::None);
    ASSERT_EQ(Title::isTitle(" "), Title::Level::None);
    ASSERT_EQ(Title::isTitle(" #"), Title::Level::None);
    ASSERT_EQ(Title::isTitle(" # "), Title::Level::None);
}

TEST(FindTitlesTest, Success)
{
    auto result = findTitles(correctTitles);

    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0].getName(), "Title 1");
    ASSERT_EQ(result[1].getName(), "Title 2");
    ASSERT_EQ(result[2].getName(), "Title 3");
    ASSERT_EQ(result[0].getLevel(), Title::Title::Level::First);
    ASSERT_EQ(result[1].getLevel(), Title::Title::Level::Second);
    ASSERT_EQ(result[2].getLevel(), Title::Title::Level::Third);
}

TEST(FindTitlesTest, Fail)
{
    ASSERT_TRUE(findTitles(incorrectTitles).empty());
}

} // namespace Notes::Parser::Markdown