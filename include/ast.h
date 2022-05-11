#pragma once

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

class Node;
class Func;
class Ident;
class Args;
class arg;
class Stmt;
class Stmts;

class Keyword;
class Program;
class Var;
class Integer;
class Real;
class Function;
class Procedure;
class While;
class Do;
class Begin;
class End;
class If;
class Then;
class Else;
class Array;
class Of;
class Div;
class Not;
class Or;
class And;

class Ident_List;
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

class Func : public Node
{
public:
	int type;
	Ident *name;
	Args *args;
	Stmts *stmts;
	Func(int, Ident *, Args *, Stmts *, int,
		 int);
};

class Arg : public Node
{
public:
	int type;
	Ident *name;
	Arg(int type, Ident *, int, int);
};

class Args : public Node
{
public:
	vector<Arg *> *args;
	Args(int, int);
	Args(Arg *, int, int);
	void AddArg(Arg *);
};

class Stmts : public Node
{
public:
	Stmt *stmts;
	Stmts(int, int);
	Stmts(Stmt *, int, int);
	void AddStmt(Stmt *);
};

class Stmt : public Node
{
public:
	Stmt *prev;
	Stmt *next;
	Stmt(int, int);
};

class Expr : public Node
{
public
	:
	int type;
	Expr(int, int);
};

class Num : public Node
{
public:
	int value;
	Num(int, int, int);
};

class NumExpr : public Expr
{
public:
	Num *num;
	NumExpr(Num *n, int, int);
};

class IdExpr : public Expr
{
public:
	Ident *ident;
	IdExpr(Ident *, int, int);
};

class Assign : public Expr
{
public:
	Ident *ident;
	Expr *expr;
	Assign(Ident *, Expr *, int, int);
};
class Add : public Expr
{
public:
	Expr *left;
	Expr *right;
	Add(Expr *, Expr *, int, int);
};

class ExprStmt : public Stmt
{
public:
	Expr *expr;
	ExprStmt(Expr *expr, int, int);
};

/* Keywords */

class Keyword : public Node
{
public:
	Keyword(int l, int c);
};

class Program : public Node
{
public:
	Program(int l, int c);
};

class Var : public Node
{
public:
	Var(int l, int c);
};

class Integer : public Node
{
public:
	Integer(int l, int c);
};

class Real : public Node
{
public:
	Real(int l, int c);
};

class Function : public Node
{
public:
	Function(int l, int c);
};

class Procedure : public Node
{
public:
	Procedure(int l, int c);
};

class While : public Node
{
public:
	While(int l, int c);
};

class Do : public Node
{
public:
	Do(int l, int c);
};

class Begin : public Node
{
public:
	Begin(int l, int c);
};

class End : public Node
{
public:
	End(int l, int c);
};

class If : public Node
{
public:
	If(int l, int c);
};

class Then : public Node
{
public:
	Then(int l, int c);
};

class Else : public Node
{
public:
	Else(int l, int c);
};

class Array : public Node
{
public:
	Array(int l, int c);
};

class Of : public Node
{
public:
	Of(int l, int c);
};

class Div : public Node
{
public:
	Div(int l, int c);
};

class Not : public Node
{
public:
	Not(int l, int c);
};

class Or : public Node
{
public:
	Or(int l, int c);
};

class And : public Node
{
public:
	And(int l, int c);
};