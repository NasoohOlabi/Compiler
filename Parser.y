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
		Program *tProgram;
		Var *tVar;
		Integer *tInteger;
		Real *tReal;
		Function *tFunction;
		Procedure *tProcedure;
		While *tWhile;
		Do *tDo;
		KBegin *tBegin;
		End *tEnd;
		If *tIf;
		Then *tThen;
		Else *tElse;
		Array *tArray;
		Of *tOf;
		Div *tDiv;
		Not *tNot;
		Or *tOr;
		And *tAnd;
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

/* New Nodes */


%token <tProgram> PROGRAM
%token <tVar> VAR
%token <tInteger> INTEGER
%token <tReal> REAL
%token <tFunction> FUNCTION
%token <tProcedure> PROCEDURE
%token <tWhile> WHILE
%token <tDo> DO
%token <tBegin> KBEGIN
%token <tEnd> END
%token <tIf> IF
%token <tThen> THEN
%token <tElse> ELSE
%token <tArray> ARRAY
%token <tOf> OF
%token <tDiv> DIV
%token <tNot> NOT
%token <tOr> OR
%token <tAnd> AND



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
int yyerror(const char* s) /*uyuy*/
{
	cout << "OOPs, synatx error" << endl;

	return 1;
}
