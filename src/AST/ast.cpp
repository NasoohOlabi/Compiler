#include "ast.h"

Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = NULL;
}

Ident::Ident(string s, int l, int c) : Node(l, c)
{
	this->name = s;
}

Func::Func(int t, Ident *n, Args *as, Stmts
	*ss, int l, int c) : Node(l, c)
{
	this->type = t;
	this->name = n;
	this->args = as;
	this->stmts = ss;	
	n->father = this;
	as->father = this;
	ss->father = this;
}

Arg::Arg(int t, Ident *n, int l, int c)
	: Node(l, c)
{
	this->type = t;
	this->name = n;
	n->father = this;
}

Args::Args(int l, int c) : Node(l, c)
{
	this->args = new vector<Arg *>;
}
Args::Args(Arg *a, int l, int c) : Node(l, c)
{
	this->args = new vector<Arg *>;
	this->AddArg(a);
}
void
Args::AddArg(Arg *a)
{
	this->args->push_back(a);
	a->father = this;
}

Stmt::Stmt(int l, int c) : Node(l, c)
{
	this->next = NULL;
	this->prev = NULL;
}

Stmts::Stmts(int l, int c) : Node(l, c)
{
	this->stmts = NULL;
}
Stmts::Stmts(Stmt *s, int l, int c) :	Node(l, c)
{
	this->stmts = NULL;
	this->AddStmt(s);
}

void
Stmts::AddStmt(Stmt *s)
{
	if (this->stmts == NULL)
	{
		this->stmts = s;
	}
	else
	{
		Stmt *p;
		p = this->stmts;
		while (p->next != NULL)
			p = p->next;
		p->next = s;
		s->prev = p;
		s->father = this;
	}
}


Num::Num(int value, int lin, int col) : Node(lin, col)
{
	this->value = value;
}

Expr::Expr(int lin, int col) : Node(lin, col)
{
	this->type = -1;
}



ExprStmt::ExprStmt(Expr *expr, int l, int c) : Stmt(l, c)
{
	this->expr = expr;
	expr->father = this;
}

NumExpr::NumExpr(Num *n, int l, int c) : Expr(l, c)
{
	this->num = n;
	n->father = this;
	this->type = 1;
}


IdExpr::IdExpr(Ident *id, int lin, int col) : Expr(lin, col)
{
	this->ident = id;
}

Assign::Assign(Ident *id, Expr *e, int lin, int col) : Expr(lin, col)
{
	this->ident = id;
	this->expr = e;
	id->father = this;
	e->father = this;
}

Add::Add(Expr *l, Expr *r, int lin, int col) : Expr(lin, col)
{
	this->left = l;
	this->right = r;
	left->father = this;
	right->father = this;
}