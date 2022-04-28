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

add_custom_command(
	TARGET Compiler PRE_BUILD
	# OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/Parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/Scanner.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/Parser.h 
	COMMAND powershell echo 'Generating Parsers...' 
	COMMAND powershell flex ../scanner.l 
	COMMAND powershell rm ../src/parsers/Scanner.cpp
	COMMAND powershell mv ./lex.yy.c ../src/parsers/Scanner.cpp
	COMMAND powershell bison -dtv -o "../src/parsers/Parser.cpp" --define="../include/Parser.h" ../Parser.y
	COMMAND powershell echo 'Finished generating Parsers.' 
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
