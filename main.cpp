#include "ast.h"
#include "Parser.h"

extern int yyparse();

int main()
{
	yyparse();
	return 0;
}
