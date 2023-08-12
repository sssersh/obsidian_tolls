
#include "parser/markdown/base_element.h"

namespace Notes::Tool::Markdown
{

BaseElement::BaseElement(Range range)
    : m_range(range)
{}

Range BaseElement::getRange() const noexcept
{
    return m_range;
}

} // namespace Notes::Tool::Markdown
