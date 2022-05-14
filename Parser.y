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
	Standard_Type *tStandard_Type;
	Type *tType;
}

/* Tokens Section (Terminals) */

%token PROGRAM VAR INTEGER REAL BOOLEAN FUNCTION PROCEDURE DD //DD is .. (Double Dots)

%token WHILE DO BEG END IF THEN ELSE ARRAY OF DIV NOT OR AND

%token <tIdent> IDENT
%token <tInt_Num> INT_NUM
%token <tReal_Num> REAL_NUM


/* Types Section (Non-Terminals) */

%type <tIdent_List> ident_list
%type <tStandard_Type> standard_type
%type <tType> type


%%

type: standard_type 
					{
						cout << "Type found :: " << $1->type ;
						$$ = new Type($1, lin, col);
					}
				| ARRAY '[' INT_NUM DD INT_NUM ']' OF standard_type
					{
						$$ = new Type($8, $3->value, $5->value, lin, col);
						cout << "Type array found";
					}			
;

standard_type: INTEGER 
					{
						$$ = new Standard_Type('I', lin, col);
						cout << "INTEGER KEYWORD\n" ;
					}
				| REAL
					{
						$$ = new Standard_Type('R', lin, col);
						cout << "REAL KEYWORD\n" ;
					}			
				| BOOLEAN
					{
						$$ = new Standard_Type('B', lin, col);
						cout << "BOOLEAN KEYWORD\n" ;
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
