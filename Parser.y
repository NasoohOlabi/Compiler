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
	Parameter *tParameter;
	Parameter_List *tParameter_List;
	Declaration *tDeclaration;
	Declarations *tDeclarations;
	Arguments *tArguments;
}

/* Tokens Section (Terminals) */

%token PROGRAM VAR INTEGER REAL BOOLEAN FUNCTION PROCEDURE DD //DD is .. (Double Dots)

%token WHILE DO BEG END IF THEN ELSE ARRAY OF UNARY_OPERATOR

%token <tIdent> IDENT
%token <tInt_Num> INT_NUM
%token <tReal_Num> REAL_NUM


/* Types Section (Non-Terminals) */

%type <tIdent_List> ident_list
%type <tStandard_Type> standard_type
%type <tType> type
%type <tParameter> parameter
%type <tParameter_List> parameter_list
%type <tDeclaration> declaration
%type <tDeclarations> declarations
%type <tArguments> arguments


%%





arguments: '(' parameter_list ')'
						{
							$$ = new Arguments($2 ,lin, col);
							cout << "arguments\n";
						}
			| /* Empty */
				{
					cout << "no arguments\n";
				}
;


declarations: declaration 
						{
							$$ = new Declarations($1 ,lin, col);
							cout << "single declaration\n";
						}
			| declarations declaration
				{
					$1->AddDec($2);
					$$ = $1;
					cout << "dec added to declarations\n";
				}
			| /* Empty */
				{
					cout << "no declerations\n";
				}
;

declaration: VAR parameter ';'	
										{
											cout << "declaration\n";
											$$ = new Declaration($2, lin, col);
										}
;

parameter_list: parameter
						{
							$$ = new Parameter_List($1 ,lin, col);
							cout << "single parameter\n";
						}
						| parameter_list ';' parameter
						{
							cout << "multiple parameterss\n";
							$1->AddParam($3);
							$$ = $1;
						}
;

parameter: ident_list ':' type	{
									cout << "Parameter\n";
									$$ = new Parameter($1, $3, lin, col);
								}
;

type: standard_type 
					{
						cout << "Type found :: " << $1->type << "\n";
						$$ = new Type($1, lin, col);
					}
				| ARRAY '[' INT_NUM DD INT_NUM ']' OF standard_type
					{
						cout << "Type array found";
						$$ = new Type($8, $3->value, $5->value, lin, col);
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
			cout << "SINGLE IDENT: " << $1->name << "\n";
			$$ = new Ident_List($1, lin, col);
		}
			| ident_list ',' IDENT
		{
			cout << "MULTIPLE IDENTS: Added\n";
			$1->AddIdent($3);
			$$ = $1;
		}
;


%%


int yyerror(const char* s)
{
	cout << "OOPs, synatx error" << endl;
	return 1;
}
