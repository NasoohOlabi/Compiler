#include "ast.h"

Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = nullptr;
}

// void Node::accept(NodeVisitor *nv)
// {
// 	nv->Visit(this);
// }

Ident::Ident(string s, int l, int c) : Node(l, c)
{
	this->name = s;
	this->symbol = NULL;
}

void Ident::accept(NodeVisitor *nv)
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

void Ident_List::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Int_Num::Int_Num(int v, int l, int c) : Node(l, c)
{
	this->value = v;
}

void Int_Num::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Real_Num::Real_Num(float v, int l, int c) : Node(l, c)
{
	this->value = v;
}

void Real_Num::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Standard_Type::Standard_Type(char t, int l, int c) : Node(l, c)
{
	this->type = t;
}

void Standard_Type::accept(NodeVisitor *nv)
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

void Type::accept(NodeVisitor *nv)
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

void Parameter::accept(NodeVisitor *nv)
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
void Parameter_List::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Declaration::Declaration(Parameter *p, int l, int c) : Node(l, c)
{
	this->param = p;
	p->father = this;
}

void Declaration::accept(NodeVisitor *nv)
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
	dec->father = this;
}

void Declarations::AddDec(Declaration *dec)
{
	this->decs->push_back(dec);
	dec->father = this;
}

void Declarations::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Local_Declaration::Local_Declaration(Parameter *p, int l, int c) : Node(l, c)
{
	this->param = p;
	p->father = this;
}

void Local_Declaration::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Local_Declarations::Local_Declarations(int l, int c) : Node(l, c)
{
	this->decs = new vector<Local_Declaration *>;
}

Local_Declarations::Local_Declarations(Local_Declaration *dec, int l, int c) : Node(l, c)
{
	this->decs = new vector<Local_Declaration *>;
	this->AddDec(dec);
	dec->father = this;
}

void Local_Declarations::AddDec(Local_Declaration *dec)
{
	this->decs->push_back(dec);
	dec->father = this;
}

void Local_Declarations::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Arguments::Arguments(int l, int c) : Node(l, c)
{
	this->param_lst = NULL;
}

Arguments::Arguments(Parameter_List *p_lst, int l, int c) : Node(l, c)
{
	this->param_lst = p_lst;
	p_lst->father = this;
}

void Arguments::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Expression::Expression(int l, int c) : Node(l, c)
{
}

void Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Int_Expression::Int_Expression(Int_Num *v, int l, int c) : Expression(l, c)
{
	this->value = v;
	this->type = "INT";
}

void Int_Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Real_Expression::Real_Expression(Real_Num *v, int l, int c) : Expression(l, c)
{
	this->value = v;
	this->type = "RL";
}

void Real_Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Boolean_Expression::Boolean_Expression(bool v, int l, int c) : Expression(l, c)
{
	this->value = v;
	this->type = "BOOL";
}

void Boolean_Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Function_Expression::Function_Expression(Ident *id, Expression_List *e_lst, int l, int c) : Expression(l, c)
{
	this->ident = id;
	this->expr_lst = e_lst;
	id->father = this;
	e_lst->father = this;
}

Function_Expression::Function_Expression(Ident *id, int l, int c) : Expression(l, c)
{
	this->ident = id;
	id->father = this;
}

void Function_Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Ident_Expression::Ident_Expression(Ident *id, int l, int c) : Expression(l, c)
{
	this->ident = id;
	id->father = this;
}

void Ident_Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Expression_Expression::Expression_Expression(Expression *exp, int l, int c) : Expression(l, c)
{
	this->expression = exp;
	exp->father = this;
}

void Expression_Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Not_Expression::Not_Expression(Expression *e, int l, int c) : Expression(l, c)
{
	this->expression = e;
	e->father = this;
}

void Not_Expression::accept(NodeVisitor *nv)
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

void Expression_List::accept(NodeVisitor *nv)
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

void Procedure_Statement::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Statement::Statement(int a, int b) : Node(a, b)
{
}

void Statement::accept(NodeVisitor *nv)
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

void Variable_Statement::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Compound_Statement::Compound_Statement(Optional_Statements *os, int l, int c) : Statement(l, c)
{
	this->optional_statements = os;
	if (os != nullptr)
		os->father = this;
}

void Compound_Statement::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

If_Statement::If_Statement(Expression *e, Statement_List *s, int l, int c) : Statement(l, c)
{
	this->expression = e;
	this->statement = s;
	e->father = this;
	s->father = this;
}

void If_Statement::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

If_Else_Statement::If_Else_Statement(Expression *e, Statement_List *s1, Statement_List *s2, int l, int c) : Statement(l, c)
{
	this->statement1 = s1;
	this->statement2 = s2;
	this->expression = e;
	s1->father = this;
	s2->father = this;
	e->father = this;
}

void If_Else_Statement::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

While_Statement::While_Statement(Expression *e, Statement_List *s, int l, int c) : Statement(l, c)
{
	this->expression = e;
	this->statement = s;
	e->father = this;
	s->father = this;
}

void While_Statement::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Return_Statement::Return_Statement(Expression *exp, int l, int c) : Statement(l, c)
{
	this->e = exp;
	exp->father = this;
}

void Return_Statement::accept(NodeVisitor *nv)
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

void Optional_Statements::accept(NodeVisitor *nv)
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

void Statement_List::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Variable::Variable(Ident *i, int l, int c) : Node(l, c)
{
	this->id = i;
	i->father = this;
	// this->is_array = false;
}

Variable::Variable(Ident *i, Expression *e, int l, int c) : Node(l, c)
{
	this->id = i;
	i->father = this;
	this->expr = e;
	e->father = this;
	// this->is_array = true;
}

void Variable::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Subprogram_Head::Subprogram_Head(Ident *id, Arguments *a, int l, int c) : Node(l, c)
{
	this->args = a;
	this->is_function = false;
	this->ident = id;
	this->std_type = NULL;
	if (a != nullptr)
		a->father = this;
}

Subprogram_Head::Subprogram_Head(Ident *id, Arguments *a, Standard_Type *s, int l, int c) : Node(l, c)
{
	this->args = a;
	this->std_type = s;
	this->is_function = true;
	this->ident = id;
	s->father = this;
	if (a != nullptr)
		a->father = this;
}
void Subprogram_Head::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Subprogram_Declaration::Subprogram_Declaration(Local_Declarations *d, Subprogram_Head *s, Compound_Statement *cs, int l, int c) : Node(l, c)
{
	this->sub_head = s;
	this->comp_stmt = cs;
	this->decs = d;
	d->father = this;
	s->father = this;
	cs->father = this;
}
void Subprogram_Declaration::accept(NodeVisitor *nv)
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

void Subprogram_Declarations::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Program::Program(Ident *i, Declarations *d, Subprogram_Declarations *sd, Compound_Statement *cs, int l, int c) : Node(l, c)
{
	this->id = i;
	this->decs = d;
	this->sub_decs = sd;
	this->comp_stmt = cs;
	if (d != nullptr)
		d->father = this;
	if (sd != nullptr)
		sd->father = this;
	cs->father = this;
	i->father = this;
	decs->father = this;
}

void Program::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Add_expression::Add_expression(Expression *e1, Expression *e2, int lin, int col) : Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != nullptr)
		e1->father = this;
	if (e2 != nullptr)
		e2->father = this;
}

void Add_expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Minus_expression::Minus_expression(Expression *e1, Expression *e2, int lin, int col) : Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != nullptr)
		e1->father = this;
	if (e2 != nullptr)
		e2->father = this;
}

void Minus_expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Mul_expression::Mul_expression(Expression *e1, Expression *e2, int lin, int col) : Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != nullptr)
		e1->father = this;
	if (e2 != nullptr)
		e2->father = this;
}

void Mul_expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Divide_expression::Divide_expression(Expression *e1, Expression *e2, int lin, int col) : Expression(lin, col)
{
	this->expression1 = e1;
	this->expression2 = e2;
	if (e1 != nullptr)
		e1->father = this;
	if (e2 != nullptr)
		e2->father = this;
}

void Divide_expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Binary_expression::Binary_expression(Expression *e1, Binary_opreator *o, Expression *e2, int lin, int col) : Expression(lin, col)
{
	this->expression1 = e1;
	this->op = o;
	this->expression2 = e2;
	if (e1 != nullptr)
		e1->father = this;
	if (e2 != nullptr)
		e2->father = this;
}

void Binary_expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Logical_expression::Logical_expression(Expression *e1, Logical_opreator *o, Expression *e2, int lin, int col) : Expression(lin, col)
{
	this->expression1 = e1;
	this->op = o;
	this->expression2 = e2;
	if (e1 != nullptr)
		e1->father = this;
	if (e2 != nullptr)
		e2->father = this;
}

void Logical_expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Array_expression::Array_expression(Ident *id, Expression *e, int lin, int col) : Expression(lin, col)
{
	this->index = e;
	this->name = id;
}

void Array_expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Binary_opreator::Binary_opreator(string o, int lin, int col) : Node(lin, col)
{
	this->op = o;
}

void Binary_opreator::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Logical_opreator::Logical_opreator(string o, int lin, int col) : Node(lin, col)
{
	this->op = o;
}

void Logical_opreator::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

/************************ Print Visitors ************************/

void PrintVisitor::Visit(Node *n)
{
	cout << "Node\n";
}

void PrintVisitor::Visit(Ident *n)
{
	cout << "Identifier:: \nName -> " << n->name << "\n";
}

void PrintVisitor::Visit(Ident_List *n)
{
	cout << "Identifiers List:: \n";
	for (int i = 0; i < (n->idents)->size(); i++)
	{
		cout << "Identifier number " << i << " ::\n";
		n->idents->at(i)->accept(this);
	}
}

void PrintVisitor::Visit(Int_Num *n)
{
	cout << "Int Number:: \nValue -> " << n->value << "\n";
}

void PrintVisitor::Visit(Real_Num *n)
{
	cout << "Real Number:: \nValue -> " << n->value << "\n";
}

void PrintVisitor::Visit(Standard_Type *n)
{
	cout << "Standard Type:: \nType -> " << n->type;
}

void PrintVisitor::Visit(Type *n)
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

void PrintVisitor::Visit(Parameter *n)
{
	cout << "Parameter:: \nType -> \n";
	n->type->accept(this);
	cout << "\nIdent List -> \n";
	n->ident_list->accept(this);
}

void PrintVisitor::Visit(Declaration *n)
{
	cout << "Declaration:: \nParameter -> \n";
	n->param->accept(this);
}

void PrintVisitor::Visit(Declarations *n)
{
	cout << "Declarations List:: \n";
	for (int i = 0; i < (n->decs)->size(); i++)
	{
		cout << "Declaration number " << i << " ::\n";
		n->decs->at(i)->accept(this);
	}
}

void PrintVisitor::Visit(Local_Declaration *n)
{
	cout << "Local Declaration:: \nParameter -> \n";
	n->param->accept(this);
}

void PrintVisitor::Visit(Local_Declarations *n)
{
	cout << "Local Declarations List:: \n";
	for (int i = 0; i < (n->decs)->size(); i++)
	{
		cout << "Local Declaration number " << i << " ::\n";
		n->decs->at(i)->accept(this);
	}
}

void PrintVisitor::Visit(Expression *n)
{
	cout << "Expression:: \n";
}

void PrintVisitor::Visit(Int_Expression *n)
{
	cout << "Int Expression:: \nValue -> \n";
	n->value->accept(this);
}

void PrintVisitor::Visit(Real_Expression *n)
{
	cout << "Real Expression:: \nValue -> \n";
	n->value->accept(this);
}

void PrintVisitor::Visit(Boolean_Expression *n)
{
	cout << "Boolean Expression:: \nValue ->" << n->value << "\n";
}

void PrintVisitor::Visit(Function_Expression *n)
{
	cout << "Function Expression:: \nIdent -> \n";
	n->ident->accept(this);
	if (n->expr_lst != NULL)
	{
		cout << "Expr List -> \n";
		n->expr_lst->accept(this);
	}
	else
	{
		cout << "\n";
	}
}

void PrintVisitor::Visit(Ident_Expression *n)
{
	cout << "Ident Expression:: \nIdent -> \n";
	n->ident->accept(this);
}

void PrintVisitor::Visit(Expression_Expression *n)
{
	cout << "Expression Expression:: \nExpr -> \n";
	n->expression->accept(this);
}

void PrintVisitor::Visit(Expression_List *n)
{
	cout << "Expressions List:: \n";
	for (int i = 0; i < (n->exprs)->size(); i++)
	{
		cout << "Expression number " << i << " ::\n";
		n->exprs->at(i)->accept(this);
	}
}

void PrintVisitor::Visit(Binary_expression *n)
{
	cout << "Binary Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nOperator -> ";
	n->op->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

void PrintVisitor::Visit(Logical_expression *n)
{
	cout << "Logical Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nOperator -> ";
	n->op->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

void PrintVisitor::Visit(Array_expression *n)
{
}

void PrintVisitor::Visit(Binary_opreator *n)
{
	cout << "Binary Opreator:: \nopreator -> " << n->op << "\n";
}

void PrintVisitor::Visit(Logical_opreator *n)
{
	cout << "Logical Opreator:: \nopreator -> " << n->op << "\n";
}

void PrintVisitor::Visit(Not_Expression *n)
{
	cout << "Not Expression:: \nExpr -> \n";
	n->expression->accept(this);
}

void PrintVisitor::Visit(Statement *n)
{
	cout << "Statement:: \n";
}

void PrintVisitor::Visit(Statement_List *n)
{
	cout << "Statements List:: \n";
	for (int i = 0; i < (n->stmts)->size(); i++)
	{
		cout << "Statement number " << i << " ::\n";
		n->stmts->at(i)->accept(this);
	}
}

void PrintVisitor::Visit(If_Statement *n)
{
	cout << "If Statement:: \nExpr -> \n";
	n->expression->accept(this);
	cout << "\nStmt -> \n";
	n->statement->accept(this);
}

void PrintVisitor::Visit(While_Statement *n)
{
	cout << "While Statement:: \nExpr -> \n";
	n->expression->accept(this);
	cout << "\nStmt -> \n";
	n->statement->accept(this);
}

void PrintVisitor::Visit(If_Else_Statement *n)
{
	cout << "If Else Statement:: \nExpr -> \n";
	n->expression->accept(this);
	cout << "\nStmt -> \n";
	n->statement1->accept(this);
	cout << "\nElse Stmt -> \n";
	n->statement2->accept(this);
}

void PrintVisitor::Visit(Compound_Statement *n)
{
	cout << "Compound Statement:: \nOptional Stmts -> \n";
	n->optional_statements->accept(this);
}

void PrintVisitor::Visit(Optional_Statements *n)
{
	cout << "Optional Statement:: \nStmt List -> \n";
	n->statement_list->accept(this);
}

void PrintVisitor::Visit(Return_Statement *n)
{
	cout << "Return Statement:: \nExp -> \n";
	n->e->accept(this);
}

void PrintVisitor::Visit(Variable_Statement *n)
{
	cout << "Variable Statement:: \nVariable -> \n";
	n->variable->accept(this);
	cout << "\nExpr -> \n";
	n->expression->accept(this);
}

void PrintVisitor::Visit(Parameter_List *n)
{
	cout << "Parameters List:: \n";
	for (int i = 0; i < (n->params)->size(); i++)
	{
		cout << "Parameter number " << i << " ::\n";
		n->params->at(i)->accept(this);
	}
}

void PrintVisitor::Visit(Arguments *n)
{
	cout << "Arguments List:: \nParam List -> \n";
	n->param_lst->accept(this);
}

void PrintVisitor::Visit(Procedure_Statement *n)
{
	cout << "Procedure Statement:: \nIdent -> \n";
	n->id->accept(this);
	if (n->expr_lst != NULL)
	{
		cout << "Expr List -> \n";
		n->expr_lst->accept(this);
	}
}

void PrintVisitor::Visit(Variable *n)
{
	cout << "Variable:: \nIdent -> \n";
	n->id->accept(this);
	if (n->expr)
	{
		cout << "Expr -> \n";
		n->expr->accept(this);
	}
}

void PrintVisitor::Visit(Subprogram_Head *n)
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

void PrintVisitor::Visit(Subprogram_Declaration *n)
{
	cout << "Subprogram Declaration:: Local Decs ->\n";
	n->decs->accept(this);
	cout << "\nSubHead-> \n ";
	n->sub_head->accept(this);
	cout << "\nCompound Stmt -> \n";
	n->comp_stmt->accept(this);
}

void PrintVisitor::Visit(Subprogram_Declarations *n)
{
	cout << "Subprogram Declarations List:: \n";
	for (int i = 0; i < (n->decs)->size(); i++)
	{
		cout << "Subprogram Declaration number " << i << " ::\n";
		n->decs->at(i)->accept(this);
	}
}

void PrintVisitor::Visit(Program *n)
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

void PrintVisitor::Visit(Add_expression *n)
{
	cout << "Add Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

void PrintVisitor::Visit(Minus_expression *n)
{
	cout << "Minus Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

void PrintVisitor::Visit(Mul_expression *n)
{
	cout << "Multiplication Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

void PrintVisitor::Visit(Divide_expression *n)
{
	cout << "Division Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
}

/************************ Type Checking Visitor ************************/

void TypeVisitor::Visit(Node *n)
{
	// cout << "Type Node\n";
}

void TypeVisitor::Visit(Ident *n)
{
	// cout << "Identifier:: \nName -> " << n->name << "\n";
}

void TypeVisitor::Visit(Ident_List *n)
{
	// cout << "Identifiers List:: \n";
	for (int i = 0; i < (n->idents)->size(); i++)
	{
		// cout << "Identifier number " << i << " ::\n";
		n->idents->at(i)->accept(this);
	}
}

void TypeVisitor::Visit(Int_Num *n)
{
	// cout << "Int Number:: \nValue -> " << n->value << "\n";
}

void TypeVisitor::Visit(Real_Num *n)
{
	// cout << "Real Number:: \nValue -> " << n->value << "\n";
}

void TypeVisitor::Visit(Standard_Type *n)
{
	// cout << "Standard Type:: \nType -> " << n->type;
}

void TypeVisitor::Visit(Type *n)
{
	// bool b = n->is_array;
	// if (b)
	// {
	// 	// cout << "Type (Array):: \nFirst -> " << n->first << "\nLast -> " << n->last << "\n";
	// }
	// else
	// {
	// 	// cout << "Type (Non-Array):: \n";
	// }
	// cout << "Std Type ->\n";
	n->std_type->accept(this);
}

void TypeVisitor::Visit(Parameter *n)
{
	// cout << "Parameter:: \nType -> \n";
	n->type->accept(this);
	// cout << "\nIdent List -> \n";
	n->ident_list->accept(this);
}

void TypeVisitor::Visit(Declaration *n)
{
	// cout << "Declaration:: \nParameter -> \n";
	n->param->accept(this);
}

void TypeVisitor::Visit(Declarations *n)
{
	// cout << "Declarations List:: \n";
	for (int i = 0; i < (n->decs)->size(); i++)
	{
		// cout << "Declaration number " << i << " ::\n";
		n->decs->at(i)->accept(this);
	}
}

void TypeVisitor::Visit(Local_Declaration *n)
{
	// cout << "Local Declaration:: \nParameter -> \n";
	n->param->accept(this);
}

void TypeVisitor::Visit(Local_Declarations *n)
{
	// cout << "Local Declarations List:: \n";
	for (int i = 0; i < (n->decs)->size(); i++)
	{
		// cout << "Local Declaration number " << i << " ::\n";
		n->decs->at(i)->accept(this);
	}
}

void TypeVisitor::Visit(Expression *n)
{
	// cout << "Expression:: \n";
}

void TypeVisitor::Visit(Int_Expression *n)
{
	// cout << "Int Expression:: \nValue -> \n";
	n->value->accept(this);
	n->type = "INT";
	// cout<<"--------------------------------------------------------------------INT Type:"<<n->type<<" at: "<<n->column<<" , "<<n->line<<"\n";
}

void TypeVisitor::Visit(Real_Expression *n)
{
	// cout << "Real Expression:: \nValue -> \n";
	n->value->accept(this);
	n->type = "RL";
	// cout<<"--------------------------------------------------------------------RL Type:"<<n->type<<"\n";
}

void TypeVisitor::Visit(Boolean_Expression *n)
{
	// cout << "Boolean Expression:: \nValue ->" << n->value << "\n";
	n->type = "BOOL";
	// cout<<"--------------------------------------------------------------------BOOL Type:"<<n->type<<"\n";
}

void TypeVisitor::Visit(Ident_Expression *n)
{
	if (n->ident->symbol != NULL)
	{
		char t = n->ident->symbol->type;

		if (n->ident->symbol->is_array)
		{
			n->type = "*";
		}
		else
		{
			n->type = "";
		}

		if (t == 'I' || t == 'J')
			n->type += "INT";
		if (t == 'R' || t == 'S')
			n->type += "RL";
		if (t == 'B' || t == 'C')
			n->type += "BOOL";
	}
	else
	{
		cout << "\nNULL Ident " << n->ident->name << "\n\n";
	}
}

void TypeVisitor::Visit(Function_Expression *n)
{

	if (n->expr_lst != NULL)
	{
		n->expr_lst->accept(this);
	}
	string ss = "";
	Symbol *s = symbolTable->lookUpFunction(n->ident, n->expr_lst, 1, ss);

	if (s == NULL)
	{
		n->symbol = NULL;
		return;
	}

	n->symbol = s;

	char t = n->symbol->type;

	if (n->ident->symbol->is_array)
	{
		n->type = "*";
	}
	else
	{
		n->type = "";
	}

	if (t == 'I' || t == 'J')
		n->type += "INT";
	if (t == 'R' || t == 'S')
		n->type += "RL";
	if (t == 'B' || t == 'C')
		n->type += "BOOL";
}

void TypeVisitor::Visit(Expression_Expression *n)
{
	// cout << "Expression Expression:: \nExpr -> \n";
	n->expression->accept(this);
}

void TypeVisitor::Visit(Expression_List *n)
{
	// cout << "Expressions List:: \n";
	for (int i = 0; i < (n->exprs)->size(); i++)
	{
		// cout << "Expression number " << i << " ::\n";
		n->exprs->at(i)->accept(this);
	}
}

void TypeVisitor::Visit(Binary_expression *n)
{
	// TODO
	//  cout << "Binary Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	// cout << "\nOperator -> ";
	n->op->accept(this);
	// cout << "\nRight Expr -> \n";
	n->expression2->accept(this);

	if (n->expression1->type == n->expression2->type && n->expression1->type != "BOOL")
		cout << "Binary Expression type checked correctly, line " << n->line << "\n\n";
	else
	{
		cout << "Type Error: line " << n->line << ", column " << n->column << endl;
		cout << "left:: " << n->expression1->type << " right:: " << n->expression2->type << "\n\n";
	}

	n->type = "BOOL";
}

void TypeVisitor::Visit(Logical_expression *n)
{
	// TODO
	//  cout << "Logical Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	// cout << "\nOperator -> ";
	n->op->accept(this);
	// cout << "\nRight Expr -> \n";
	n->expression2->accept(this);

	if (n->expression1->type == "BOOL" && n->expression2->type == "BOOL")
		cout << "Logical Expression type checked correctly, line " << n->line << "\n\n";
	else
	{
		cout << "Type Error: line " << n->line << ", column " << n->column << "\n\n";
	}

	n->type = "BOOL";
}

void TypeVisitor::Visit(Array_expression *n)
{
	// TODO
	//  cout << "Logical Expression:: \nLeft Expr -> \n";
	n->index->accept(this);
	// cout << "\nOperator -> ";
	n->name->accept(this);
	// cout << "\nRight Expr -> \n";

	// cout << "Expr -> \n";

	Symbol *s = symbolTable->lookUpSymbol(n->name);
	if (s != NULL)
	{
		if (s->type == 'I')
			n->type = "INT";
		if (s->type == 'R')
			n->type = "RL";
		if (s->type == 'B')
			n->type = "BOOL";
	}

	if (n->index->type == "INT")
	{
		cout << "Array with int index\n";
	}
	else
	{
		cout << "Error: Array not int index, line " << n->line;
	}

	// n->name->
}

void TypeVisitor::Visit(Binary_opreator *n)
{
	// cout << "Binary Opreator:: \nopreator -> " << n->op << "\n";
}

void TypeVisitor::Visit(Logical_opreator *n)
{
	// cout << "Logical Opreator:: \nopreator -> " << n->op << "\n";
}

void TypeVisitor::Visit(Not_Expression *n)
{
	// cout << "Not Expression:: \nExpr -> \n";
	n->expression->accept(this);
	n->type = "BOOL";
}

void TypeVisitor::Visit(Statement *n)
{
	// cout << "Statement:: \n";
}

void TypeVisitor::Visit(Statement_List *n)
{
	// cout << "Statements List:: \n";
	for (int i = 0; i < (n->stmts)->size(); i++)
	{
		// cout << "Statement number " << i << " ::\n";
		n->stmts->at(i)->accept(this);
	}
}

void TypeVisitor::Visit(If_Statement *n)
{
	// cout << "If Statement:: \nExpr -> \n";
	n->expression->accept(this);
	// cout << "\nStmt -> \n";
	n->statement->accept(this);
}

void TypeVisitor::Visit(While_Statement *n)
{
	// cout << "While Statement:: \nExpr -> \n";
	n->expression->accept(this);
	// cout << "\nStmt -> \n";
	n->statement->accept(this);
}

void TypeVisitor::Visit(If_Else_Statement *n)
{
	// cout << "If Else Statement:: \nExpr -> \n";
	n->expression->accept(this);
	// cout << "\nStmt -> \n";
	n->statement1->accept(this);
	// cout << "\nElse Stmt -> \n";
	n->statement2->accept(this);
}

void TypeVisitor::Visit(Compound_Statement *n)
{
	// cout << "Compound Statement:: \nOptional Stmts -> \n";
	n->optional_statements->accept(this);
}

void TypeVisitor::Visit(Optional_Statements *n)
{
	// cout << "Optional Statement:: \nStmt List -> \n";
	if (n->statement_list != NULL)
		n->statement_list->accept(this);
}

void TypeVisitor::Visit(Return_Statement *n)
{
	n->e->accept(this);
}

void TypeVisitor::Visit(Variable_Statement *n)
{

	n->variable->accept(this);
	n->expression->accept(this);

	// bool is_arr = n->variable->is_array;

	// cout << "HERE!" << endl;
	// if (n->variable->id->symbol->type == NULL)
	// 	cout << "null";

	if (n->variable->id->symbol == NULL)
	{
		cout << "this is null";
		return;
	}

	char ident_type = n->variable->id->symbol->type;

	string expr_type = "";

	if (n->expression->type.size() == 0)
	{
		expr_type = n->expression->symbol->type;
	}
	else
	{
		expr_type = n->expression->type;
	}

	if (dynamic_cast<Array_expression *>(n->expression) != NULL)
	{
		// cout << "dynamic cast";
		string ss = "";
		ss.push_back(expr_type[0] - 1);
		expr_type = ss;
	}

	if (n->variable->expr != NULL)
	{
		ident_type -= 1;
	}

	if (ident_type == 'I' && expr_type == "INT" || ident_type == 'R' && expr_type == "RL" || ident_type == 'B' && expr_type == "BOOL")
	{
		cout << "Assignemt Type checked correctly, line " << n->line << "\n\n";
	}
	else if (ident_type == 'I' && expr_type == "I" || ident_type == 'R' && expr_type == "R" || ident_type == 'B' && expr_type == "B")
	{
		cout << "Assignemt Type checked correctly, line " << n->line << "\n\n";
	}
	else
	{
		cout << "Type Error: line " << n->line << ", column " << n->column << "\n";
		cout << "left:: " << ident_type << "  right:: " << expr_type << "\n\n";
	}
}

void TypeVisitor::Visit(Parameter_List *n)
{
	// cout << "Parameters List:: \n";
	for (int i = 0; i < (n->params)->size(); i++)
	{
		// cout << "Parameter number " << i << " ::\n";
		n->params->at(i)->accept(this);
	}
}

void TypeVisitor::Visit(Arguments *n)
{
	// cout << "Arguments List:: \nParam List -> \n";
	if (n->param_lst != NULL)
	{
		n->param_lst->accept(this);
	}
}

void TypeVisitor::Visit(Procedure_Statement *n)
{
	n->id->accept(this);

	if (n->expr_lst != NULL)
	{
		n->expr_lst->accept(this);
	}
	string ss = "";
	Symbol *s = symbolTable->lookUpFunction(n->id, n->expr_lst, 2, ss);
}

void TypeVisitor::Visit(Variable *n)
{
	// cout << "Variable:: \nIdent -> \n";
	n->id->accept(this);
	if (n->expr)
	{
		// cout << "Expr -> \n";
		n->expr->accept(this);
		if (n->expr->type == "INT")
		{
			cout << "Array int index";
		}
		else
		{
			cout << "Error: Array not int index, line " << n->line;
		}
	}
}

void TypeVisitor::Visit(Subprogram_Head *n)
{
	// cout << "Subprogram Head:: \nType -> " << (n->is_function ? "Function" : "Procedure");
	// cout << "\nArguments -> \n";

	if (n->args != NULL && n->args->param_lst != NULL && n->args->param_lst->params != NULL)
	{
		n->args->accept(this);
	}

	if (n->std_type != NULL)
	{
		// cout << "\nStd type -> \n";
		n->std_type->accept(this);
	}
}

void TypeVisitor::Visit(Subprogram_Declaration *n)
{
	// cout << "Subprogram Declaration:: \nSubHead -> \n";
	n->sub_head->accept(this);

	if (n->decs != NULL)
		n->decs->accept(this);
	// cout << "\nCompound Stmt -> \n";
	n->comp_stmt->accept(this);
}

void TypeVisitor::Visit(Subprogram_Declarations *n)
{
	// cout << "Subprogram Declarations List:: \n";

	for (int i = 0; i < n->decs->size(); i++)
	{
		// cout << "Subprogram Declaration number " << i << " ::\n";
		cout << "\n\nVisiting Subprogram " << i << "\n\n";

		n->decs->at(i)->accept(this);
	}

	cout << "\n\nVisiting the main program\n\n";
}

void TypeVisitor::Visit(Program *n)
{
	// cout << "Program (root):: \nIdent -> \n";
	n->id->accept(this);
	// cout << "\nDeclarations -> \n";
	n->decs->accept(this);
	// cout << "\nSubprogram Declarations -> \n";
	n->sub_decs->accept(this);
	// cout << "\nCompound Stmt -> \n";
	n->comp_stmt->accept(this);
}

void TypeVisitor::Visit(Add_expression *n)
{
	// cout<<"--------------------------------------------------------------------I am in Type Visitor for Add Expression:\n";
	// cout << "Add Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	// cout << "\nRight Expr -> \n";
	n->expression2->accept(this);

	// types: int , real

	string left = n->expression1->type;
	string right = n->expression2->type;

	// cout<<"--------------------------------------------------------------------Left :"<<n->expression1<<" at: "<<n->column<<" , "<<n->line<<"\n";
	// cout<<"--------------------------------------------------------------------Right :"<<n->expression2<<" at: "<<n->column<<" , "<<n->line<<"\n";

	// cout<<"--------------------------------------------------------------------Left Type:"<<n->expression1->type<<" at: "<<n->column<<" , "<<n->line<<"\n";
	// cout<<"--------------------------------------------------------------------Right Type:"<<n->expression2->type<<" at: "<<n->column<<" , "<<n->line<<"\n";
	if (left == "INT" && right == "INT")
	{
		n->type = "INT";
	}
	else if (left == "RL" && right == "RL")
	{
		n->type = "RL";
	}
	else if ((left == "INT" && right == "RL") || (left == "RL" && right == "INT"))
	{
		n->type = "RL";
		n->expression1->type = "RL";
		n->expression2->type = "RL";
	}
	else
	{
		cout << "Type Error: line " << n->line << ", column " << n->column << "\n\n";
	}
	// cout<<"--------------------------------------------------------------------Left Type:"<<n->expression1->type<<" at: "<<n->column<<" , "<<n->line<<"\n";
	// cout<<"--------------------------------------------------------------------Right Type:"<<n->expression2->type<<" at: "<<n->column<<" , "<<n->line<<"\n";
}

void TypeVisitor::Visit(Minus_expression *n)
{
	// cout << "Minus Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	// cout << "\nRight Expr -> \n";
	n->expression2->accept(this);

	// types: int , real

	string left = n->expression1->type;
	string right = n->expression2->type;

	if (left == "INT" && right == "INT")
	{
		n->type = "INT";
	}
	else if (left == "RL" && right == "RL")
	{
		n->type = "RL";
	}
	else if ((left == "INT" && right == "RL") || (left == "RL" && right == "INT"))
	{
		n->type = "RL";
		n->expression1->type = "RL";
		n->expression2->type = "RL";
	}
}

void TypeVisitor::Visit(Mul_expression *n)
{
	// cout << "Multiplication Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	// cout << "\nRight Expr -> \n";
	n->expression2->accept(this);

	// types: int , real

	string left = n->expression1->type;
	string right = n->expression2->type;

	if (left == "INT" && right == "INT")
	{
		n->type = "INT";
	}
	else if (left == "RL" && right == "RL")
	{
		n->type = "RL";
	}
	else if ((left == "INT" && right == "RL") || (left == "RL" && right == "INT"))
	{
		n->type = "RL";
		n->expression1->type = "RL";
		n->expression2->type = "RL";
	}
}

void TypeVisitor::Visit(Divide_expression *n)
{
	// cout << "Division Expression:: \nLeft Expr -> \n";
	n->expression1->accept(this);
	// cout << "\nRight Expr -> \n";
	n->expression2->accept(this);
	// types : int, real

	string left = n->expression1->type;
	string right = n->expression2->type;

	n->type = "RL";
}

/************************ Code Visitors ************************/

void CodeVisitor::Visit(Node *n)
{
}

void CodeVisitor::Visit(Ident *n)
{
}

void CodeVisitor::Visit(Ident_List *n)
{
}

void CodeVisitor::Visit(Int_Num *n)
{
}

void CodeVisitor::Visit(Real_Num *n)
{
}

void CodeVisitor::Visit(Standard_Type *n)
{
}

void CodeVisitor::Visit(Type *n)
{
}

void CodeVisitor::Visit(Parameter *n)
{
	// TODO BOOLEAN
	string ptype;

	if (n->type->std_type->type == 'I')
		ptype = "i";

	if (n->type->std_type->type == 'R')
		ptype = "f";

	string pkind;

	if (n->ident_list == NULL || n->ident_list->idents->size() == 0)
		return;

	if (n->ident_list->idents->front()->symbol->kind == 1)
		pkind = "g";

	if (n->ident_list->idents->front()->symbol->kind == 2)
		pkind = "l";

	string def_value = (ptype == "i" ? "0" : "0.0");

	for (int i = 0; i < n->ident_list->idents->size(); i++)
	{
		int pointer;
		if (pkind == "g")
		{
			gp--;
			pointer = gp;
		}
		else
		{
			fp++;
			pointer = fp;
		}

		n->ident_list->idents->at(i)->symbol->location = pointer;
		if (n->type->is_array)
		{
			int size = n->type->last - n->type->first + 1;
			vout << "alloc " << size << "\n";
		}
		else
		{
			vout << "push" << ptype << " " << def_value << "\n";
		}
		vout << "store" << pkind << " " << pointer << "\n";
		vout << "push" << pkind << " " << pointer << "\n";
	}
}

void CodeVisitor::Visit(Declaration *n)
{
	n->param->accept(this);
}

void CodeVisitor::Visit(Declarations *n)
{
	int s = n->decs->size();
	for (int i = 0; i < s; i++)
	{
		n->decs->at(i)->accept(this);
	}
}

void CodeVisitor::Visit(Local_Declaration *n)
{
	n->param->accept(this);
}

void CodeVisitor::Visit(Local_Declarations *n)
{
	int s = n->decs->size();
	for (int i = 0; i < s; i++)
	{
		n->decs->at(i)->accept(this);
	}
}

void CodeVisitor::Visit(Expression *n)
{
}

void CodeVisitor::Visit(Int_Expression *n)
{
	vout << "pushi " << n->value->value << endl;
}

void CodeVisitor::Visit(Real_Expression *n)
{
	vout << "pushf " << n->value->value << endl;
}

void CodeVisitor::Visit(Boolean_Expression *n)
{
	cout << "\n\nBOOLEAN\n\n";
}

void CodeVisitor::Visit(Ident_Expression *n)
{
	if (n->ident->symbol->kind == 1)
	{
		vout << "pushg " << n->ident->symbol->location << "\n";
	}
	else if (n->ident->symbol->kind == 2)
	{
		vout << "pushl " << n->ident->symbol->location << "\n";
	}
}

void CodeVisitor::Visit(Function_Expression *n)
{

	string name = n->ident->name;
	Subprogram_Declaration sd = funcs.at(name);

	if (n->type == "INT")
	{
		vout << "pushi 0\n";
		vout << "storeg " << --gp << "\n";
		vout << "pushi 0\n";
		vout << "storel " << ++fp << "\n";
	}
	else if (n->type == "RL")
	{
		vout << "pushf 0.0\n";
		vout << "storeg " << --gp << "\n";
		vout << "pushi 0\n";
		vout << "storel " << ++fp << "\n";
	}
	else if (n->type == "BOOL")
	{
		vout << "pushi 0\n";
		vout << "storeg " << --gp << "\n";
		vout << "pushi 0\n";
		vout << "storel " << ++fp << "\n";
	}

	n->expr_lst->accept(this);

	string func_key = "";

	symbolTable->lookUpFunction(n->ident, n->expr_lst, 1, func_key);

	string func_label = "";

	for (int i = 0; i < func_key.size(); i++)
	{
		if (func_key[i] == '@')
			func_label.push_back('_');
		else
		{
			func_label.push_back(func_key[i]);
		}
	}

	if (visited.count(func_label) == 0)
	{

		visited.insert({func_label, true});

		sd.sub_head->args->accept(this);

		vout << "pusha " << func_label << "\n"
			 << "call\n"
			 << "jump "
			 << "END_" + func_label << "\n"
			 << func_label + ":\n";

		for (int i = 0; i < sd.comp_stmt->optional_statements->statement_list->stmts->size(); i++)
		{
			sd.comp_stmt->optional_statements->statement_list->stmts->at(i)->accept(this);
		}

		vout << "return\n";

		vout
			<< "END_" + func_label + ":"
			<< "\n";
	}

	else
	{
		vout << "pusha " << func_label << "\n"
			 << "call\n";
	}

	// vout << "pushg " << gp << "\n";
	// vout << "storel " << fp << "\n";

	// vout << "pop " << n->expr_lst->exprs->size() - 1 << "\n";

	// vout << "pushl " << fp << "\n";

	vout << "pop " << n->expr_lst->exprs->size() - 1 << "\n";

	vout << "pushg " << gp << "\n";
}

void CodeVisitor::Visit(Expression_Expression *n)
{
	n->expression->accept(this);
}

void CodeVisitor::Visit(Expression_List *n)
{
	for (int i = 0; i < n->exprs->size(); i++)
	{
		n->exprs->at(i)->accept(this);
	}
}

void CodeVisitor::Visit(Binary_expression *n)
{

	n->expression1->accept(this);
	n->expression2->accept(this);

	string ptype;
	if (n->expression1->type == "INT")
		ptype = "";

	else if (n->expression1->type == "RL")
		ptype = "f";

	string opreation;

	if (n->op->op == ">")
		opreation = "sup";
	else if (n->op->op == ">=")
		opreation = "supeq";
	else if (n->op->op == "<")
		opreation = "inf";
	else if (n->op->op == "<=")
		opreation = "infeq";

	opreation = ptype + opreation;

	vout << opreation << "\n";
}

void CodeVisitor::Visit(Logical_expression *n)
{
	cout << "\n\nLOGICAL\n\n";
}

void CodeVisitor::Visit(Binary_opreator *n)
{
}

void CodeVisitor::Visit(Logical_opreator *n)
{
}

void CodeVisitor::Visit(Not_Expression *n)
{
	cout << "\n\nNOT\n\n";
}
void CodeVisitor::Visit(Array_expression *n)
{

	int loc = n->name->symbol->location;
	if (n->name->symbol->kind == 1)
	{ // 1 is global
		vout << "pushg " << loc << "\n";
	}
	else
	{ // 2 is local
		vout << "pushl " << loc << "\n";
	}

	vout << "load " << ((Int_Expression *)n->index)->value->value << "\n";
}

void CodeVisitor::Visit(Statement *n)
{
}

void CodeVisitor::Visit(Statement_List *n)
{
	int s = n->stmts->size();
	for (int i = 0; i < s; i++)
	{
		n->stmts->at(i)->accept(this);
	}
}

void CodeVisitor::Visit(If_Statement *n)
{

	if (dynamic_cast<Binary_expression *>(n->expression) != nullptr)
	{
		std::cout << "\n\nBE\n\n"
				  << std::endl;
	}

	n->expression->accept(this);

	// cout << "HERE\n";

	string end = "END_IF";

	end += std::to_string(ifCount++);

	vout << "jz " << end << "\n";

	n->statement->accept(this);
	vout << end << ":\n";
}

void CodeVisitor::Visit(While_Statement *n)

{
	string start = "START_WHILE" + std::to_string(whileCount);
	string end = "END_WHILE" + std::to_string(whileCount++);

	vout << start << ":\n";

	n->expression->accept(this);

	vout << "jz " << end << "\n";

	n->statement->accept(this);

	vout << "jump " << start << "\n";
	vout << end << ":\n";
}

void CodeVisitor::Visit(If_Else_Statement *n)
{

	n->expression->accept(this);

	string end = "END_IF";
	string elseif = "ELSE_IF";

	end += std::to_string(ifCount);
	elseif += std::to_string(ifCount++);

	vout << "jz " << elseif << "\n";

	n->statement1->accept(this);

	vout << elseif << ":\n";

	n->statement2->accept(this);

	vout << end << ":\n";
}

void CodeVisitor::Visit(Compound_Statement *n)
{
	n->optional_statements->accept(this);
}

void CodeVisitor::Visit(Optional_Statements *n)
{
	if (n->statement_list != NULL)
		n->statement_list->accept(this);
}

void CodeVisitor::Visit(Return_Statement *n)
{
	// TODO return certain value

	n->e->accept(this);

	vout << "storeg " << gp << "\n";

	vout
		<< "return\n";
}

void CodeVisitor::Visit(Variable_Statement *n)
{

	if (n->variable->expr != NULL)
	{
		int loc = n->variable->id->symbol->location;
		if (n->variable->id->symbol->kind == 1)
		{ // 1 is global
			vout << "pushg " << loc << "\n";
		}
		else
		{ // 2 is local
			vout << "pushl " << loc << "\n";
		}

		n->expression->accept(this);

		vout << "store " << ((Int_Expression *)n->variable->expr)->value->value << "\n";

		return;
	}

	n->expression->accept(this);
	int loc = n->variable->id->symbol->location;

	if (n->variable->id->symbol->kind == 1)
	{ // 1 is global
		vout << "storeg " << loc << "\n";
	}
	else
	{ // 2 is local
		vout << "storel " << loc << "\n";
	}
}

void CodeVisitor::Visit(Parameter_List *n)
{

	// int pls = n->params->size();
	// for (int i = 0; i < pls; i++)
	// {
	// 	n->params->at(i)->accept(this);
	// }
}

void CodeVisitor::Visit(Arguments *n)
{
	int counter = -1;
	for (int i = n->param_lst->params->size() - 1; i >= 0; i--)
	{
		for (int j = n->param_lst->params->at(i)->ident_list->idents->size() - 1; j >= 0; j--)
		{
			n->param_lst->params->at(i)->ident_list->idents->at(j)->symbol->location = counter--;
		}
	}
}

void CodeVisitor::Visit(Procedure_Statement *n)
{
	string name = n->id->name;
	Subprogram_Declaration sd = funcs.at(name);

	n->expr_lst->accept(this);

	string proc_key = "";

	symbolTable->lookUpFunction(n->id, n->expr_lst, 2, proc_key);

	string proc_label = "";

	for (int i = 0; i < proc_key.size(); i++)
	{
		if (proc_key[i] == '@')
			proc_label.push_back('_');
		else
		{
			proc_label.push_back(proc_key[i]);
		}
	}

	if (visited.count(proc_label) == 0)
	{

		visited.insert({proc_label, true});

		sd.sub_head->args->accept(this);

		vout << "pusha " << proc_label << "\n"
			 << "call\n"
			 << "jump "
			 << "END_" + proc_label << "\n"
			 << proc_label + ":\n";

		for (int i = 0; i < sd.comp_stmt->optional_statements->statement_list->stmts->size(); i++)
		{
			sd.comp_stmt->optional_statements->statement_list->stmts->at(i)->accept(this);
		}

		vout << "return\n";

		vout
			<< "END_" + proc_label + ":"
			<< "\n";
	}

	else
	{
		vout << "pusha " << proc_label << "\n"
			 << "call\n";
	}

	vout << "pop " << n->expr_lst->exprs->size() << "\n";
}

void CodeVisitor::Visit(Variable *n)
{
}

void CodeVisitor::Visit(Subprogram_Head *n)
{
}

void CodeVisitor::Visit(Subprogram_Declaration *n)
{
}

void CodeVisitor::Visit(Subprogram_Declarations *n)
{
}

void CodeVisitor::Visit(Program *n)
{
	vout << "start\n";
	// int n_of_functions = n->sub_decs->decs->size();
	// for (int i = 0; i < n_of_functions; i++)
	// {
	// 	n->sub_decs->decs->at(i)->sub_head->args->param_lst->accept(this);
	// }

	n->decs->accept(this);
	n->comp_stmt->accept(this);

	vout << "stop\n";

	vout.close();
}

void CodeVisitor::Visit(Add_expression *n)
{

	n->expression1->accept(this);
	n->expression2->accept(this);
	if (n->type == "INT")
	{
		vout << "add\n";
	}
	if (n->type == "RL")
	{
		vout << "fadd\n";
	}
}

void CodeVisitor::Visit(Minus_expression *n)
{
	n->expression1->accept(this);
	n->expression2->accept(this);
	if (n->type == "INT")
	{
		vout << "sub\n";
	}
	if (n->type == "RL")
	{
		vout << "fsub\n";
	}
}

void CodeVisitor::Visit(Mul_expression *n)
{
	n->expression1->accept(this);
	n->expression2->accept(this);
	if (n->type == "INT")
	{
		vout << "mul\n";
	}
	if (n->type == "RL")
	{
		vout << "fmul\n";
	}
}

void CodeVisitor::Visit(Divide_expression *n)
{
	n->expression1->accept(this);
	n->expression2->accept(this);
	if (n->expression1->type == "INT")
	{
		vout << "div\n";
	}
	if (n->expression1->type == "RL")
	{
		vout << "fdiv\n";
	}
}

Symbol::Symbol(string n, int k, char t, bool is_array)
{
	this->name = n;
	this->type = t;
	this->kind = k;
	this->is_array = is_array;
	if (is_array)
		this->type += 1;
}

Symbol::Symbol(string n, int k, char t, bool is_array, int f, int l)
{
	this->name = n;
	this->type = t;
	this->kind = k;
	this->is_array = is_array;
	if (is_array)
		this->type += 1;
	this->first = f;
	this->last = l;
}

Scope::Scope()
{
	this->hashTab = new HashTab;
}
SymbolTable::SymbolTable()
{
	this->scopes = new vector<Scope *>;
	this->scopes->push_back(new Scope());
	this->current = this->scopes->at(0);
}
bool SymbolTable::AddSymbol(Ident *ident, int kind, char type, bool is_array)
{

	Symbol *s = new Symbol(ident->name, kind, type, is_array);
	string key_type = (kind == 1 ? "g" : "l");
	string key = key_type + ident->name;
	Symbol *temp = this->current->hashTab->GetMember(key);

	if (temp == NULL)
	{
		this->current->hashTab->AddKey(key, s);
		ident->symbol = s;
		return true;
	}
	else
	{
		cout << "\n\nError:: variable redefinition " << ident->name << ", line " << ident->line << ", col " << ident->column << "\n\n";
		return false;
	}
}

bool SymbolTable::AddSymbol(Ident *ident, int kind, char type, bool is_array, int first, int last)
{

	Symbol *s = new Symbol(ident->name, kind, type, is_array, first, last);
	string key_type = (kind == 1 ? "g" : "l");
	string key = key_type + ident->name;
	Symbol *temp = this->current->hashTab->GetMember(key);

	if (temp == NULL)
	{
		this->current->hashTab->AddKey(key, s);
		ident->symbol = s;
		return true;
	}
	else
	{
		cout << "\n\nError:: variable redefinition " << ident->name << ", line " << ident->line << ", col " << ident->column << "\n\n";
		return false;
	}
}

bool SymbolTable::AddFunction(Ident *ident, Arguments *args, int kind, char type, bool is_array) // k = 1 -> function else procedure
{
	Symbol *s = new Symbol(ident->name, kind, type, is_array);
	string key;
	if (kind == 1)
		key = "f" + ident->name;
	else
		key = "p" + ident->name;

	// int n = args->param_lst->params->size();

	int n;

	if (args->param_lst->params != NULL)
		n = args->param_lst->params->size();
	else
		n = 0;

	for (int i = 0; i < n; i++)
	{
		key += "@";
		key.push_back(args->param_lst->params->at(i)->ident_list->idents->front()->symbol->type);
		// key.push_back(args->param_lst->params->at(i)->type->std_type->type);
		key += (std::to_string(args->param_lst->params->at(i)->ident_list->idents->size()));
	}

	Symbol *temp = this->scopes->at(0)->hashTab->GetMember(key);
	if (temp == NULL)
	{
		this->scopes->at(0)->hashTab->AddKey(key, s);
		ident->symbol = s;
		return true;
	}
	else
	{
		cout << "\n\nError:: function redefinition " << ident->name << ", line " << ident->line << ", col " << ident->column << "\n\n";
		return false;
	}
}

Symbol *SymbolTable::lookUpSymbol(Ident *ident)
{
	// Assume local variable
	string key = "l" + ident->name;
	Symbol *sym = this->current->hashTab->GetMember(key);
	if (sym != NULL)
	{
		ident->symbol = sym;
		return sym;
	}
	else
	{
		key = "g" + ident->name;
		Symbol *sym = this->scopes->at(0)->hashTab->GetMember(key);
		if (sym != NULL)
		{
			ident->symbol = sym;
			return sym;
		}
		else
		{
			// cout << "\n\nError:: Undeclared variable " << ident->name << ", line " << ident->line << ", col " << ident->column << "\n\n";
			return nullptr;
		}
	}
}

Symbol *SymbolTable::lookUpFunction(Ident *ident, Expression_List *exp_lst, int kind, string &k)
{
	string key;
	if (kind == 1)
		key = "f" + ident->name;
	else
		key = "p" + ident->name;

	int n;

	if (exp_lst != NULL && exp_lst->exprs != NULL)
		n = exp_lst->exprs->size();
	else
		n = 0;

	char lst = '?';
	int lst_num = 0;

	for (int i = 0; i < n; i++)
	{
		if (lst == '?')
		{
			lst = exp_lst->exprs->at(i)->type.at(0);
			if (lst == '*')
			{
				lst = exp_lst->exprs->at(i)->type.at(1) + 1;
			}
			lst_num += 1;
		}
		else
		{

			char nw = exp_lst->exprs->at(i)->type.at(0);
			if (nw == '*')
			{
				nw = exp_lst->exprs->at(i)->type.at(1) + 1;
			}

			if (lst == nw)
			{
				lst_num += 1;
			}
			else
			{
				key += "@";
				key.push_back(lst);
				key += std::to_string(lst_num);
				lst_num = 1;
				lst = nw;
			}
		}
	}
	if (lst_num >= 1)
	{
		key += "@";
		key.push_back(lst);
		key += std::to_string(lst_num);
	}

	Symbol *sym = this->scopes->at(0)->hashTab->GetMember(key);

	if (sym != NULL)
	{
		ident->symbol = sym;
		string str = (kind == 1 ? "function" : "procedure");
		cout << "\n\nMatched " << str << " correctly, line " << ident->line << "\n";
		k = key;
		return sym;
	}
	else
	{
		cout << "\n\nError:: No matching function " << ident->name << " with the same params, line " << ident->line << "\n\n";
		k = "";
		return nullptr;
	}
}

void SymbolTable::startScope()
{
	this->scopes->push_back(new Scope());
	this->current = this->scopes->back();
}

void SymbolTable::endScope()
{
	this->current = this->scopes->at(0);
}