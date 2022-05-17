#pragma once
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

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

class Node
{
public:
	int line;
	int column;
	Node *father;
	Node(int, int);
};

class Ident : public Node
{
public:
	string name;
	Ident(string n, int l, int c);
};

class Ident_List : public Node
{
public:
	vector<Ident *> *idents;
	Ident_List(int, int);
	Ident_List(Ident *, int, int);
	void AddIdent(Ident *);
};

class Int_Num : public Node
{
public:
	int value;
	Int_Num(int, int, int);
};

class Real_Num : public Node
{
public:
	float value;
	Real_Num(float, int, int);
};

class Unary_Operator : public Node
{
public:
	string op;
	Unary_Operator(string, int, int);
};

class Standard_Type : public Node
{
public:
	char type;
	Standard_Type(char, int, int);
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
};

class Parameter : public Node
{
public:
	Ident_List *ident_list;
	Type *type;
	Parameter(Ident_List *, Type *, int, int);
};

class Parameter_List : public Node
{
public:
	vector<Parameter *> *params;
	Parameter_List(int, int);
	Parameter_List(Parameter *, int, int);
	void AddParam(Parameter *);
};

class Declaration : public Node
{
public:
	Parameter *param;
	Declaration(Parameter *, int, int);
};

class Declarations : public Node
{
public:
	vector<Declaration *> *decs;
	Declarations(int, int);
	Declarations(Declaration *, int, int);
	void AddDec(Declaration *);
};

class Arguments : public Node
{
public:
	Parameter_List *param_lst;
	Arguments(Parameter_List *, int, int);
};
class Expression : public Node
{
public:
	Expression(int, int);
};

class Int_Expression : public Expression
{
public:
	Int_Num *value;
	Int_Expression(Int_Num *, int, int);
};
class Real_Expression : public Expression
{
public:
	Real_Num *value;
	Real_Expression(Real_Num *, int, int);
};
class Boolean_Expression : public Expression
{
public:
	bool value;
	Boolean_Expression(bool, int, int);
};
class Ident_Expression : public Expression
{
public:
	Ident *ident;
	Expression_List *expr_lst;
	Ident_Expression(Ident *, Expression_List *, int, int);
	Ident_Expression(Ident *, int, int);
};
class Expression_Expression : public Expression
{
public:
	Expression *expression;
	Expression_Expression(Expression *, int, int);
};
class Unary_Expression : public Expression
{
public:
	Expression *left_exp;
	Unary_Operator *op;
	Expression *right_exp;
	Unary_Expression(Expression *, Unary_Operator *, Expression *, int, int);
};
class Not_Expression : public Expression
{
public:
	Expression *expression;
	Not_Expression(Expression *, int, int);
};

class Expression_List : public Node
{
public:
	vector<Expression *> *exprs;
	Expression_List(int, int);
	Expression_List(Expression *, int, int);
	void AddExpr(Expression *);
};