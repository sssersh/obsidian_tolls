#pragma once

#include <stdexcept>

namespace Notes::Tool::Markdown
{

struct Range
{
    Range(std::size_t begin, std::size_t end)
        : m_begin(begin)
        , m_end(end)
    {
        if (end < begin) throw std::runtime_error("Incorrect range");
    }

    std::size_t m_begin;
    std::size_t m_end;
};

} // namespace Notes::Tool