#pragma once

#include "parser/range.h"

#include <string_view>

namespace Notes::Tool::Markdown
{

struct Title
{
    enum class Level
    {
        None = 0,
        First,
        Second,
        Third,
        Fours,
        Fivth,
        Sixth
    };

    Title(Level level, Range range, std::string_view name);

    std::string_view getName() const noexcept;
    Level getLevel() const noexcept;
    Range getRange() const noexcept;

    static Title::Level isTitle(std::string_view str);
    static Title createTitle(std::string_view text, Level level, Range range);

private:
    Level m_level;
    Range m_range;
    std::string_view m_name;
};


std::vector<Title> findTitles(std::string_view text);
std::vector<Range> findHorizontalDelimeters(std::string_view text);

} // namespace Notes::Tool::Markdown
