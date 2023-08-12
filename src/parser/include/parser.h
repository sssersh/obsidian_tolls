#pragma once

#include "i_parser.h"

namespace Notes::Tool
{

template<typename T>
class Parser : public IBaseParser<T>
{
public:
    T parse(std::string_view rawText) override;
};

using QuestionParser = Parser<Questions>;
using NoteParser = Parser<INote>;

} // namespace Notes::Tool