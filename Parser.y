%{
	#include "ast.h"
	#include <iostream>
	using std::cout;
	using std::endl;	
	extern int yylex();
	extern int yyerror(const char *);
	int lin = 0, col =0;

	Program *root;
	SymbolTable *symbolTable = new SymbolTable();
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
	Expression *tExpression;
	Int_Expression *tInt_Expression;
	Real_Expression *tReal_Expression;
	Boolean_Expression *tBoolean_Expression;
	Ident_Expression *tIdent_Expression;
	Expression_Expression *tExpression_Expression;
	Not_Expression *tNot_Expression;
	Expression_List *tExpression_List;
	Procedure_Statement *tProcedure_Statement;
	Statement *tStatement;
	Statement_List *tStatement_List;
	Optional_Statements *tOptional_Statements;
	Compound_Statement *tCompound_Statement;
	Variable *tVariable;
	Subprogram_Head *tSubprogram_Head;
	Subprogram_Declaration *tSubprogram_Declaration;
	Subprogram_Declarations *tSubprogram_Declarations;
	Program *tProgram;
	Add_expression *tAdd_expression;
	Minus_expression *tMinus_expression;
	Mul_expression *tMul_expression;
	Divide_expression *tDivide_expression;
	Binary_expression *tBinary_expression;
	Binary_opreator *tBinary_Opreator;
 }

/* Tokens Section (Terminals) */

%token PROGRAM INTEGER REAL BOOLEAN DD ASSIGN
%token WHILE DO BEG END IF THEN ARRAY OF TRUE FALSE
%token <tIdent> IDENT
%token <tInt_Num> INT_NUM
%token <tReal_Num> REAL_NUM


/* Precedences & Priorities Section */



%left '+' '-'
%left '*' '/'

%nonassoc <tBinary_Opreator> BINARY_OPERATOR

%nonassoc EXPRLST_PREC

%nonassoc ELSE
%nonassoc IF_PREC

%nonassoc NOSUBDECS_PREC
%nonassoc FUNCTION
%nonassoc PROCEDURE
%nonassoc SUBPROGRAMDEC_PREC
%nonassoc SUBDECS_PREC


%nonassoc NODECS_PREC
%nonassoc VAR

%nonassoc UNARY_PREC
%nonassoc NOT

%nonassoc EXPR_PREC
%nonassoc ','



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
%type <tNot_Expression> not_expression
*/

%type <tExpression_List> expression_list
%type <tProcedure_Statement> procedure_statement
%type <tVariable> variable
%type <tStatement> statement
%type <tStatement_List> statement_list
%type <tOptional_Statements> optional_statements
%type <tCompound_Statement> compound_statement
%type <tSubprogram_Head> subprogram_head
%type <tSubprogram_Declaration> subprogram_declaration
%type <tSubprogram_Declarations> subprogram_declarations
%type <tProgram> program
%type <tAdd_expression> add_expression
%type <tMinus_expression> minus_expression
%type <tMul_expression> mul_expression
%type <tDivide_expression> divide_expression
%type <tBinary_expression> binary_expression


%%

program: PROGRAM IDENT ';' declarations subprogram_declarations compound_statement 
	{
		cout << "main program\n";
		$$ = new Program($2, $4, $5, $6, lin, col);
		root = $$;
	}


subprogram_declarations: subprogram_declarations subprogram_declaration ';' %prec SUBDECS_PREC
								{
									$1->AddDec($2);
									$$ = $1;
									cout << "sub dec added to sub declarations\n";
								}
							| /* Empty */ %prec NOSUBDECS_PREC
								{
									cout << "no sub declerations\n";
									$$ = new Subprogram_Declarations(lin, col);
								}
;


subprogram_declaration: subprogram_head compound_statement %prec SUBPROGRAMDEC_PREC
							{
								cout << "subprogram dec\n";
								$$ = new Subprogram_Declaration($1, $2, lin, col);
							}
;

subprogram_head: FUNCTION IDENT arguments ':' standard_type ';'
					{
						cout << "subprogram_head function\n";
						$$ = new Subprogram_Head($3, $5, lin, col);
					}
				| PROCEDURE IDENT arguments ';'
					{
						cout << "subprogram_head procedure\n";
						$$ = new Subprogram_Head($3, lin, col);
					}
;

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


expression_list: expression %prec EXPRLST_PREC
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
			| add_expression
								{
									$$ = $1;
								}
			| minus_expression
								{
									$$ = $1;
								}			
			| mul_expression
								{
									$$ = $1;
								}			
			|divide_expression
								{
									$$ = $1;
								}								
			| binary_expression %prec UNARY_PREC
								{
									$$ = $1;
								}
			| IDENT expression_list %prec EXPR_PREC
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
			| /* Empty */  %prec NODECS_PREC
				{
					cout << "no declerations\n";
					$$ = new Declarations(lin, col);
				}
;

declaration: VAR parameter ';'	
										{
											cout << "declaration\n";
											$$ = new Declaration($2, lin, col);

											char t = $2->type->std_type->type;
											cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& "<<t<<"\n";
											int n = $2->ident_list->idents->size();
											for(int i=0;i<n;i++){
												symbolTable->AddSymbol($2->ident_list->idents->at(i),1,t);
											}
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

add_expression: expression '+' expression 
					{
						cout<<"Add Expression found";
						$$ = new Add_expression($1, $3, lin, col);
					}
;

minus_expression: expression '-' expression 
				{
						cout<<"Minus Expression found";
						$$ = new Minus_expression($1, $3, lin, col);
				}
;

mul_expression: expression '*' expression 
				{
						cout<<"Mult Expression found";
						$$ = new Mul_expression($1, $3, lin, col);
				}
;

divide_expression: expression '/' expression 
				{
						cout<<"Divide Expression found";
						$$ = new Divide_expression($1, $3, lin, col);
				}
;

binary_expression: expression BINARY_OPERATOR expression 
				{
						cout<< "Binary Expression found";
						$$ = new Binary_expression($1, $2, $3, lin, col);
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
						$$= new Optional_Statements($1, lin, col);
					}
					| /* Empty */
					{
						$$= new Optional_Statements(lin, col);
					}
;

compound_statement: BEG optional_statements END
					{
						$$= new Compound_Statement($2, lin, col);
					}
;


%%

int yyerror(const char* s)
{
	cout << "OOPs, synatx error" << endl;
	return 1;
}
