#pragma once

#include "parser/range.h"

#include <string_view>

// TODO: move from markdown

namespace Notes::Parser::Markdown
{

struct Element
{

    Element(Range range);
    Range getRange() const noexcept;

private:
    Range m_range;
};

} // namespace Notes::Parser::Markdown
