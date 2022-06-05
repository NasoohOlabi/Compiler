#include "ast.h"
#include "Parser.h"

extern int yyparse();

extern Program *root;

int main()
{
	freopen(SRC_PATH"/Input.mp","r",stdin);
	yyparse();
	cout << "Parsing is done...\n";
	root;
	cout << root->id;
	NodeVisitor *pv = new PrintVisitor();
	root->accept(pv);
	return 0;
}
