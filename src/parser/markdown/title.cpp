
#include "parser/markdown/title.h"
#include "parser/common.h"

namespace Notes::Tool::Markdown
{

Title::Level Title::isTitle(std::string_view str)
{
    std::size_t level = 0;

    while (level < str.size() && str[level] == '#')
        level++;

    auto spacePosition = level;
    auto namePosition = spacePosition + 1;

    if (!level                     ||
        namePosition >= str.size() ||
        str[spacePosition] != ' ')
        return Title::Level::None;

    return static_cast<Title::Level>(level);
}

Title::Title(Level level, Range range, std::string_view name)
    : BaseElement(range)
    , m_level(level)
    , m_name(name)
{}

std::string_view Title::getName() const noexcept 
{
    return m_name;
}

Title::Level Title::getLevel() const noexcept 
{
    return m_level;
}

Title Title::createTitle(std::string_view text, Level level, Range range)
{
    auto titleData = Utils::getSubstr(text, range);
    std::size_t namePos = (std::size_t)level + sizeof(' ');
    std::string_view name { titleData.begin() + namePos, titleData.begin() + range.size() };

    return { level, range, name };
}

} // namespace Notes::Tool::Markdown