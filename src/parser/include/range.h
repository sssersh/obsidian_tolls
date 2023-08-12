#pragma once

#include <stdexcept>
#include <string_view>

namespace Notes::Tool
{

struct Range
{
    Range(std::size_t begin, std::size_t end)
        : m_begin(begin)
        , m_end(end)
    {
        if (end < begin) throw std::runtime_error("Incorrect range");
    }

    std::size_t begin() const noexcept
    {
        return m_begin;
    }

    std::size_t end() const noexcept
    {
        return m_end;
    }

    bool isContainedInString(std::string_view str)
    {
        return begin() <= str.size() && end() <= str.size();
    }

private:
    std::size_t m_begin;
    std::size_t m_end;
};

} // namespace Notes::Tool