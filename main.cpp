#include "ast.h"
#include "Parser.h"

extern int yyparse();

// extern Program *root;
extern FUNCTION *root;

int main()
{
	freopen(SRC_PATH"/Input.mp","r",stdin);
	yyparse();
	cout << "Parsing is done...\n";
	root;
	// NodeVisitor *pv = new PrintVisitor();
	// root->accept(pv);
	return 0;
}
