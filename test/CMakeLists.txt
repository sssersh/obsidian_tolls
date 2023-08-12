
project(gtest_tool)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    common_test.cpp
    markdown_test.cpp
    question_parser_test.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        note_parser
    # TODO: записать, как линкуется gtest
        GTest::gtest 
        GTest::gmock 
        GTest::gmock_main 
)
