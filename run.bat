"C:\Program Files (x86)\GnuWin32\bin\flex.exe" -oScanner.cpp scanner.l
"C:\Program Files (x86)\GnuWin32\bin\bison.exe" -dtv -o Parser.cpp --define=Parser.h Parser.y
g++ Parser.cpp Scanner.cpp Parser.h -o app

app.exe