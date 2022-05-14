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