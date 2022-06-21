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
}

void Int_Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Real_Expression::Real_Expression(Real_Num *v, int l, int c) : Expression(l, c)
{
	this->value = v;
}

void Real_Expression::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Boolean_Expression::Boolean_Expression(bool v, int l, int c) : Expression(l, c)
{
	this->value = v;
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

If_Statement::If_Statement(Expression *e, Statement *s, int l, int c) : Statement(l, c)
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

If_Else_Statement::If_Else_Statement(Expression *e, Statement *s1, Statement *s2, int l, int c) : Statement(l, c)
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

While_Statement::While_Statement(Expression *e, Statement *s, int l, int c) : Statement(l, c)
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
}

Variable::Variable(Ident *i, Expression *e, int l, int c) : Node(l, c)
{
	this->id = i;
	i->father = this;
	this->expr = e;
	e->father = this;
}

void Variable::accept(NodeVisitor *nv)
{
	nv->Visit(this);
}

Subprogram_Head::Subprogram_Head(Arguments *a, int l, int c) : Node(l, c)
{
	this->args = a;
	this->is_function = false;
	if (a != nullptr)
		a->father = this;
}

Subprogram_Head::Subprogram_Head(Arguments *a, Standard_Type *s, int l, int c) : Node(l, c)
{
	this->args = a;
	this->std_type = s;
	this->is_function = true;
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
		if (t == 'I')
			n->type = "INT";
		if (t == 'R')
			n->type = "RL";
		if (t == 'B')
			n->type = "BOOL";
	}
	else
	{
		cout << "NULL Ident " << n->ident->name << "\n\n";
	}
}

void TypeVisitor::Visit(Function_Expression *n)
{

	if (n->expr_lst != NULL)
	{
		n->expr_lst->accept(this);
	}

	Symbol *s = symbolTable->lookUpFunction(n->ident, n->expr_lst, 1);

	if (s == NULL)
		cout << "NULL Function Symbol\n";

	n->symbol = s;

	char t = n->symbol->type;
	if (t == 'I')
		n->type = "INT";
	if (t == 'R')
		n->type = "RL";
	if (t == 'B')
		n->type = "BOOL";
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
		cout << "Binary Expression type checked correctly, line " << n->line << endl;
	else
	{
		cout << "Type Error: line " << n->line << ", column " << n->column << endl;
		cout << "left:: " << n->expression1->type << " right:: " << n->expression2->type;
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
		cout << "Logical Expression type checked correctly, line " << n->line << "\n";
	else
	{
		cout << "Type Error: line " << n->line << ", column " << n->column << endl;
	}

	n->type = "BOOL";
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
	n->statement_list->accept(this);
}

void TypeVisitor::Visit(Variable_Statement *n)
{

	n->variable->accept(this);
	n->expression->accept(this);

	if (n->variable->id->symbol == NULL)
		return;

	char ident_type = n->variable->id->symbol->type;

	string expr_type = n->expression->type;

	if (ident_type == 'I' && expr_type == "INT" || ident_type == 'R' && expr_type == "RL" || ident_type == 'B' && expr_type == "BOOL")
	{
		cout << "Assignemt Type checked correctly, line " << n->line << endl;
	}
	else
	{
		cout << "Type Error: line " << n->line << ", column " << n->column << endl;
		cout << "left:: " << ident_type << "  right:: " << expr_type << endl;
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
	n->param_lst->accept(this);
}

void TypeVisitor::Visit(Procedure_Statement *n)
{
	// TODO
	//  cout << "Procedure Statement:: \nIdent -> \n";
	n->id->accept(this);
	if (n->expr_lst != NULL)
	{
		// cout << "Expr List -> \n";
		n->expr_lst->accept(this);
	}

	Symbol *s = symbolTable->lookUpFunction(n->id, n->expr_lst, 2);
}

void TypeVisitor::Visit(Variable *n)
{
	// cout << "Variable:: \nIdent -> \n";
	n->id->accept(this);
	if (n->expr)
	{
		// cout << "Expr -> \n";
		n->expr->accept(this);
	}
}

void TypeVisitor::Visit(Subprogram_Head *n)
{
	// cout << "Subprogram Head:: \nType -> " << (n->is_function ? "Function" : "Procedure");
	// cout << "\nArguments -> \n";
	n->args->accept(this);
	if (n->std_type)
	{
		// cout << "\nStd type -> \n";
		n->std_type->accept(this);
	}
}

void TypeVisitor::Visit(Subprogram_Declaration *n)
{
	if (n->decs != NULL)
		n->decs->accept(this);
	// cout << "Subprogram Declaration:: \nSubHead -> \n";
	n->sub_head->accept(this);
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
		cout << "Type Error: line " << n->line << ", column " << n->column << endl;
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
	cout << "The Type of left is: " << n->expression1->type << "\n";
	cout << "The Type of Right is: " << n->expression2->type << "\n";
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
	cout << "The Type of left is: " << n->expression1->type << "\n";
	cout << "The Type of Right is: " << n->expression2->type << "\n";
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
	cout << "The Type of left is: " << n->expression1->type << "\n";
	cout << "The Type of Right is: " << n->expression2->type << "\n";
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
	if (n->type->std_type->type == 'I')
	{
		for (int i = 0; i < n->ident_list->idents->size(); i++)
		{
			fp++;
			n->ident_list->idents->at(i)->symbol->location = fp;
			// cout << n->ident_list->idents->at(i)->name << endl;
			vout << "pushi 0"
				 << "\n";
			vout << "storel " << fp << "\n";
			vout << "pushl " << fp << "\n";
		}
	}
}

void CodeVisitor::Visit(Declaration *n)
{
}

void CodeVisitor::Visit(Declarations *n)
{
}

void CodeVisitor::Visit(Local_Declaration *n)
{
}

void CodeVisitor::Visit(Local_Declarations *n)
{
}

void CodeVisitor::Visit(Expression *n)
{
}

void CodeVisitor::Visit(Int_Expression *n)
{
}

void CodeVisitor::Visit(Real_Expression *n)
{
}

void CodeVisitor::Visit(Boolean_Expression *n)
{
}

void CodeVisitor::Visit(Ident_Expression *n)
{
}

void CodeVisitor::Visit(Function_Expression *n)
{
}

void CodeVisitor::Visit(Expression_Expression *n)
{
}

void CodeVisitor::Visit(Expression_List *n)
{
}

void CodeVisitor::Visit(Binary_expression *n)
{
}

void CodeVisitor::Visit(Logical_expression *n)
{
}

void CodeVisitor::Visit(Binary_opreator *n)
{
}

void CodeVisitor::Visit(Logical_opreator *n)
{
}

void CodeVisitor::Visit(Not_Expression *n)
{
}

void CodeVisitor::Visit(Statement *n)
{
}

void CodeVisitor::Visit(Statement_List *n)
{
}

void CodeVisitor::Visit(If_Statement *n)
{
}

void CodeVisitor::Visit(While_Statement *n)
{
}

void CodeVisitor::Visit(If_Else_Statement *n)
{
}

void CodeVisitor::Visit(Compound_Statement *n)
{
}

void CodeVisitor::Visit(Optional_Statements *n)
{
}

void CodeVisitor::Visit(Variable_Statement *n)
{
}

void CodeVisitor::Visit(Parameter_List *n)
{

	int pls = n->params->size();
	for (int i = 0; i < pls; i++)
	{
		n->params->at(i)->accept(this);
	}
}

void CodeVisitor::Visit(Arguments *n)
{
}

void CodeVisitor::Visit(Procedure_Statement *n)
{
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
	int n_of_functions = n->sub_decs->decs->size();
	for (int i = 0; i < n_of_functions; i++)
	{
		n->sub_decs->decs->at(i)->sub_head->args->param_lst->accept(this);
	}

	vout << "stop\n";
}

void CodeVisitor::Visit(Add_expression *n)
{
}

void CodeVisitor::Visit(Minus_expression *n)
{
}

void CodeVisitor::Visit(Mul_expression *n)
{
}

void CodeVisitor::Visit(Divide_expression *n)
{
}

Symbol::Symbol(string n, int k, char t)
{
	this->name = n;
	this->type = t;
	this->kind = k;
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
bool SymbolTable::AddSymbol(Ident *ident, int kind, char type)
{
	Symbol *s = new Symbol(ident->name, kind, type);
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

bool SymbolTable::AddFunction(Ident *ident, Arguments *args, int kind, char type) // k = 1 -> function else procedure
{
	Symbol *s = new Symbol(ident->name, kind, type);
	string key;
	if (kind == 1)
		key = "f" + ident->name;
	else
		key = "p" + ident->name;

	// int n = args->param_lst->params->size();

	if (kind == 1)
		cout << "localll\n\n";

	int n;

	if (args->param_lst->params != NULL)
		n = args->param_lst->params->size();
	else
		n = 0;

	for (int i = 0; i < n; i++)
	{
		key += "@";
		key.push_back(args->param_lst->params->at(i)->type->std_type->type);
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
			cout << "\n\nError:: Undeclared variable " << ident->name << ", line " << ident->line << ", col " << ident->column << "\n\n";
			return nullptr;
		}
	}
}

Symbol *SymbolTable::lookUpFunction(Ident *ident, Expression_List *exp_lst, int kind)
{
	string key;
	if (kind == 1)
		key = "f" + ident->name;
	else
		key = "p" + ident->name;

	int n;

	if (exp_lst->exprs != NULL)
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
			lst_num += 1;
		}
		else
		{
			if (lst == exp_lst->exprs->at(i)->type.at(0))
			{
				lst_num += 1;
			}
			else
			{
				key += "@";
				key.push_back(lst);
				key += std::to_string(lst_num);
				lst_num = 1;
				lst = exp_lst->exprs->at(i)->type.at(0);
			}
		}
	}
	if (lst_num >= 1)
	{
		key += "@";
		key.push_back(exp_lst->exprs->back()->type.at(0));
		key += std::to_string(lst_num);
	}

	Symbol *sym = this->scopes->at(0)->hashTab->GetMember(key);

	if (sym != NULL)
	{
		ident->symbol = sym;
		string str = (kind == 1 ? "function" : "procedure");
		cout << "\n\nMatched " << str << " correctly, line " << ident->line << "\n\n";
		return sym;
	}
	else
	{
		cout << "\n\nError:: No matching function " << ident->name << "with the same params, line " << ident->line << ", col " << ident->column << "\n\n";
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