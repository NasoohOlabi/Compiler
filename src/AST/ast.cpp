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

Ident_List::Ident_List(int l, int c) : Node(l, c)
{
	this->idents = new vector<Ident *>;
}

Ident_List::Ident_List(Ident *id, int l, int c) : Node(l, c)
{
	this->idents = new vector<Ident *>;
	this->AddIdent(id);
}

void Ident_List::AddIdent(Ident *id)
{
	this->idents->push_back(id);
	id->father = this;
}

Int_Num::Int_Num(int v, int l, int c) : Node(l, c)
{
	this->value = v;
}

Real_Num::Real_Num(float v, int l, int c) : Node(l, c)
{
	this->value = v;
}

Unary_Operator::Unary_Operator(string o, int l, int c) : Node(l, c)
{
	this->op = o;
}

Standard_Type::Standard_Type(char t, int l, int c) : Node(l, c)
{
	this->type = t;
}

Type::Type(Standard_Type *st, int f, int lst, int l, int c) : Node(l, c)
{
	this->std_type = st;
	this->first = f;
	this->last = lst;
	this->is_array = true;
	st->father = this;
}

Type::Type(Standard_Type *st, int l, int c) : Node(l, c)
{
	this->std_type = st;
	this->is_array = false;
	st->father = this;
}

Parameter::Parameter(Ident_List *id_lst, Type *t, int l, int c) : Node(l, c)
{
	this->ident_list = id_lst;
	this->type = t;
	id_lst->father = this;
	t->father = this;
}

Parameter_List::Parameter_List(int l, int c) : Node(l, c)
{
	this->params = new vector<Parameter *>;
}

Parameter_List::Parameter_List(Parameter *p, int l, int c) : Node(l, c)
{
	this->params = new vector<Parameter *>;
	this->AddParam(p);
}

void Parameter_List::AddParam(Parameter *p)
{
	this->params->push_back(p);
	p->father = this;
}

Declaration::Declaration(Parameter *p, int l, int c) : Node(l, c)
{
	this->param = p;
	p->father = this;
}

Declarations::Declarations(int l, int c) : Node(l, c)
{
	this->decs = new vector<Declaration *>;
}

Declarations::Declarations(Declaration *dec, int l, int c) : Node(l, c)
{
	this->decs = new vector<Declaration *>;
	this->AddDec(dec);
}

void Declarations::AddDec(Declaration *dec)
{
	this->decs->push_back(dec);
	dec->father = this;
}

Arguments::Arguments(Parameter_List *p_lst, int l, int c) : Node(l, c)
{
	this->param_lst = p_lst;
	p_lst->father = this;
}

Expression::Expression(int l, int c) : Node(l, c)
{
}

Int_Expression::Int_Expression(int v, int l, int c) : Expression(l, c)
{
	this->value = v;
}

Real_Expression::Real_Expression(float v, int l, int c) : Expression(l, c)
{
	this->value = v;
}

Boolean_Expression::Boolean_Expression(bool v, int l, int c) : Expression(l, c)
{
	this->value = v;
}

Ident_Expression::Ident_Expression(Ident *id, int l, int c) : Expression(l, c)
{
	this->ident = id;
	id->father = this;
}

Ident_Expression::Ident_Expression(Ident *id, Expression_List *e_lst, int l, int c) : Expression(l, c)
{
	this->ident = id;
	this->expr_lst = e_lst;
	id->father = this;
	e_lst->father = this;
}

Expression_Expression::Expression_Expression(Expression *exp, int l, int c) : Expression(l, c)
{
	this->expression = exp;
	exp->father = this;
}

Unary_Expression::Unary_Expression(Expression *le, Unary_Operator *o, Expression *re, int l, int c) : Expression(l, c)
{
	this->left_exp = le;
	this->op = o;
	this->right_exp = re;
	le->father = this;
	o->father = this;
	re->father = this;
}

Not_Expression::Not_Expression(Expression *e, int l, int c) : Expression(l, c)
{
	this->expression = e;
	e->father = this;
}

Expression_List::Expression_List(int l, int c) : Node(l, c)
{
	this->exprs = new vector<Expression *>;
}

Expression_List::Expression_List(Expression *e, int l, int c) : Node(l, c)
{
	this->exprs = new vector<Expression *>;
	this->AddExpr(e);
}

void Expression_List::AddExpr(Expression *e)
{
	this->exprs->push_back(e);
	e->father = this;
}