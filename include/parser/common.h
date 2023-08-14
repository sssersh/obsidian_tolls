#pragma once

#include "parser/range.h"

#include <string_view>

namespace Notes::Parser::Utils
{

std::string_view getSubstr(std::string_view origin, Range range);
bool isLineBeginning(std::string_view text, std::size_t pos);

} // namespace Notes::Parser::Utils
