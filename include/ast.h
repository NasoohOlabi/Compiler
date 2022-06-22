#pragma once
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "hash_table.h"
#include "hash_fun.h"

#include <fstream>
using std::ios;
using std::ofstream;

static ofstream vout("..\\code.txt", ios::out);

class Node;
class Ident;
class Ident_List;
class Int_Num;
class Real_Num;
class Standard_Type;
class Type;
class Parameter;
class Declaration;
class Declarations;
class Local_Declaration;
class Local_Declarations;
class Expression;
class Int_Expression;
class Real_Expression;
class Boolean_Expression;
class Function_Expression;
class Ident_Expression;
class Expression_Expression;
class Not_Expression;
class Expression_List;
class Procedure_Statement;
class Optional_statements;
class Statement;
class Variable_Statement;
class Statement_List;
class If_Statement;
class While_Statement;
class If_Else_Statement;
class Compound_Statement;
class Variable;
class Parameter_List;
class Arguments;
class Subprogram_Head;
class Subprogram_Declaration;
class Subprogram_Declarations;
class Program;
class Add_expression;
class Minus_expression;
class Mul_expression;
class Divide_expression;
class Binary_expression;
class Logical_expression;
class Binary_opreator;
class Logical_opreator;

class NodeVisitor;
class PrintVisitor;
class TypeVisitor;
class CodeVisitor;
class Symbol;
class Scope;
class SymbolTable;

typedef CHashTable<Symbol> HashTab;

extern SymbolTable *symbolTable;

class Node
{
public:
	int line;
	int column;
	Node *father;
	Node(int, int);
	Symbol *symbol;
	virtual void accept(NodeVisitor *) = 0;
};

class Ident : public Node
{
public:
	string name;
	Ident(string n, int l, int c);
	void accept(NodeVisitor *) override;
};

class Ident_List : public Node
{
public:
	vector<Ident *> *idents;
	Ident_List(int, int);
	Ident_List(Ident *, int, int);
	void AddIdent(Ident *);
	void accept(NodeVisitor *) override;
};

class Int_Num : public Node
{
public:
	int value;
	Int_Num(int, int, int);
	void accept(NodeVisitor *) override;
};

class Real_Num : public Node
{
public:
	float value;
	Real_Num(float, int, int);
	void accept(NodeVisitor *) override;
};

class Standard_Type : public Node
{
public:
	char type;
	Standard_Type(char, int, int);
	void accept(NodeVisitor *) override;
};

class Type : public Node
{
public:
	bool is_array;
	int first;
	int last;
	Standard_Type *std_type;
	Type(Standard_Type *, int, int, int, int);
	Type(Standard_Type *, int, int);
	void accept(NodeVisitor *) override;
};

class Parameter : public Node
{
public:
	Ident_List *ident_list;
	Type *type;
	Parameter(Ident_List *, Type *, int, int);
	void accept(NodeVisitor *) override;
};

class Parameter_List : public Node
{
public:
	vector<Parameter *> *params;
	Parameter_List(int, int);
	Parameter_List(Parameter *, int, int);
	void AddParam(Parameter *);
	void accept(NodeVisitor *) override;
};

class Declaration : public Node
{
public:
	Parameter *param;
	Declaration(Parameter *, int, int);
	void accept(NodeVisitor *) override;
};

class Declarations : public Node
{
public:
	vector<Declaration *> *decs;
	Declarations(int, int);
	Declarations(Declaration *, int, int);
	void AddDec(Declaration *);
	void accept(NodeVisitor *) override;
};

class Local_Declaration : public Node
{
public:
	Parameter *param;
	Local_Declaration(Parameter *, int, int);
	void accept(NodeVisitor *) override;
};

class Local_Declarations : public Node
{
public:
	vector<Local_Declaration *> *decs;
	Local_Declarations(int, int);
	Local_Declarations(Local_Declaration *, int, int);
	void AddDec(Local_Declaration *);
	void accept(NodeVisitor *) override;
};

class Arguments : public Node
{
public:
	Parameter_List *param_lst;
	Arguments(int, int);
	Arguments(Parameter_List *, int, int);
	void accept(NodeVisitor *) override;
};
class Expression : public Node
{
public:
	string type;
	Expression(int, int);
	void accept(NodeVisitor *) override;
};

class Int_Expression : public Expression
{
public:
	Int_Num *value;
	Int_Expression(Int_Num *, int, int);
	void accept(NodeVisitor *) override;
};
class Real_Expression : public Expression
{
public:
	Real_Num *value;
	Real_Expression(Real_Num *, int, int);
	void accept(NodeVisitor *) override;
};
class Boolean_Expression : public Expression
{
public:
	bool value;
	Boolean_Expression(bool, int, int);
	void accept(NodeVisitor *) override;
};
class Function_Expression : public Expression
{
public:
	Ident *ident;
	Expression_List *expr_lst = NULL;
	Function_Expression(Ident *, Expression_List *, int, int);
	void accept(NodeVisitor *) override;
};

class Ident_Expression : public Expression
{
public:
	Ident *ident;
	Ident_Expression(Ident *, int, int);
	void accept(NodeVisitor *) override;
};
class Expression_Expression : public Expression
{
public:
	Expression *expression;
	Expression_Expression(Expression *, int, int);
	void accept(NodeVisitor *) override;
};
class Not_Expression : public Expression
{
public:
	Expression *expression;
	Not_Expression(Expression *, int, int);
	void accept(NodeVisitor *) override;
};

class Expression_List : public Node
{
public:
	vector<Expression *> *exprs;
	Expression_List(int, int);
	Expression_List(Expression *, int, int);
	void AddExpr(Expression *);
	void accept(NodeVisitor *) override;
};

class Statement : public Node
{
public:
	Statement(int, int);
	void accept(NodeVisitor *) override;
};

class Procedure_Statement : public Statement
{
public:
	Ident *id;
	Expression_List *expr_lst;
	Procedure_Statement(Ident *, int, int);
	Procedure_Statement(Ident *, Expression_List *, int, int);
	void accept(NodeVisitor *) override;
};

class Optional_Statements : public Statement
{
public:
	Statement_List *statement_list;
	// bool returnValue = false;
	Optional_Statements(Statement_List *, int, int);
	Optional_Statements(int, int);
	void accept(NodeVisitor *) override;
};

class Statement_List : public Node
{
public:
	vector<Statement *> *stmts;
	// bool returnValue = false;
	Statement_List(int, int);
	Statement_List(Statement *, int, int);
	void AddStatement(Statement *);
	void accept(NodeVisitor *) override;
};

class Variable_Statement : public Statement
{
public:
	Variable *variable;
	Expression *expression;
	// string type;
	Variable_Statement(Variable *, Expression *, int, int);
	void accept(NodeVisitor *) override;
};

class Compound_Statement : public Statement
{
public:
	Optional_Statements *optional_statements;
	Compound_Statement(Optional_Statements *, int, int);
	void accept(NodeVisitor *) override;
};

class If_Statement : public Statement
{
public:
	Expression *expression;
	Statement *statement;
	If_Statement(Expression *, Statement *, int, int);
	void accept(NodeVisitor *) override;
};
class If_Else_Statement : public Statement
{
public:
	Expression *expression;
	Statement *statement1;
	Statement *statement2;
	If_Else_Statement(Expression *, Statement *, Statement *, int, int);
	void accept(NodeVisitor *) override;
};

class While_Statement : public Statement
{
public:
	Expression *expression;
	Statement *statement;
	While_Statement(Expression *, Statement *, int, int);
	void accept(NodeVisitor *) override;
};

class Variable : public Node
{
public:
	Ident *id;
	Expression *expr{};
	Variable(Ident *, int, int);
	Variable(Ident *, Expression *, int, int);
	void accept(NodeVisitor *) override;
};

class Subprogram_Head : public Node
{
public:
	Arguments *args;
	Standard_Type *std_type;
	bool is_function;
	Subprogram_Head(Arguments *, int, int);
	Subprogram_Head(Arguments *, Standard_Type *, int, int);
	void accept(NodeVisitor *) override;
};

class Subprogram_Declaration : public Node
{
public:
	Local_Declarations *decs;
	Subprogram_Head *sub_head;
	Compound_Statement *comp_stmt;
	Subprogram_Declaration(Local_Declarations *, Subprogram_Head *, Compound_Statement *, int, int);
	void accept(NodeVisitor *) override;
};

class Subprogram_Declarations : public Node
{
public:
	vector<Subprogram_Declaration *> *decs;
	Subprogram_Declarations(int, int);
	Subprogram_Declarations(Subprogram_Declaration *, int, int);
	void AddDec(Subprogram_Declaration *);
	void accept(NodeVisitor *) override;
};

class Program : public Node
{
public:
	Ident *id;
	Declarations *decs;
	Subprogram_Declarations *sub_decs;
	Compound_Statement *comp_stmt;
	Program(Ident *, Declarations *, Subprogram_Declarations *, Compound_Statement *, int, int);
	void accept(NodeVisitor *) override;
};

class Add_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Add_expression(Expression *, Expression *, int, int);
	void accept(NodeVisitor *) override;
};

class Minus_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Minus_expression(Expression *, Expression *, int, int);
	void accept(NodeVisitor *) override;
};

class Mul_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Mul_expression(Expression *, Expression *, int, int);
	void accept(NodeVisitor *) override;
};

class Divide_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Divide_expression(Expression *, Expression *, int, int);
	void accept(NodeVisitor *) override;
};

class Binary_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Binary_opreator *op;
	Binary_expression(Expression *, Binary_opreator *, Expression *, int, int);
	void accept(NodeVisitor *) override;
};

class Logical_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Logical_opreator *op;
	Logical_expression(Expression *, Logical_opreator *, Expression *, int, int);
	void accept(NodeVisitor *) override;
};
class Binary_opreator : public Node
{
public:
	string op;
	Binary_opreator(string, int, int);
	void accept(NodeVisitor *) override;
};

class Logical_opreator : public Node
{
public:
	string op;
	Logical_opreator(string, int, int);
	void accept(NodeVisitor *) override;
};

class NodeVisitor
{
public:
	virtual void Visit(Node *) = 0;
	virtual void Visit(Ident *) = 0;
	virtual void Visit(Ident_List *) = 0;
	virtual void Visit(Int_Num *) = 0;
	virtual void Visit(Real_Num *) = 0;
	virtual void Visit(Standard_Type *) = 0;
	virtual void Visit(Type *) = 0;
	virtual void Visit(Parameter *) = 0;
	virtual void Visit(Declaration *) = 0;
	virtual void Visit(Declarations *) = 0;
	virtual void Visit(Local_Declaration *) = 0;
	virtual void Visit(Local_Declarations *) = 0;
	virtual void Visit(Expression *) = 0;
	virtual void Visit(Int_Expression *) = 0;
	virtual void Visit(Real_Expression *) = 0;
	virtual void Visit(Boolean_Expression *) = 0;
	virtual void Visit(Function_Expression *) = 0;
	virtual void Visit(Ident_Expression *) = 0;
	virtual void Visit(Expression_Expression *) = 0;
	virtual void Visit(Expression_List *) = 0;
	virtual void Visit(Binary_expression *) = 0;
	virtual void Visit(Logical_expression *) = 0;
	virtual void Visit(Not_Expression *) = 0;
	virtual void Visit(Statement *) = 0;
	virtual void Visit(Statement_List *) = 0;
	virtual void Visit(If_Statement *) = 0;
	virtual void Visit(While_Statement *) = 0;
	virtual void Visit(If_Else_Statement *) = 0;
	virtual void Visit(Compound_Statement *) = 0;
	virtual void Visit(Optional_Statements *) = 0;
	virtual void Visit(Variable_Statement *) = 0;
	virtual void Visit(Parameter_List *) = 0;
	virtual void Visit(Arguments *) = 0;
	virtual void Visit(Procedure_Statement *) = 0;
	virtual void Visit(Variable *) = 0;
	virtual void Visit(Subprogram_Head *) = 0;
	virtual void Visit(Subprogram_Declaration *) = 0;
	virtual void Visit(Subprogram_Declarations *) = 0;
	virtual void Visit(Program *) = 0;
	virtual void Visit(Add_expression *) = 0;
	virtual void Visit(Minus_expression *) = 0;
	virtual void Visit(Mul_expression *) = 0;
	virtual void Visit(Divide_expression *) = 0;
	virtual void Visit(Binary_opreator *) = 0;
	virtual void Visit(Logical_opreator *) = 0;
};

class PrintVisitor : public NodeVisitor
{
public:
	void Visit(Node *) override;
	void Visit(Ident *) override;
	void Visit(Ident_List *) override;
	void Visit(Int_Num *) override;
	void Visit(Real_Num *) override;
	void Visit(Standard_Type *) override;
	void Visit(Type *) override;
	void Visit(Parameter *) override;
	void Visit(Declaration *) override;
	void Visit(Declarations *) override;
	void Visit(Local_Declaration *) override;
	void Visit(Local_Declarations *) override;
	void Visit(Expression *) override;
	void Visit(Int_Expression *) override;
	void Visit(Real_Expression *) override;
	void Visit(Boolean_Expression *) override;
	void Visit(Function_Expression *) override;
	void Visit(Ident_Expression *) override;
	void Visit(Expression_Expression *) override;
	void Visit(Expression_List *) override;
	void Visit(Binary_expression *) override;
	void Visit(Logical_expression *) override;
	void Visit(Not_Expression *) override;
	void Visit(Statement *) override;
	void Visit(Statement_List *) override;
	void Visit(If_Statement *) override;
	void Visit(While_Statement *) override;
	void Visit(If_Else_Statement *) override;
	void Visit(Compound_Statement *) override;
	void Visit(Optional_Statements *) override;
	void Visit(Variable_Statement *) override;
	void Visit(Parameter_List *) override;
	void Visit(Arguments *) override;
	void Visit(Procedure_Statement *) override;
	void Visit(Variable *) override;
	void Visit(Subprogram_Head *) override;
	void Visit(Subprogram_Declaration *) override;
	void Visit(Subprogram_Declarations *) override;
	void Visit(Program *) override;
	void Visit(Add_expression *) override;
	void Visit(Minus_expression *) override;
	void Visit(Mul_expression *) override;
	void Visit(Divide_expression *) override;
	void Visit(Binary_opreator *) override;
	void Visit(Logical_opreator *) override;
};

class TypeVisitor : public NodeVisitor
{
public:
	virtual void Visit(Node *);
	virtual void Visit(Ident *);
	virtual void Visit(Ident_List *);
	virtual void Visit(Int_Num *);
	virtual void Visit(Real_Num *);
	virtual void Visit(Standard_Type *);
	virtual void Visit(Type *);
	virtual void Visit(Parameter *);
	virtual void Visit(Declaration *);
	virtual void Visit(Declarations *);
	virtual void Visit(Local_Declaration *);
	virtual void Visit(Local_Declarations *);
	virtual void Visit(Expression *);
	virtual void Visit(Int_Expression *);
	virtual void Visit(Real_Expression *);
	virtual void Visit(Boolean_Expression *);
	virtual void Visit(Function_Expression *);
	virtual void Visit(Ident_Expression *);
	virtual void Visit(Expression_Expression *);
	virtual void Visit(Expression_List *);
	virtual void Visit(Binary_expression *);
	virtual void Visit(Logical_expression *);
	virtual void Visit(Not_Expression *);
	virtual void Visit(Statement *);
	virtual void Visit(Statement_List *);
	virtual void Visit(If_Statement *);
	virtual void Visit(While_Statement *);
	virtual void Visit(If_Else_Statement *);
	virtual void Visit(Compound_Statement *);
	virtual void Visit(Optional_Statements *);
	virtual void Visit(Variable_Statement *);
	virtual void Visit(Parameter_List *);
	virtual void Visit(Arguments *);
	virtual void Visit(Procedure_Statement *);
	virtual void Visit(Variable *);
	virtual void Visit(Subprogram_Head *);
	virtual void Visit(Subprogram_Declaration *);
	virtual void Visit(Subprogram_Declarations *);
	virtual void Visit(Program *);
	virtual void Visit(Add_expression *);
	virtual void Visit(Minus_expression *);
	virtual void Visit(Mul_expression *);
	virtual void Visit(Divide_expression *);
	virtual void Visit(Binary_opreator *);
	virtual void Visit(Logical_opreator *);
};

class CodeVisitor : public NodeVisitor
{
public:
	int fp = -1, ifCount = 0;
	virtual void Visit(Node *);
	virtual void Visit(Ident *);
	virtual void Visit(Ident_List *);
	virtual void Visit(Int_Num *);
	virtual void Visit(Real_Num *);
	virtual void Visit(Standard_Type *);
	virtual void Visit(Type *);
	virtual void Visit(Parameter *);
	virtual void Visit(Declaration *);
	virtual void Visit(Declarations *);
	virtual void Visit(Local_Declaration *);
	virtual void Visit(Local_Declarations *);
	virtual void Visit(Expression *);
	virtual void Visit(Int_Expression *);
	virtual void Visit(Real_Expression *);
	virtual void Visit(Boolean_Expression *);
	virtual void Visit(Function_Expression *);
	virtual void Visit(Ident_Expression *);
	virtual void Visit(Expression_Expression *);
	virtual void Visit(Expression_List *);
	virtual void Visit(Binary_expression *);
	virtual void Visit(Logical_expression *);
	virtual void Visit(Not_Expression *);
	virtual void Visit(Statement *);
	virtual void Visit(Statement_List *);
	virtual void Visit(If_Statement *);
	virtual void Visit(While_Statement *);
	virtual void Visit(If_Else_Statement *);
	virtual void Visit(Compound_Statement *);
	virtual void Visit(Optional_Statements *);
	virtual void Visit(Variable_Statement *);
	virtual void Visit(Parameter_List *);
	virtual void Visit(Arguments *);
	virtual void Visit(Procedure_Statement *);
	virtual void Visit(Variable *);
	virtual void Visit(Subprogram_Head *);
	virtual void Visit(Subprogram_Declaration *);
	virtual void Visit(Subprogram_Declarations *);
	virtual void Visit(Program *);
	virtual void Visit(Add_expression *);
	virtual void Visit(Minus_expression *);
	virtual void Visit(Mul_expression *);
	virtual void Visit(Divide_expression *);
	virtual void Visit(Binary_opreator *);
	virtual void Visit(Logical_opreator *);
};

class Symbol
{
public:
	string name;
	int kind;
	char type;
	int location;
	Symbol(string, int, char);
};
class Scope
{
public:
	HashTab *hashTab;
	Scope();
};

class SymbolTable
{
public:
	vector<Scope *> *scopes;
	Scope *current;
	bool AddSymbol(Ident *, int, char);
	bool AddFunction(Ident *, Arguments *, int, char);
	bool AddProcedure(Ident *, Arguments *, int, char);
	SymbolTable();
	Symbol *lookUpSymbol(Ident *);
	Symbol *lookUpFunction(Ident *, Expression_List *, int);
	void startScope();
	void endScope();
};