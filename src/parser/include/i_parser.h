#pragma once

#include "note/i_note.h"
#include "note/questions.h"

#include <string>

namespace Notes::Tool
{

template<typename T>
class IBaseParser
{
public:
    virtual T parse(std::string_view rawText) = 0;
};

using IQuestionParser = IBaseParser<Questions>;
using INoteParser = IBaseParser<INote>;

} // Notes::Tool
