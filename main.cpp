#include <fstream>
#include <iostream>

#include "BSlogger.hpp"
#include "Node.hpp"
#include "Parser.h"

using std::cout;
using std::endl;
using std::ios;
using std::ofstream;

extern int yyparse();

int main() {
	cout << "Hello" << endl;
	int x = 4;

	ofstream myfile;
	myfile.open("../last_run.log", ios::out);

	// LOG_INIT_CUSTOM(myfile);
	LOG_INIT_COUT();
	log(LOG_INFO) << "test " << '\n';

	myfile.close();

	yyparse();

	return 0;
}
