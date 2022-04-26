flex -oScanner.cpp scanner.l
bison -dtv -o Parser.cpp --define=Parser.h Parser.y
g++ Parser.cpp Scanner.cpp Parser.h -o app

app.exe