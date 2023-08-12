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
        First,
        Second,
        Third,
        Fours,
        Fivth,
        Sixth
    };

    Title(
        Level level,
        Range range,
        std::string_view name)
        : m_level(level)
        , m_range(range)
        , m_name(name)
    {}

    std::string_view getName() const noexcept 
    {
        return m_name;
    }

    Level getLevel() const noexcept 
    {
        return m_level;
    }

    Range getRange() const noexcept
    {
        return m_range;
    }

    static Title createTitle(std::string_view text, Level level, Range range)
    {
        auto titleData = Utils::getSubstr(text, range);
        std::size_t namePos = (std::size_t)level + sizeof(' ');
        std::string_view name { titleData.begin() + namePos, titleData.begin() + range.size() };

        return { level, range, name };
    }

private:
    Level m_level;
    Range m_range;
    std::string_view m_name;
};

// TODO: add infinitely to Range and use it here
Title::Level isTitle(std::string_view str, Range range = { 0, str.size() });
std::vector<Title> findTitles(std::string_view text);
std::vector<Range> findHorizontalDelimeters(std::string_view text);

} // namespace Notes::Tool::Markdown