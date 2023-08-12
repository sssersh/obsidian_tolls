#pragma once

#include "parser/range.h"

#include <string_view>

namespace Notes::Tool::Markdown
{

struct BaseElement
{
    BaseElement(Range range);
    Range getRange() const noexcept;

private:
    Range m_range;
};

} // namespace Notes::Tool::Markdown
