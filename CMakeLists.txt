cmake_minimum_required(VERSION 3.0.0)
project(Compiler VERSION 0.1.0)

include(CTest)
enable_testing()

add_custom_target(Parsers ALL)
add_custom_command(
	TARGET Parsers PRE_BUILD
	COMMAND powershell echo 'Generating Parsers...' & flex -o"../src/parsers/Scanner.cpp" "../scanner.l" &  s -dtv -o "../src/parsers/Parser.cpp" --define="../include/Parser.h" ../Parser.y & echo 'Finished generating Parsers.' & ".\\..\\VM\\vm.exe" -dump "../code.txt"
	DEPENDS ../Parser.y ../scanner.l
	)
	
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# C++14: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
	
file(GLOB_RECURSE sources src/* )
add_executable(Compiler main.cpp ${sources})
target_include_directories(Compiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_dependencies(Compiler Parsers)


add_definitions(-DSRC_PATH="${CMAKE_SOURCE_DIR}")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
 