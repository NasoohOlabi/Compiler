
%{

	#include <iostream>
	using std::cout;
	using std::endl;
	extern int yylex();
	extern int yyerror(const char *);

%}

%token NUMBER
%token IDENT
%token IF
%token PROCEDURE
%token PROGRAM
%token VAR
%token INTEGER
%token REAL
%token TRUE
%token FALSE
%token LE
%token SE
%token EQ
%token NQ
%token NE
%token BOOLEAN
%token RETURN
%token DECREMENT
%token INCREMENT
%token NUL
%token FOR
%token WHILE
%token DOUBLE
%token FUNCTION
%token DO
%token BEG
%token END
%token ARRAY
%token DIV
%token OF
%token OR
%token AND
%token NOT
%token INTEGER_LITERAL
%token REAL_LITERAL


%nonassoc ELSE
%nonassoc IFPREC

%left '-'
%left '*' 
%left MINUS

%%

stmts: stmt 
		| stmts stmt 
		;

stmt: IDENT '=' expr ';' 
		| IF '(' expr ')' stmt %prec IFPREC 
		| IF '(' expr ')' stmts ELSE stmts
		;

expr: NUMBER 
		| IDENT 
		| expr '-' expr 
		| expr '*' expr 
		| '-' expr %prec MINUS
		;


%%

int yyerror(const char * s){

	cout << "Syntax Error.... " << endl;
	return 1;

}

int main(){
	yyparse();
	return 0;
}