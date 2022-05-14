%{
	#include "ast.h"
	
	#include <iostream>
	using std::cout;
	using std::endl;	
	
	extern int yylex();
	extern int yyerror(const char *);

	int lin = 0, col =0;

%}

%token PROGRAM VAR INTEGER REAL FUNCTION PROCEDURE WHILE

%token  DO BEG END IF THEN ELSE ARRAY OF DIV NOT OR AND

%token INT_NUM REAL_NUM


%%

y: REAL_NUM
{
	cout << "REAL NUMBER\n";
}
;

x: INT_NUM
{
	cout << "INT NUMBER\n";
}
;



%%


int yyerror(const char* s)
{
	cout << "OOPs, synatx error" << endl;
	return 1;
}
