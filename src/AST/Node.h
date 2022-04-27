using namespace std;

class Node {
  protected:
	Node* parent;
	size_t depth;
	vector<Node*> children;

  public:
	Node(Node* parent)
	    : parent(parent), depth((parent != nullptr) ? parent->depth + 1 : 0) {
		this.children = new vector<Node*>();
	};

	void setChildren(vector<Node*> children) { this->children = children; }
	void setChildren(Node* arg1 = nullptr, Node* arg2 = nullptr,
	                 Node* arg3 = nullptr, Node* arg4 = nullptr,
	                 Node* arg5 = nullptr, Node* arg6 = nullptr,
	                 Node* arg7 = nullptr, Node* arg8 = nullptr,
	                 Node* arg9 = nullptr, Node* arg10 = nullptr);

	~Node();
};

Node::~Node() {}

void Node::setChildren(Node* arg1 = nullptr, Node* arg2 = nullptr,
                       Node* arg3 = nullptr, Node* arg4 = nullptr,
                       Node* arg5 = nullptr, Node* arg6 = nullptr,
                       Node* arg7 = nullptr, Node* arg8 = nullptr,
                       Node* arg9 = nullptr, Node* arg10 = nullptr) {
	if (arg1 != nullptr) {
		children.push_back(arg1);
	} else
		return;
	if (arg2 != nullptr) {
		children.push_back(arg2);
	} else
		return;
	if (arg3 != nullptr) {
		children.push_back(arg3);
	} else
		return;
	if (arg4 != nullptr) {
		children.push_back(arg4);
	} else
		return;
	if (arg5 != nullptr) {
		children.push_back(arg5);
	} else
		return;
	if (arg6 != nullptr) {
		children.push_back(arg6);
	} else
		return;
	if (arg7 != nullptr) {
		children.push_back(arg7);
	} else
		return;
	if (arg8 != nullptr) {
		children.push_back(arg8);
	} else
		return;
	if (arg9 != nullptr) {
		children.push_back(arg9);
	} else
		return;
	if (arg10 != nullptr) {
		children.push_back(arg10);
	} else
		return;
}