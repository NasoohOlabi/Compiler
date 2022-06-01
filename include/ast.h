#pragma once
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

// #include "hash_table.h"
// #include "hash_fun.h"

class Node;
class Ident;
class Ident_List;
class Int_Num;
class Real_Num;
class Unary_Operator;
class Standard_Type;
class Type;
class Parameter;
class Declaration;
class Declarations;
class Expression;
class Int_Expression;
class Real_Expression;
class Boolean_Expression;
class Ident_Expression;
class Expression_Expression;
class Unary_Expression;
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

class NodeVisistor;
class PrintVisistor;
// class TypeVisitor;
// class CodeVisitor;

// typedef CHashTable <Symbol> HashTab;

class Node
{
public:
	int line;
	int column;
	Node *father;
	Node(int, int);
	virtual void accept(NodeVisistor *);
};

class Ident : public Node
{
public:
	string name;
	Ident(string n, int l, int c);
	virtual void accept(NodeVisistor *);
};

class Ident_List : public Node
{
public:
	vector<Ident *> *idents;
	Ident_List(int, int);
	Ident_List(Ident *, int, int);
	void AddIdent(Ident *);
	virtual void accept(NodeVisistor *);
};

class Int_Num : public Node
{
public:
	int value;
	Int_Num(int, int, int);
	virtual void accept(NodeVisistor *);
};

class Real_Num : public Node
{
public:
	float value;
	Real_Num(float, int, int);
	virtual void accept(NodeVisistor *);
};

class Unary_Operator : public Node
{
public:
	string op;
	Unary_Operator(string, int, int);
	virtual void accept(NodeVisistor *);
};

class Standard_Type : public Node
{
public:
	char type;
	Standard_Type(char, int, int);
	virtual void accept(NodeVisistor *);
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
	virtual void accept(NodeVisistor *);
};

class Parameter : public Node
{
public:
	Ident_List *ident_list;
	Type *type;
	Parameter(Ident_List *, Type *, int, int);
	virtual void accept(NodeVisistor *);
};

class Parameter_List : public Node
{
public:
	vector<Parameter *> *params;
	Parameter_List(int, int);
	Parameter_List(Parameter *, int, int);
	void AddParam(Parameter *);
	virtual void accept(NodeVisistor *);
};

class Declaration : public Node
{
public:
	Parameter *param;
	Declaration(Parameter *, int, int);
	virtual void accept(NodeVisistor *);
};

class Declarations : public Node
{
public:
	vector<Declaration *> *decs;
	Declarations(int, int);
	Declarations(Declaration *, int, int);
	void AddDec(Declaration *);
	virtual void accept(NodeVisistor *);
};

class Arguments : public Node
{
public:
	Parameter_List *param_lst;
	Arguments(Parameter_List *, int, int);
	virtual void accept(NodeVisistor *);
};
class Expression : public Node
{
public:
	Expression(int, int);
	virtual void accept(NodeVisistor *);
};

class Int_Expression : public Expression
{
public:
	Int_Num *value;
	Int_Expression(Int_Num *, int, int);
	virtual void accept(NodeVisistor *);
};
class Real_Expression : public Expression
{
public:
	Real_Num *value;
	Real_Expression(Real_Num *, int, int);
	virtual void accept(NodeVisistor *);
};
class Boolean_Expression : public Expression
{
public:
	bool value;
	Boolean_Expression(bool, int, int);
	virtual void accept(NodeVisistor *);
};
class Ident_Expression : public Expression
{
public:
	Ident *ident;
	Expression_List *expr_lst;
	Ident_Expression(Ident *, Expression_List *, int, int);
	Ident_Expression(Ident *, int, int);
	virtual void accept(NodeVisistor *);
};
class Expression_Expression : public Expression
{
public:
	Expression *expression;
	Expression_Expression(Expression *, int, int);
	virtual void accept(NodeVisistor *);
};
class Unary_Expression : public Expression
{
public:
	Expression *left_exp;
	Unary_Operator *op;
	Expression *right_exp;
	Unary_Expression(Expression *, Unary_Operator *, Expression *, int, int);
	virtual void accept(NodeVisistor *);
};
class Not_Expression : public Expression
{
public:
	Expression *expression;
	Not_Expression(Expression *, int, int);
	virtual void accept(NodeVisistor *);
};

class Expression_List : public Node
{
public:
	vector<Expression *> *exprs;
	Expression_List(int, int);
	Expression_List(Expression *, int, int);
	void AddExpr(Expression *);
	virtual void accept(NodeVisistor *);
};

class Statement : public Node
{
public:
	Statement(int, int);
	virtual void accept(NodeVisistor *);
};

class Procedure_Statement : public Statement
{
public:
	Ident *id;
	Expression_List *expr_lst;
	Procedure_Statement(Ident *, int, int);
	Procedure_Statement(Ident *, Expression_List *, int, int);
	virtual void accept(NodeVisistor *);
};

class Optional_Statements : public Statement
{
public:
	Statement_List *statement_list;
	// bool returnValue = false;
	Optional_Statements(Statement_List *, int, int);
	Optional_Statements(int, int);
	virtual void accept(NodeVisistor *);
};

class Statement_List : public Node
{
public:
	vector<Statement *> *stmts;
	// bool returnValue = false;
	Statement_List(int, int);
	Statement_List(Statement *, int, int);
	void AddStatement(Statement *);
	virtual void accept(NodeVisistor *);
};

class Variable_Statement : public Statement
{
public:
	Variable *variable;
	Expression *expression;
	// string type;
	Variable_Statement(Variable *, Expression *, int, int);
	virtual void accept(NodeVisistor *);
};

class Compound_Statement : public Statement
{
public:
	Optional_Statements *optional_statements;
	Compound_Statement(Optional_Statements *, int, int);
	virtual void accept(NodeVisistor *);
};

class If_Statement : public Statement
{
public:
	Expression *expression;
	Statement *statement;
	If_Statement(Expression *, Statement *, int, int);
	virtual void accept(NodeVisistor *);
};
class If_Else_Statement : public Statement
{
public:
	Expression *expression;
	Statement *statement1;
	Statement *statement2;
	If_Else_Statement(Expression *, Statement *, Statement *, int, int);
	virtual void accept(NodeVisistor *);
};

class While_Statement : public Statement
{
public:
	Expression *expression;
	Statement *statement;
	While_Statement(Expression *, Statement *, int, int);
	virtual void accept(NodeVisistor *);
};

class Variable : public Node
{
public:
	Ident *id;
	Expression *expr;
	Variable(Ident *, int, int);
	Variable(Ident *, Expression *, int, int);
	virtual void accept(NodeVisistor *);
};

class Subprogram_Head : public Node
{
public:
	Arguments *args;
	Standard_Type *std_type;
	bool is_function;
	Subprogram_Head(Arguments *, int, int);
	Subprogram_Head(Arguments *, Standard_Type *, int, int);
	virtual void accept(NodeVisistor *);
};

class Subprogram_Declaration : public Node
{
public:
	Subprogram_Head *sub_head;
	Compound_Statement *comp_stmt;
	Subprogram_Declaration(Subprogram_Head *, Compound_Statement *, int, int);
	virtual void accept(NodeVisistor *);
};

class Subprogram_Declarations : public Node
{
public:
	vector<Subprogram_Declaration *> *decs;
	Subprogram_Declarations(int, int);
	Subprogram_Declarations(Subprogram_Declaration *, int, int);
	void AddDec(Subprogram_Declaration *);
	virtual void accept(NodeVisistor *);
};

class Program : public Node
{
public:
	Ident *id;
	Declarations *decs;
	Subprogram_Declarations *sub_decs;
	Compound_Statement *comp_stmt;
	Program(Ident *, Declarations *, Subprogram_Declarations *, Compound_Statement *, int, int);
	virtual void accept(NodeVisistor *);
};

class Add_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Add_expression(Expression *, Expression *, int, int);
	virtual void accept(NodeVisistor *);
};

class Minus_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Minus_expression(Expression *, Expression *, int, int);
	virtual void accept(NodeVisistor *);
};

class Mul_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Mul_expression(Expression *, Expression *, int, int);
	virtual void accept(NodeVisistor *);
};

class Divide_expression : public Expression
{
public:
	Expression *expression1;
	Expression *expression2;
	Divide_expression(Expression *, Expression *, int, int);
	virtual void accept(NodeVisistor *);
};

class NodeVisistor
{
public:
	virtual void Visit(Node *) = 0;
	virtual void Visit(Ident *) = 0;
	virtual void Visit(Ident_List *) = 0;
	virtual void Visit(Int_Num *) = 0;
	virtual void Visit(Real_Num *) = 0;
	virtual void Visit(Unary_Operator *) = 0;
	virtual void Visit(Standard_Type *) = 0;
	virtual void Visit(Type *) = 0;
	virtual void Visit(Parameter *) = 0;
	virtual void Visit(Declaration *) = 0;
	virtual void Visit(Declarations *) = 0;
	virtual void Visit(Expression *) = 0;
	virtual void Visit(Int_Expression *) = 0;
	virtual void Visit(Real_Expression *) = 0;
	virtual void Visit(Boolean_Expression *) = 0;
	virtual void Visit(Ident_Expression *) = 0;
	virtual void Visit(Expression_Expression *) = 0;
	virtual void Visit(Expression_List *) = 0;
	virtual void Visit(Unary_Expression *) = 0;
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
};

class PrintVisistor : public NodeVisistor
{
public:
	virtual void Visit(Node *);
	virtual void Visit(Ident *);
	virtual void Visit(Ident_List *);
	virtual void Visit(Int_Num *);
	virtual void Visit(Real_Num *);
	virtual void Visit(Unary_Operator *);
	virtual void Visit(Standard_Type *);
	virtual void Visit(Type *);
	virtual void Visit(Parameter *);
	virtual void Visit(Declaration *);
	virtual void Visit(Declarations *);
	virtual void Visit(Expression *);
	virtual void Visit(Int_Expression *);
	virtual void Visit(Real_Expression *);
	virtual void Visit(Boolean_Expression *);
	virtual void Visit(Ident_Expression *);
	virtual void Visit(Expression_Expression *);
	virtual void Visit(Expression_List *);
	virtual void Visit(Unary_Expression *);
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
};

// class TypeVisitor : public NodeVisistor
// {
// public:
// 	// TypeVisitor() {}
// 	// virtual void Visit(Node *);
// 	// virtual void Visit(Ident *);
// 	// virtual void Visit(Ident_List *);
// 	// virtual void Visit(Int_Num *);
// 	// virtual void Visit(Real_Num *);
// 	// virtual void Visit(Unary_Operator *);
// 	// virtual void Visit(Standard_Type *);
// 	// virtual void Visit(Type *);
// 	// virtual void Visit(Parameter *);
// 	// virtual void Visit(Declaration *);
// 	// virtual void Visit(Declarations *);
// 	// virtual void Visit(Expression *);
// 	// virtual void Visit(Int_Expression *);
// 	// virtual void Visit(Real_Expression *);
// 	// virtual void Visit(Boolean_Expression *);
// 	// virtual void Visit(Ident_Expression *);
// 	// virtual void Visit(Expression_Expression *);
// 	// virtual void Visit(Expression_List *);
// 	// virtual void Visit(Unary_Expression *);
// 	// virtual void Visit(Not_Expression *);
// 	// virtual void Visit(Statement *);
// 	// virtual void Visit(Statement_List *);
// 	// virtual void Visit(If_Statement *);
// 	// virtual void Visit(While_Statement *);
// 	// virtual void Visit(If_Else_Statement *);
// 	// virtual void Visit(Compound_Statement *);
// 	// virtual void Visit(Optional_Statements *);
// 	// virtual void Visit(Variable_Statement *);
// 	// virtual void Visit(Parameter_List *);
// 	// virtual void Visit(Arguments *);
// 	// virtual void Visit(Procedure_Statement *);
// 	// virtual void Visit(Variable *);
// 	// virtual void Visit(Subprogram_Head *);
// 	// virtual void Visit(Subprogram_Declaration *);
// 	// virtual void Visit(Subprogram_Declarations *);
// 	// virtual void Visit(Program *);
// 	// virtual void Visit(Add_expression *);
// 	// virtual void Visit(Minus_expression *);
// 	// virtual void Visit(Mul_expression *);
// 	// virtual void Visit(Divide_expression *);
// };

// class CodeVisitor : public NodeVisistor
// {
// public:
// 	// virtual void Visit(Node *)  ;
// 	// virtual void Visit(Ident *)  ;
// 	// virtual void Visit(Ident_List *)  ;
// 	// virtual void Visit(Int_Num *)  ;
// 	// virtual void Visit(Real_Num *)  ;
// 	// virtual void Visit(Unary_Operator *)  ;
// 	// virtual void Visit(Standard_Type *)  ;
// 	// virtual void Visit(Type *)  ;
// 	// virtual void Visit(Parameter *)  ;
// 	// virtual void Visit(Declaration *)  ;
// 	// virtual void Visit(Declarations *)  ;
// 	// virtual void Visit(Expression *)  ;
// 	// virtual void Visit(Int_Expression *)  ;
// 	// virtual void Visit(Real_Expression *)  ;
// 	// virtual void Visit(Boolean_Expression *)  ;
// 	// virtual void Visit(Ident_Expression *)  ;
// 	// virtual void Visit(Expression_Expression *)  ;
// 	// virtual void Visit(Expression_List *)  ;
// 	// virtual void Visit(Unary_Expression *)  ;
// 	// virtual void Visit(Not_Expression *)  ;
// 	// virtual void Visit(Statement *)  ;
// 	// virtual void Visit(Statement_List *)  ;
// 	// virtual void Visit(If_Statement *)  ;
// 	// virtual void Visit(While_Statement *)  ;
// 	// virtual void Visit(If_Else_Statement *)  ;
// 	// virtual void Visit(Compound_Statement *)  ;
// 	// virtual void Visit(Optional_Statements *)  ;
// 	// virtual void Visit(Variable_Statement *)  ;
// 	// virtual void Visit(Parameter_List *)  ;
// 	// virtual void Visit(Arguments *)  ;
// 	// virtual void Visit(Procedure_Statement *)  ;
// 	// virtual void Visit(Variable *)  ;
// 	// virtual void Visit(Subprogram_Head *)  ;
// 	// virtual void Visit(Subprogram_Declaration *)  ;
// 	// virtual void Visit(Subprogram_Declarations *)  ;
// 	// virtual void Visit(Program *)  ;
// 	// virtual void Visit(Add_expression *)  ;
// 	// virtual void Visit(Minus_expression *)  ;
// 	// virtual void Visit(Mul_expression *)  ;
// 	// virtual void Visit(Divide_expression *)  ;
// };