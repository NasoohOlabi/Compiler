flex -oScanner.cpp scanner.l
bison -dtv -o Parser.cpp --define=Parser.h Parser.y
g++ Parser.cpp Scanner.cpp Parser.h -o app
del Parser.cpp
del Scanner.cpp
del Parser.output
del Parser.h.gch
app.exe