#pragma once

#include "common.h"

#include <string_view>

namespace Notes::Tool::Markdown
{

struct Title
{
    enum class Level
    {
        None = 0,
        One,
        Second,
        Third,
        Fours,
        Fivth,
        Sixth
    };

    Level m_level;
    Range m_range;
};

Title::Level isTitle(std::string_view str);
std::vector<Title> findTitles(std::string_view text);
std::vector<Range> findHorizontalDelimeters(std::string_view text);

} // namespace Notes::Tool::Markdown