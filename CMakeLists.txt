
# TODO: записать
cmake_minimum_required(VERSION 3.26)

project(tool)

set(CMAKE_CXX_STANDARD 20)

add_library(note_parser
    src/note/scheme/element.cpp    

    src/parser/common.cpp
    src/parser/markdown/markdown.cpp
    src/parser/markdown/element.cpp
    src/parser/markdown/title.cpp
    src/parser/questions_parser.cpp
)

target_include_directories(note_parser PUBLIC include)

add_subdirectory(test)
