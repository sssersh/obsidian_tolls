
#include "common.h"
#include "markdown.h"

namespace Notes::Tool::Markdown
{

Title::Level isTitle(std::string_view str, Range range)
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

std::vector<Title> findTitles(std::string_view text)
{
    std::vector<Title> result;

    std::size_t pos = 0, prev = 0;
	while (true)
    {
        pos = text.find("#", prev);
        if (pos == std::string_view::npos)
            break;

        Range titleRange { pos, text.size() - pos };
        if (auto level = isTitle(text, titleRange); level != Title::Level::None)
        {
            auto begin = pos;
            pos = text.find("\n", pos);
            Range range { begin, pos != std::string_view::npos ? pos : text.size() };
            auto title = Title::createTitle(text, level, range);
            result.push_back(std::move(title));
        }
        else
        {
            ++pos;
        }
        if (pos == std::string_view::npos || pos >= text.size())
            break;

        prev = pos;
    }

    return result;
}

std::vector<Range> findHorizontalDelimeters(std::string_view text)
{
    // TODO: delimeter - "\n[-][-][-][-]*\n"
    // позиция с N+1 от текущего разделителя до следующего разделителя - значение
    return {};
}

} // namespace Notes::Tool::Markdown