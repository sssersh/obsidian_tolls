#pragma once

#include "parser/range.h"

#include <string_view>

namespace Notes::Tool::Utils
{

std::string_view getSubstr(std::string_view origin, Range range);
bool isLineBeginning(std::string_view text, std::size_t pos);

} // namespace Notes::Tool::Utils
