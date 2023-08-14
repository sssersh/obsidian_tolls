#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace Notes::Tool
{

struct Question
{
    std::size_t m_group;
    std::string m_text;
};

using Questions = std::vector<Question>;

} // Notes::Tool
