#include "ast.h"
#include <utility>

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

Subprogram_Declaration::Subprogram_Declaration(Subprogram_Head *s, Compound_Statement *cs, int l, int c) : Node(l, c)
{
	this->sub_head = s;
	this->comp_stmt = cs;
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

Binary_opreator::Binary_opreator(string o, int lin, int col) : Node(lin, col)
{
	this->op = o;
}

void Binary_opreator::accept(NodeVisitor *nv)
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

void PrintVisitor::Visit(Ident_Expression *n)
{
	cout << "Ident Expression:: \nIdent -> \n";
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

void PrintVisitor::Visit(Binary_opreator *n)
{
	cout << "Binary Opreator:: \nopreator -> " << n->op << "\n";
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
	cout << "Subprogram Declaration:: \nSubHead -> \n";
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
	string key = "l" + ident->name;
	Symbol *temp = this->current->hashTab->GetMember(key);
	if (temp == NULL)
	{
		this->current->hashTab->AddKey(key, s);
		ident->symbol = s;
		return true;
	}
	else
	{
		cout << "**************************************************Redefinition variable " << ident->name << " " << type << "\n";
		return false;
	}
}

bool SymbolTable::AddFunction(Ident *ident, Arguments *args, int kind, char type) // k = 0 -> function else procedure
{
	Symbol *s = new Symbol(ident->name, kind, type);
	string key = "f" + ident->name;
	int n = args->param_lst->params->size();

	for (int i = 0; i < n; i++)
	{
		key += ("@" + args->param_lst->params->at(i)->type->std_type->type);
	}

	Symbol *temp = this->current->hashTab->GetMember(key);
	if (temp == NULL)
	{
		this->current->hashTab->AddKey(key, s);
		ident->symbol = s;
		return true;
	}
	else
	{
		cout << "**************************************************Redefinition variable " << ident->name << " " << type << "\n";
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
		Symbol *sym = this->scopes->at(this->scopes->size() - 2)->hashTab->GetMember(key);
		if (sym != NULL)
		{
			ident->symbol = sym;
			return sym;
		}
		else
		{
			cout << "**************************************************Undeclared variable " << ident->name << "\n";
			return NULL;
		}
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