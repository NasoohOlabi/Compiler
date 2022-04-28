cmake_minimum_required(VERSION 3.0.0)
project(Compiler VERSION 0.1.0)

include(CTest)
enable_testing()

# add_executable(Compiler main.cpp
# 		src/parsers/Parser.cpp
# 		src/parsers/Scanner.cpp
# )

file(GLOB_RECURSE sources src/*)
add_executable(Compiler main.cpp ${sources})

target_include_directories(Compiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
