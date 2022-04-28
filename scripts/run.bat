@REM flex -d -o"src/parsers/Scanner.cpp" scanner.l
flex -o"src/parsers/Scanner.cpp" scanner.l
bison -dtv -o "src/parsers/Parser.cpp" --define="include/Parser.h" Parser.y

@REM g++ Parser.cpp Scanner.cpp Parser.h -o app

@REM app.exe