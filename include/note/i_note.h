#pragma once

#include <string_view>

namespace Notes
{

class INote
{
public:
    enum class Part
    {
        Info,
        Comments,
        Questions,
        Metainfo,
        Listings
    };

    virtual std::string_view getText() const = 0;

};

} // Notes