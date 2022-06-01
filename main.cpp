#include "ast.h"
#include "Parser.h"

extern int yyparse();

extern Program *root;

int main()
{
	yyparse();
	cout << "Parsing is done...\n";
	root;
	NodeVisistor *pv = new PrintVisistor();
	root->accept(pv);
	return 0;
}
