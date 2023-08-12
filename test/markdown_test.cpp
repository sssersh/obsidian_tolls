
#include "markdown.h"

#include <gmock/gmock.h>

#include <string_view>

namespace Notes::Tool::Markdown
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
    ASSERT_EQ(Markdown::isTitle("# Title 1"), Markdown::Title::Level::First);
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

// TEST(FindTitlesTest, Success)
// {
//     auto result = Markdown::findTitles(correctTitles);

//     ASSERT_EQ(result.size(), 3);
//     ASSERT_EQ(result[0].getName(), "Title 1");
//     ASSERT_EQ(result[1].getName(), "Title 2");
//     ASSERT_EQ(result[2].getName(), "Title 3");
//     ASSERT_EQ(result[0].getLevel(), Title::Level::First);
//     ASSERT_EQ(result[1].getLevel(), Title::Level::Second);
//     ASSERT_EQ(result[2].getLevel(), Title::Level::Third);
// }

// TEST(FindTitlesTest, Fail)
// {
//     ASSERT_TRUE(Markdown::findTitles(incorrectTitles).empty());
// }

} // namespace Notes::Tool::Markdown