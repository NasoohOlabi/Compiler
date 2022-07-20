#include "ast.h"
#include "Parser.h"
#include <cstdlib>

extern int yyparse();

extern Program *root;
// extern FUNCTION *root;

int main()
{
	freopen(SRC_PATH "/test.mp", "r", stdin);
	// freopen(SRC_PATH "/Input-Clean.mp", "r", stdin);
	cout << "\n\nParsing started...\n\n";
	yyparse();
	cout << "\n\nParsing is done...\n\n";
	root;

	// NodeVisitor *pv = new PrintVisitor();
	// root->accept(pv);

	NodeVisitor *pv = new TypeVisitor();
	root->accept(pv);

	cout << "\n\nType Checking Finished... Starting Code Generation:\n\n";

	NodeVisitor *cv = new CodeVisitor();
	root->accept(cv);

	string cmd = ".\\\\..\\\\VM\\\\vm.exe -dump ../code.txt";
	const char *command = cmd.c_str();
	system(command);

	return 0;
}
