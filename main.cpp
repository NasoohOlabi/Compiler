#include <iostream>

#include "Parser.h"
using std::cout;
using std::endl;
extern int yyparse();

int main() {
	cout << "Hello" << endl;
	yyparse();
	return 0;
}
