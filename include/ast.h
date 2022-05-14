#pragma once

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

class Node;

class Node
{
public:
	int line;
	int column;
	Node *father;
	Node(int, int);
};