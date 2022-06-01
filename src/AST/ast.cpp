#include "ast.h"

Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = NULL;
}
void Node::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Ident::Ident(string s, int l, int c) : Node(l, c)
{
	this->name = s;
}
void Ident::accept(NodeVisistor *nv)
{
	nv->Visit(this);
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
void Ident_list::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Int_Num::Int_Num(int v, int l, int c) : Node(l, c)
{
	this->value = v;
}
void Int_Num::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Real_Num::Real_Num(float v, int l, int c) : Node(l, c)
{
	this->value = v;
}
void Real_Num::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Unary_Operator::Unary_Operator(string o, int l, int c) : Node(l, c)
{
	this->op = o;
}
void Unary_Operator::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Standard_Type::Standard_Type(char t, int l, int c) : Node(l, c)
{
	this->type = t;
}
void Standard_Type::accept(NodeVisistor *nv)
{
	nv->Visit(this);
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
void Type::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Parameter::Parameter(Ident_List *id_lst, Type *t, int l, int c) : Node(l, c)
{
	this->ident_list = id_lst;
	this->type = t;
	id_lst->father = this;
	t->father = this;
}
void Parameter::accept(NodeVisistor *nv)
{
	nv->Visit(this);
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
void Parameter_List::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Declaration::Declaration(Parameter *p, int l, int c) : Node(l, c)
{
	this->param = p;
	p->father = this;
}
void Declaration::accept(NodeVisistor *nv)
{
	nv->Visit(this);
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
void Declarations::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Arguments::Arguments(Parameter_List *p_lst, int l, int c) : Node(l, c)
{
	this->param_lst = p_lst;
	p_lst->father = this;
}
void Arguments::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Expression::Expression(int l, int c) : Node(l, c)
{
}
void Expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Int_Expression::Int_Expression(Int_Num *v, int l, int c) : Expression(l, c)
{
	this->value = v;
}
void Int_Expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Real_Expression::Real_Expression(Real_Num *v, int l, int c) : Expression(l, c)
{
	this->value = v;
}
void Real_Expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Boolean_Expression::Boolean_Expression(bool v, int l, int c) : Expression(l, c)
{
	this->value = v;
}
void Boolean_Expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
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
void Ident_Expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Expression_Expression::Expression_Expression(Expression *exp, int l, int c) : Expression(l, c)
{
	this->expression = exp;
	exp->father = this;
}
void Expression_Expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
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
void Unary_Expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Not_Expression::Not_Expression(Expression *e, int l, int c) : Expression(l, c)
{
	this->expression = e;
	e->father = this;
}
void Not_Expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
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
void Expression_List::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Procedure_Statement::Procedure_Statement(Ident *i, int l, int c) : Statement(l, c)
{
	this->id = i;
	i->father = this;
}

Procedure_Statement::Procedure_Statement(Ident *i, Expression_List *el, int l, int c) : Statement(l, c)
{
	this->id = i;
	i->father = this;
	this->expr_lst = el;
	el->father = this;
}
void Procedure_Statement::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Statement::Statement(int a, int b) : Node(a, b)
{
}
void Statement::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Variable_Statement::Variable_Statement(Variable *v, Expression *e, int l, int c) : Statement(l, c)
{
	this->variable = v;
	this->expression = e;
	v->father = this;
	e->father = this;
}
void Variable_Statement::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Compound_Statement::Compound_Statement(Optional_Statements *os, int l, int c) : Statement(l, c)
{
	this->optional_statements = os;
	if (os != NULL)
		os->father = this;
}
void Compound_Statement::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
If_Statement::If_Statement(Expression *e, Statement *s, int l, int c) : Statement(l, c)
{
	this->expression = e;
	this->statement = s;
	e->father = this;
	s->father = this;
}
void If_Statement::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
If_Else_Statement::If_Else_Statement(Expression *e, Statement *s1, Statement *s2, int l, int c) : Statement(l, c)
{
	this->statement1 = s1;
	this->statement2 = s2;
	this->expression = e;
	s1->father = this;
	s2->father = this;
	e->father = this;
}
void If_Else_Statement::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
While_Statement::While_Statement(Expression *e, Statement *s, int l, int c) : Statement(l, c)
{
	this->expression = e;
	this->statement = s;
	e->father = this;
	s->father = this;
}
void While_Statement::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Optional_Statements::Optional_Statements(Statement_List *sl, int l, int c) : Statement(l, c)
{
	this->statement_list = sl;
	sl->father = this;
}

Optional_Statements::Optional_Statements(int l, int c) : Statement(l, c)
{
}
void Optional_Statements::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Statement_List::Statement_List(int l, int c) : Node(l, c)
{
	this->stmts = new vector<Statement *>;
}

Statement_List::Statement_List(Statement *s, int l, int c) : Node(l, c)
{
	this->stmts = new vector<Statement *>;
	this->AddStatement(s);
}

void Statement_List::AddStatement(Statement *s)
{
	this->stmts->push_back(s);
	s->father = this;
}
void Statement_List::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Variable::Variable(Ident *i, int l, int c) : Node(l, c)
{
	this->id = i;
	i->father = this;
}

Variable::Variable(Ident *i, Expression *e, int l, int c) : Node(l, c)
{
	this->id = i;
	i->father = this;
	this->expr = e;
	e->father = this;
}
void Variable::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Subprogram_Head::Subprogram_Head(Arguments *a, int l, int c) : Node(l, c)
{
	this->args = a;
	this->is_function = false;
	if (a != NULL)
		a->father = this;
}

Subprogram_Head::Subprogram_Head(Arguments *a, Standard_Type *s, int l, int c) : Node(l, c)
{
	this->args = a;
	this->std_type = s;
	this->is_function = true;
	s->father = this;
	if (a != NULL)
		a->father = this;
}
void Subprogram_Head::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Subprogram_Declaration::Subprogram_Declaration(Subprogram_Head *s, Compound_Statement *cs, int l, int c) : Node(l, c)
{
	this->sub_head = s;
	this->comp_stmt = cs;
	s->father = this;
	cs->father = this;
}
void Subprogram_Declaration::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Subprogram_Declarations::Subprogram_Declarations(int l, int c) : Node(l, c)
{
	this->decs = new vector<Subprogram_Declaration *>;
}

Subprogram_Declarations::Subprogram_Declarations(Subprogram_Declaration *dec, int l, int c) : Node(l, c)
{
	this->decs = new vector<Subprogram_Declaration *>;
	this->AddDec(dec);
}

void Subprogram_Declarations::AddDec(Subprogram_Declaration *dec)
{
	this->decs->push_back(dec);
	dec->father = this;
}
void Subprogram_Declarations::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}
Program::Program(Ident *i, Declarations *d, Subprogram_Declarations *sd, Compound_Statement *cs, int l, int c) : Node(l, c)
{
	this->id = i;
	this->decs = d;
	this->sub_decs = sd;
	this->comp_stmt = cs;
	if (d != NULL)
		d->father = this;
	if (sd != NULL)
		sd->father = this;
	cs->father = this;
	i->father = this;
}


Add_expression::Add_expression(Expression * e1, Expression * e2, int lin, int col) :Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != NULL)
		e1->father = this;
	if (e2 != NULL)
		e2->father = this;
}
void Add_expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}


Minus_expression::Minus_expression(Expression * e1, Expression * e2, int lin, int col) :Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != NULL)
		e1->father = this;
	if (e2 != NULL)
		e2->father = this;
}
void Minus_expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}

Mul_expression::Mul_expression(Expression * e1, Expression * e2, int lin, int col) :Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != NULL)
		e1->father = this;
	if (e2 != NULL)
		e2->father = this;
}
void Mul_expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}

Divide_expression::Divide_expression(Expression * e1, Expression * e2, int lin, int col) :Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != NULL)
		e1->father = this;
	if (e2 != NULL)
		e2->father = this;
}
void Divide_expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}