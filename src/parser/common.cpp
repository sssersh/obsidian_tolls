
#include "parser/common.h"

namespace Notes::Tool::Utils
{

std::string_view getSubstr(std::string_view origin, Range range)
{
    if (!range.isContainedInString(origin))
    {
        throw std::runtime_error("Incorrect range or string");
    }
    return { origin.begin() + range.begin(), range.size() };   
}

bool isLineBeginning(std::string_view text, std::size_t pos)
{
    return pos < text.size() && ( pos == 0 || text[pos - 1] == '\n');
}

} // namespace Notes::Tool::Utils