
#include "markdown.h"

namespace Notes::Tool::Markdown
{

Title::Level isTitle(std::string_view str)
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

    std::size_t pos = 0, prev = 0, begin = 0;
	while ((pos != std::string_view::npos) && (pos = text.find("#", prev)))
    {
        if (auto level = isTitle({ text.begin() + pos, text.end() }); level != Title::Level::None)
        {
            auto begin = pos;
            pos = text.find("\n", pos);
            Title title
            {
                .m_level = level,
                .m_range = { begin, pos != std::string_view::npos ? pos : text.size() } 
            };
            result.push_back(std::move(title));
        }
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