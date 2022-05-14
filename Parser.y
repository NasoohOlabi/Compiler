%{
	#include "ast.h"
	
	#include <iostream>
	using std::cout;
	using std::endl;	
	
	extern int yylex();
	extern int yyerror(const char *);

	int lin = 0, col =0;

%}


%token NUM


%%


x: NUM
{
	cout << "NUMBER";
}
;


%%


int yyerror(const char* s)
{
	cout << "OOPs, synatx error" << endl;
	return 1;
}
