
#include "parser/markdown/element.h"

namespace Notes::Parser::Markdown
{

Element::Element(Range range)
    : m_range(range)
{}

Range Element::getRange() const noexcept
{
    return m_range;
}

} // namespace Notes::Parser::Markdown
