
#include "common.h"

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

} // namespace Notes::Tool::Utils