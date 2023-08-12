#pragma once

#include "range.h"

#include <string_view>

namespace Notes::Tool::Utils
{

std::string_view getSubstr(std::string_view origin, Range range);

} // namespace Notes::Tool::Utils
