#pragma once
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

class Node;
class Ident;
class Ident_List;
class Int_Num;
class Real_Num;
class Standard_Type;
class Type;
class Parameter;
class Declaration;
class Declarations;

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

class Ident_List : public Node
{
public:
	vector<Ident *> *idents;
	Ident_List(int, int);
	Ident_List(Ident *, int, int);
	void AddIdent(Ident *);
};

class Int_Num : public Node
{
public:
	int value;
	Int_Num(int, int, int);
};

class Real_Num : public Node
{
public:
	float value;
	Real_Num(float, int, int);
};

class Standard_Type : public Node
{
public:
	char type;
	Standard_Type(char, int, int);
};

class Type : public Node
{
public:
	bool is_array;
	int first;
	int last;
	Standard_Type *std_type;
	Type(Standard_Type *, int, int, int, int);
	Type(Standard_Type *, int, int);
};

class Parameter : public Node
{
public:
	Ident_List *ident_list;
	Type *type;
	Parameter(Ident_List *, Type *, int, int);
};

class Parameter_List : public Node
{
public:
	vector<Parameter *> *params;
	Parameter_List(int, int);
	Parameter_List(Parameter *, int, int);
	void AddParam(Parameter *);
};

class Declaration : public Node
{
public:
	Parameter *param;
	Declaration(Parameter *, int, int);
};

class Declarations : public Node
{
public:
	vector<Declaration *> *decs;
	Declarations(int, int);
	Declarations(Declaration *, int, int);
	void AddDec(Declaration *);
};