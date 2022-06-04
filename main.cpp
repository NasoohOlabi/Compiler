#include "ast.h"
#include "Parser.h"

extern int yyparse();

extern Program *root;

int main()
{
	yyparse();
	cout << "Parsing is done...\n";
	root;
	NodeVisitor *pv = new PrintVisitor();
	root->accept(pv);
	return 0;
}
