
#include "parser/common.h"
#include "parser/markdown/markdown.h"

namespace Notes::Parser::Markdown
{

std::vector<Title> findTitles(std::string_view text)
{
    std::vector<Title> result;

    std::size_t pos = 0, prev = 0;
	while (true)
    {
        pos = text.find("#", prev);
        if (pos == std::string_view::npos)
            break;

        std::string_view titleCandidate { text.begin() + pos, text.end() };
        Title::Level level;
        if (Utils::isLineBeginning(text, pos) && (level = Title::isTitle(titleCandidate), level != Title::Level::None))
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

} // namespace Notes::Parser::Markdown
