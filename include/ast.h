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