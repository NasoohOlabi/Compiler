#include <iostream>

// #include "BSlogger.hpp"
// #include "Flogger.hpp"
#include "Node.hpp"
#include "Parser.h"

using std::cout;
using std::endl;
extern int yyparse();

int main() {
	cout << "Hello" << endl;
	int x = 4;

	// // Initiate logger (default name is 'log')
	// LOG_INIT_CERR();

	// log(LOG_INFO) << "Arg: "
	//               << " => " << '\n';

	// ige::FileLogger flogger("log");

	yyparse();

	return 0;
}
