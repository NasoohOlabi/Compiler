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
	Func(int , Ident *, Args *, Stmts *, int,
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
	Expr*expr;
	Assign(Ident *, Expr *, int, int);
};
class Add : public Expr
{
public:
	Expr*left;
	Expr*right;
	Add(Expr *, Expr *, int, int);
};



class ExprStmt : public Stmt
{
public:
	Expr *expr;
	ExprStmt(Expr *expr, int, int);
};
