
#include "parser.h"

#include <regex>

namespace Notes::Tool
{

template<>
Questions Parser<Questions>::parse(std::string_view rawText)
{


    (void) rawText;
    return {};
}

} // namespace Notes::Tool
