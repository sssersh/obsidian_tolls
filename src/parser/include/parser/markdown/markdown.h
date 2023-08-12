#pragma once

#include "parser/common.h"
#include "parser/markdown/title.h"

#include <string_view>

namespace Notes::Tool::Markdown
{

std::vector<Title> findTitles(std::string_view text);
std::vector<Range> findHorizontalDelimeters(std::string_view text);

} // namespace Notes::Tool::Markdown
