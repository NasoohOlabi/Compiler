#include <fstream>
#include <iostream>

#include "BSlogger.hpp"
#include "ast.h"
#include "Parser.h"

#define pretty_print(x) std::cout << #x "=" << x << '\n'
#define pp(x) pretty_print(x)
#define STR(x) #x << '=' << x << ' '

#define init_persist()                       \
	ofstream myfile;                          \
	myfile.open("../last_run.log", ios::out); \
	LOG_INIT_CUSTOM(myfile);                  \
	log.set_log_level(LOG_DEBUG)
#define start_persist(level) log(level) <<
#define end_persist << '\n'
#define close_persist() myfile.close()

using std::cout;
using std::endl;
using std::ios;
using std::ofstream;

extern int yyparse();

int main() {
	cout << "Hello" << endl;
	int x = 4;

	init_persist();

	start_persist(LOG_INFO) "test52 " << x << '\n' << "test" end_persist;
	start_persist(LOG_DEBUG) STR(x) end_persist;

	pp(x);

	cout << STR(x) << '\n';

	close_persist();

	yyparse();

	return 0;
}
