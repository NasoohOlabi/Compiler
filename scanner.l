%{
	#include "ast.h"
	#include "parser.h"

	extern int lin, col;
%}


/* Options */

%option noyywrap
%option caseless


/* Definitions */


Digit 		[0-9]
Alpha 		[a-z]
Id      	[{Alpha}_][{Alpha}{Digit}_]*
Int_Num 	0|([1-9]{Digit}*)
Real_Num	(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))?|"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?|(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))

%%

\n 					{
						col = 1;
						lin++;
					}

Id 					{
						cout << "Id:\n" << yytext;
					}	

Int_Num 					{
						cout << "Int_Num:\n" << yytext;
}

Real_Num 					{
						cout << "Real_Num:\n" << yytext;
}

"int"      return INT;

[0-9]+				{
						yylval.tNum = new Num(atoi(yytext), lin, col);
						return NUM;
					}
[a-z][a-z0-9]*       {						
						// yylval.tIdent = new Ident(strdup(yytext), lin, col);
						return IDENT;
					}
[(){},\-+;=]		return *yytext;
[ \n\t]       /* IGNORE */
%%

