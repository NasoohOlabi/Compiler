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
	Unary_Operator *tUnary_Operator;
	Standard_Type *tStandard_Type;
	Type *tType;
	Parameter *tParameter;
	Parameter_List *tParameter_List;
	Declaration *tDeclaration;
	Declarations *tDeclarations;
	Arguments *tArguments;
	Expression *tExpression;
	Int_Expression *tInt_Expression;
	Real_Expression *tReal_Expression;
	Boolean_Expression *tBoolean_Expression;
	Ident_Expression *tIdent_Expression;
	Expression_Expression *tExpression_Expression;
	Unary_Expression *tUnary_Expression;
	Not_Expression *tNot_Expression;
	Expression_List *tExpression_List;
	Procedure_Statement *tProcedure_Statement;
	Statement *tStatement;
	Statement_List *tStatement_List;
	Optional_Statements *tOptional_Statements;
	Compound_Statement *tCompound_Statement;
	Variable *tVariable;
}

/* Tokens Section (Terminals) */

%token PROGRAM VAR INTEGER REAL BOOLEAN FUNCTION PROCEDURE DD ASSIGN

%token WHILE DO BEG END IF THEN ELSE ARRAY OF TRUE FALSE NOT

%token <tIdent> IDENT
%token <tInt_Num> INT_NUM
%token <tReal_Num> REAL_NUM
%token <tUnary_Operator> UNARY_OPERATOR

/*--*/

%nonassoc IF_PREC
%nonassoc ELSE

/* Types Section (Non-Terminals) */

%type <tIdent_List> ident_list
%type <tStandard_Type> standard_type
%type <tType> type
%type <tParameter> parameter
%type <tParameter_List> parameter_list
%type <tDeclaration> declaration
%type <tDeclarations> declarations
%type <tArguments> arguments
%type <tExpression> expression
/*
%type <tInt_Expression> int_expression
%type <tReal_Expression> real_expression
%type <tBoolean_Expression> boolean_expression
%type <tIdent_Expression> ident_expression
%type <tExpression_Expression> expression_expression
%type <tUnary_Expression> unary_expression
%type <tNot_Expression> not_expression
*/
%type <tExpression_List> expression_list
%type <tProcedure_Statement> procedure_statement
%type <tVariable> variable
%type <tStatement> statement
%type <tStatement_List> statement_list
%type <tOptional_Statements> optional_statements
%type <tCompound_Statement> compound_statement

%%

variable: IDENT
				{
					cout << "variable\n";
					$$ = new Variable($1, lin, col);
				}
			| IDENT '[' expression ']'
				{
					cout << "variable with expr\n";
					$$ = new Variable($1, $3, lin, col);
				}
;


procedure_statement: IDENT
							{
								cout << "procedure stmt\n";
								$$ = new Procedure_Statement($1, lin, col);
							}
					| IDENT '(' expression_list ')'
							{
								cout << "procedure stmt with list\n";
								$$ = new Procedure_Statement($1, $3, lin, col);
							}
;


expression_list: expression
						{
							$$ = new Expression_List($1 ,lin, col);
							cout << "single expression\n";
						}
						| expression_list ',' expression
						{
							cout << "multiple expressions\n";
							$1->AddExpr($3);
							$$ = $1;
						}
;

expression: INT_NUM
								{
									$$ = new Int_Expression($1, lin, col);
									cout << "Int Expression\n";
								}			
			| REAL_NUM
								{
									$$ = new Real_Expression($1, lin, col);
									cout << "Real Expression\n";
								}
			| TRUE
								{
									$$ = new Boolean_Expression(true, lin, col);
									cout << "Boolean true Expression\n";
								}
			| FALSE
								{
									$$ = new Boolean_Expression(false, lin, col);
									cout << "Boolean false Expression\n";
								}
			| NOT expression
								{
									$$ = new Not_Expression($2 ,lin, col);
									cout << "Not Expression\n";
								}
			| expression UNARY_OPERATOR expression
								{
									$$ = new Unary_Expression($1, $2, $3, lin, col);
									cout << "Unary Expression\n";
								}
			| IDENT expression_list
								{
									$$ = new Ident_Expression($1, $2 ,lin, col);
									cout << "Ident List Expression\n";
								}
			| IDENT 
								{
									$$ = new Ident_Expression($1, lin, col);
									cout << "Ident Expression" << $1->name << "\n";
								}
			| '(' expression ')'
								{
									$$ = new Expression_Expression($2 ,lin, col);
									cout << "Expression Expression\n";
								}
;

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

/* 
subprogram_head: FUNCTION IDENT arguments ':' standard_type ';'
				 | PROCEDURE IDENT arguments ';' */

statement : variable ASSIGN expression
									{
										cout << "Assign stmts\n";
										$$= new Variable_Statement($1, $3, lin, col);
									}
			| procedure_statement
									{
										/* $$ = $1; */
									}
			| compound_statement
									{
										$$= new Compound_Statement($1->optional_statements, lin, col);
									}
			| IF expression THEN statement %prec IF_PREC 
									{
										cout << "If stmt\n";
										$$= new If_Statement($2, $4, lin, col);
									}
			| IF expression THEN statement ELSE statement
									{
										cout << "If else stmts\n";
										$$= new If_Else_Statement($2, $4, $6, lin, col);
									}
			| WHILE expression DO statement
									{
										cout << "While stmts\n";
										$$= new While_Statement($2, $4, lin, col);
									}
;
statement_list : statement 
					{
						$$= new Statement_List($1, lin, col);
					}
				 | statement_list ';' statement
				 	{
						$1->AddStatement($3); 
						$$ = $1;
					}
;
optional_statements: statement_list
					{
						$$= new Optional_statements($1, lin, col);
					}
					| /* Empty */
					{
						$$= new Optional_statements(lin, col);
					}
;
compound_statement: BEG optional_statements END
					{
						$$= new Compound_statement($2, lin, col);
					}
;
/* 
subprogram_declaration: subprogram_head compound_statement */
/* 
subprogram_declarations : subprogram_declarations subprogram_declaration ';'
						  | Empty */


%%


int yyerror(const char* s)
{
	cout << "OOPs, synatx error" << endl;
	return 1;
}
