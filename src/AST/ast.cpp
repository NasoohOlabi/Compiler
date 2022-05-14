#include "ast.h"

Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = NULL;
}