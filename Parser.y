%{
	#include "ast.h"
	
	#include <iostream>
	using std::cout;
	using std::endl;	
	
	extern int yylex();
	extern int yyerror(const char *);
		
	Func *root;
	int lin = 0, col =0;

%}

%union
{
		Func *tFunc;
		Args *tArgs;
		Arg *tArg;
		int tInt;
		Expr *tExpr;
		Stmts *tStmts;
		Stmt *tStmt;
		Num *tNum;
		Ident *tIdent;
}

%type <tFunc> func
%type <tArg> arg
%type <tArgs> args args_e
%type <tInt> type
%type <tExpr> expr
%type <tStmt> stmt
%type <tStmts> stmts




%token <tIdent> IDENT
%token <tNum> NUM

%token INT



%left  '='
%left '+'



%%
func: type IDENT '(' args_e ')' '{' stmts '}' 
		{ 
			$$ = new Func($1, $2, $4, $7, lin, col);
			root = $$;
			cout << "Parsing is done Correctly!!!" << endl;
		}
										
;
arg : type IDENT
		{
			$$ = new Arg($1, $2, lin, col);
		}
;
args:	arg 
			{
				$$ = new Args($1, lin, col);
			}
		| args ',' arg
			{
				$$ = $1;
				$$->AddArg($3);
			}
;
args_e:		/* empty */
			{
				$$ = new Args(lin, col);
			}
		| args
		 {
			$$ = $1;
		 }
			

;
type: INT
		{
			// the type in integer
			$$ = 1;
		}

;
expr:		NUM
				{
					$$ = new NumExpr($1, lin, col);
				}
		| IDENT
			{
				$$ = new IdExpr($1, lin, col);
			}
		| IDENT '=' expr
		{
				$$ = new Assign($1, $3,  lin, col);
		}
		| expr '+' expr
		{
				$$ = new Add($1, $3, lin, col);
		}
;
stmt:		expr ';'
			{
				$$ = new ExprStmt($1, lin, col);
			}
;
stmts: /* Empty */
			{
				$$ = new Stmts(lin, col);
			}
		|stmts stmt
			{
				$1->AddStmt($2);
				$$ = $1;
			} 
;

%%
int yyerror(const char* s)
{
	cout << "OOPs, synatx error" << endl;

	return 1;
}
