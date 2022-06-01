#include "ast.h"

Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = NULL;
}

// void Node::accept(NodeVisistor *nv)
// {
// 	nv->Visit(this);
// }

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

void Ident_List::accept(NodeVisistor *nv)
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

Add_expression::Add_expression(Expression *e1, Expression *e2, int lin, int col) : Expression(lin, col)
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

Minus_expression::Minus_expression(Expression *e1, Expression *e2, int lin, int col) : Expression(lin, col)
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

Mul_expression::Mul_expression(Expression *e1, Expression *e2, int lin, int col) : Expression(lin, col)
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

Divide_expression::Divide_expression(Expression *e1, Expression *e2, int lin, int col) : Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != NULL)
		e1->father = this;
	if (e2 != NULL)
		;
	e2->father = this;
}

void Divide_expression::accept(NodeVisistor *nv)
{
	nv->Visit(this);
}

/************************ Print Visitors ************************/

void PrintVisistor::Visit(Node *n)
{
	cout << "Node\n";
}

void PrintVisistor::Visit(Ident *n)
{
	cout << "Identifier:: \nName -> " << n->name;
}

void PrintVisistor::Visit(Ident_List *n)
{
	cout << "Identifiers List:: \n";
	for (int i = 0; i < (n->idents)->size(); i++)
	{
		cout << "Identifier number " << i << " ::\n";
		n->idents->at(i)->accept(this);
	}
}

void PrintVisistor::Visit(Int_Num *n)
{
	cout << "Int Number:: \nValue -> " << n->value;
}

void PrintVisistor::Visit(Real_Num *n)
{
	cout << "Real Number:: \nValue -> " << n->value;
}

void PrintVisistor::Visit(Unary_Operator *n)
{
	cout << "Unary Operator:: \nOpreation -> " << n->op;
}

void PrintVisistor::Visit(Standard_Type *n)
{
	cout << "Standard Type:: \nType -> " << n->type;
}

void PrintVisistor::Visit(Type *n)
{
	bool b = n->is_array;
	if (b)
	{
		cout << "Type (Array):: \nFirst -> " << n->first << "\nLast -> " << n->last << "\n";
	}
	else
	{
		cout << "Type (Non-Array):: \n";
	}
	cout << "Std Type ->\n";
	n->std_type->accept(this);
}

void PrintVisistor::Visit(Parameter *n)
{
	cout << "Parameter:: \nType -> \n";
	n->type->accept(this);
	cout << "\nIdent List -> \n";
	n->ident_list->accept(this);
}

void PrintVisistor::Visit(Declaration *n)
{
	cout << "Declaration:: \nParameter -> \n";
	n->param->accept(this);
}

void PrintVisistor::Visit(Declarations *n)
{
	cout << "Declarations List:: \n";
	for (int i = 0; i < (n->decs)->size(); i++)
	{
		cout << "Declaration number " << i << " ::\n";
		n->decs->at(i)->accept(this);
	}
}

void PrintVisistor::Visit(Expression *n)
{
	cout << "Expression:: \n";
}

void PrintVisistor::Visit(Int_Expression *n)
{
	cout << "Int Expression:: \nValue -> " << n->value;
}

void PrintVisistor::Visit(Real_Expression *n)
{
	cout << "Real Expression:: \nValue -> " << n->value;
}

void PrintVisistor::Visit(Boolean_Expression *n)
{
	cout << "Boolean Expression:: \nValue -> " << n->value;
}

void PrintVisistor::Visit(Ident_Expression *n)
{
	cout << "Ident Expression:: \nIdent -> \n";
	n->ident->accept(this);
	if (n->expr_lst)
	{
		cout << "Expr List -> \n";
		n->expr_lst->accept(this);
	}
}

void PrintVisistor::Visit(Expression_Expression *n)
{
	cout << "Expression Expression:: \nExpr -> \n";
	n->expression->accept(this);
}

void PrintVisistor::Visit(Expression_List *n)
{
	cout << "Expressions List:: \n";
	for (int i = 0; i < (n->exprs)->size(); i++)
	{
		cout << "Expression number " << i << " ::\n";
		n->exprs->at(i)->accept(this);
	}
}

void PrintVisistor::Visit(Unary_Expression *n)
{
	cout << "Unary Expression:: \nLeft Expr -> \n";
	n->left_exp->accept(this);
	cout << "\nOpreator -> \n";
	n->op->accept(this);
	cout << "\nRight Expr -> \n";
	n->right_exp->accept(this);
}

void PrintVisistor::Visit(Not_Expression *n)
{
	cout << "Not Expression:: \nExpr -> \n";
	n->expression->accept(this);
}

void PrintVisistor::Visit(Statement *n)
{
	cout << "Statement:: \n";
}

void PrintVisistor::Visit(Statement_List *n)
{
	cout << "Statements List:: \n";
	for (int i = 0; i < (n->stmts)->size(); i++)
	{
		cout << "Statement number " << i << " ::\n";
		n->stmts->at(i)->accept(this);
	}
}

void PrintVisistor::Visit(If_Statement *n)
{
	cout << "If Statement:: \nExpr -> \n";
	n->expression->accept(this);
	cout << "\nStmt -> \n";
	n->statement->accept(this);
}

void PrintVisistor::Visit(While_Statement *n)
{
	cout << "While Statement:: \nExpr -> \n";
	n->expression->accept(this);
	cout << "\nStmt -> \n";
	n->statement->accept(this);
}

void PrintVisistor::Visit(If_Else_Statement *n)
{
	cout << "If Else Statement:: \nExpr -> \n";
	n->expression->accept(this);
	cout << "\nStmt -> \n";
	n->statement1->accept(this);
	cout << "\nElse Stmt -> \n";
	n->statement2->accept(this);
}

void PrintVisistor::Visit(Compound_Statement *n)
{
	cout << "Compund Statement:: \nOptional Stmts -> \n";
	n->optional_statements->accept(this);
}

void PrintVisistor::Visit(Optional_Statements *n)
{
	cout << "Optional Statement:: \nStmt List -> \n";
	n->statement_list->accept(this);
}

void PrintVisistor::Visit(Variable_Statement *n)
{
	cout << "Variable Statement:: \nVariable -> \n";
	n->variable->accept(this);
	cout << "\nExpr -> \n";
	n->expression->accept(this);
}

void PrintVisistor::Visit(Parameter_List *n)
{
	cout << "Parameters List:: \n";
	for (int i = 0; i < (n->params)->size(); i++)
	{
		cout << "Parameter number " << i << " ::\n";
		n->params->at(i)->accept(this);
	}
}

void PrintVisistor::Visit(Arguments *n)
{
	cout << "Arguments List:: \nParam List -> \n";
	n->param_lst->accept(this);
}

void PrintVisistor::Visit(Procedure_Statement *n)
{
	cout << "Procedure Statement:: \nIdent -> \n";
	n->id->accept(this);
	if (n->expr_lst)
	{
		cout << "Expr List -> \n";
		n->expr_lst->accept(this);
	}
}

void PrintVisistor::Visit(Variable *n)
{
	cout << "Variable:: \nIdent -> \n";
	n->id->accept(this);
	if (n->expr)
	{
		cout << "Expr -> \n";
		n->expr->accept(this);
	}
}

void PrintVisistor::Visit(Subprogram_Head *n)
{
	cout << "Subprogram Head:: \nType -> " << (n->is_function ? "Function" : "Procedure");
	cout << "\nArguments -> \n";
	n->args->accept(this);
	if (n->std_type)
	{
		cout << "\nStd type -> \n";
		n->std_type->accept(this);
	}
}

void PrintVisistor::Visit(Subprogram_Declaration *n)
{
	cout << "Subprogram Declaration:: \nSubHead -> \n";
	n->sub_head->accept(this);
	cout << "\nCompound Stmt -> \n";
	n->comp_stmt->accept(this);
}

void PrintVisistor::Visit(Subprogram_Declarations *n)
{
	cout << "Subprogram Declarations List:: \n";
	for (int i = 0; i < (n->decs)->size(); i++)
	{
		cout << "Subprogram Declaration number " << i << " ::\n";
		n->decs->at(i)->accept(this);
	}
}

void PrintVisistor::Visit(Program *n)
{
	cout << "Program (root):: \nIdent -> \n";
	n->id->accept(this);
	cout << "\nDeclarations -> \n";
	n->decs->accept(this);
	cout << "\nSubprogram Declarations -> \n";
	n->sub_decs->accept(this);
	cout << "\nCompound Stmt -> \n";
	n->comp_stmt->accept(this);
}

void PrintVisistor::Visit(Add_expression *n)
{
	cout << "Add Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

void PrintVisistor::Visit(Minus_expression *n)
{
	cout << "Minus Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

void PrintVisistor::Visit(Mul_expression *n)
{
	cout << "Multiplication Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

void PrintVisistor::Visit(Divide_expression *n)
{
	cout << "Division Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}
