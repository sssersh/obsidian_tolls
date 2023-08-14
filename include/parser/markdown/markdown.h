#pragma once

#include "parser/common.h"
#include "parser/markdown/title.h"

#include <string_view>

namespace Notes::Parser::Markdown
{

std::vector<Title> findTitles(std::string_view text);
std::vector<Range> findHorizontalDelimeters(std::string_view text);

} // namespace Notes::Markdown
