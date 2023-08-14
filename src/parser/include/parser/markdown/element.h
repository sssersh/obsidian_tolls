#pragma once

#include "parser/range.h"

#include <string_view>

namespace Notes::Tool::Markdown
{

struct Element
{
    enum class Necesserity
    {
        Optional = 0,
        Mandatory
    };

    Element(Necesserity necesserity, Range range);
    Range getRange() const noexcept;

private:
    Necesserity m_necesserity;
    Range m_range;
};

} // namespace Notes::Tool::Markdown
