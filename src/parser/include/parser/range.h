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

    std::size_t size() const noexcept
    {
        return m_end - m_begin;
    }

    bool isContainedInString(std::string_view str)
    {
        return begin() <= str.size() && (begin() + size()) <= str.size();
    }
    
private:
    std::size_t m_begin;
    std::size_t m_end;
};

// TODO: оператор сравнения, чтобы можно было в set хранить

} // namespace Notes::Tool