%{
	#include "ast.h"
	
	#include <iostream>
	using std::cout;
	using std::endl;	
	
	extern int yylex();
	extern int yyerror(const char *);

	int lin = 0, col =0;

%}

/* Union Definition Section */

%union{
	Ident *tIdent;
	Ident_List *tIdent_List;
	Int_Num *tInt_Num;
	Real_Num *tReal_Num;
}

/* Tokens Section (Terminals) */

%token PROGRAM VAR INTEGER REAL BOOLEAN FUNCTION PROCEDURE

%token WHILE DO BEG END IF THEN ELSE ARRAY OF DIV NOT OR AND

%token <tIdent> IDENT
%token <tInt_Num> INT_NUM
%token <tReal_Num> REAL_NUM


/* Types Section (Non-Terminals) */

%type <tIdent_List> ident_list

%%

standard_type: INTEGER  //Maybe turn to node?
			| REAL
			| BOOLEAN
			{
				cout << "TYPE KEYWORD\n" ;
			}
;

ident_list: IDENT
		{
			$$ = new Ident_List($1, lin, col);
			cout << "SINGLE IDENT: " << $1;
		}
			| ident_list ',' IDENT
		{
			$1->AddIdent($3);
			cout << "MULTIPLE IDENTS: Added" << $3;
			$$ = $1;
		}
;


%%


int yyerror(const char* s)
{
	cout << "OOPs, synatx error" << endl;
	return 1;
}
