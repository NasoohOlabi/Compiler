cmake_minimum_required(VERSION 3.0.0)
project(Compiler VERSION 0.1.0)

include(CTest)
enable_testing()

# add_executable(Compiler main.cpp
# 		src/parsers/Parser.cpp
# 		src/parsers/Scanner.cpp
# )


add_custom_target(Parsers ALL)
add_custom_command(
	TARGET Parsers PRE_BUILD
	# OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/Parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/Scanner.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/Parser.h 
	# COMMAND powershell echo 'Generating Parsers...' & flex "../scanner.l" & del "../src/parsers/Scanner.cpp" & Move-Item -Path "./lex.yy.c" -Destination "../src/parsers/Scanner.cpp" & bison -dtv -o "../src/parsers/Parser.cpp" --define="../include/Parser.h" ../Parser.y & echo 'Finished generating Parsers.' 
	COMMAND powershell echo 'Generating Parsers...' & flex -o"../src/parsers/Scanner.cpp" "../scanner.l" & bison -dtv -o "../src/parsers/Parser.cpp" --define="../include/Parser.h" ../Parser.y & echo 'Finished generating Parsers.' 
	# COMMAND powershell bash ; echo 'Generating Parsers...' ; flex ../scanner.l ; rm ../src/parsers/Scanner.cpp ; mv ./lex.yy.c ../src/parsers/Scanner.cpp ; bison -dtv -o "../src/parsers/Parser.cpp" --define="../include/Parser.h" ../Parser.y ; echo 'Finished generating Parsers.' 
	)
	
	
file(GLOB_RECURSE sources src/* )
add_executable(Compiler main.cpp ${sources})
target_include_directories(Compiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_dependencies(Compiler Parsers)

# add_custom_target(Compiler ALL
# COMMAND Comp
# SOURCES main.cpp ${sources} 
# DEPENDS Parsers
# WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
# )



# SET(sources ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/*.cpp)

# SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/*.cpp GENERATED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
 