#pragma once

#include "parser/i_parser.h"

namespace Notes::Parser
{

template<typename T>
class Parser : public IBaseParser<T>
{
public:
    T parse(std::string_view rawText) override;
};

//using QuestionParser = Parser<Questions>;
using NoteParser = Parser<INote>;

} // namespace Notes::Parser