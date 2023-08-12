
#include "parser/parser.h"

#include <gmock/gmock.h>

#include <string_view>

static constexpr std::string_view testText1 = R"(
- Question 1
- Question 2
---
- Question 3
- Question 4
- Multi
line
question 5
---
Question 6
)";

// Добавить тексты с разделителем в начале и в конце

// TEST(QuestionParserTest, Test1)
// {
//     auto parser = Notes::Tool::QuestionParser{};

//     auto result = parser.parse(testText1);

//     ASSERT_EQ(result.size(), 6);
// }
