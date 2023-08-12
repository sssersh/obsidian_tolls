
#include "markdown.h"

#include <gmock/gmock.h>

#include <string_view>

namespace Notes::Tool
{

static constexpr std::string_view correctTitles = R"(
# Title 1
## Title 2
### Title 3
)";

// #tag
//  #tag2
//  # Not title

TEST(IsTitleTest, Success)
{
    ASSERT_EQ(Markdown::isTitle("# Title 1"), Markdown::Title::Level::One);
    ASSERT_EQ(Markdown::isTitle("## Title 1"), Markdown::Title::Level::Second);
    ASSERT_EQ(Markdown::isTitle("### Title 1"), Markdown::Title::Level::Third);
    ASSERT_EQ(Markdown::isTitle("#### Title 1"), Markdown::Title::Level::Fours);
    ASSERT_EQ(Markdown::isTitle("##### Title 1"), Markdown::Title::Level::Fivth);
    ASSERT_EQ(Markdown::isTitle("###### Title 1"), Markdown::Title::Level::Sixth);
}

TEST(IsTitleTest, Fail)
{
    ASSERT_EQ(Markdown::isTitle(""), Markdown::Title::Level::None);
    ASSERT_EQ(Markdown::isTitle("#"), Markdown::Title::Level::None);
    ASSERT_EQ(Markdown::isTitle("# "), Markdown::Title::Level::None);
    ASSERT_EQ(Markdown::isTitle(" "), Markdown::Title::Level::None);
    ASSERT_EQ(Markdown::isTitle(" #"), Markdown::Title::Level::None);
    ASSERT_EQ(Markdown::isTitle(" # "), Markdown::Title::Level::None);
}

TEST(FindTitlesTest, Success)
{
    auto result = Markdown::findTitles(correctTitles);

    ASSERT_EQ(result.size(), 3);
}

} // namespace Notes::Tool