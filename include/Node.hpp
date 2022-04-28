#pragma once

#include <iostream>
#include <vector>

using std::size_t;
using std::vector;

class Node {
  protected:
	Node* parent;
	size_t depth;
	vector<Node*> children;

  public:
	Node(Node* parent);

	void setChildren(vector<Node*> children);
	void setChildren(Node* arg1, Node* arg2, Node* arg3, Node* arg4, Node* arg5,
	                 Node* arg6, Node* arg7, Node* arg8, Node* arg9,
	                 Node* arg10);

	~Node();
};
