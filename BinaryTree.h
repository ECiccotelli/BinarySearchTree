struct Node
{
	int data;
	Node *left;
	Node *right;
};

class BinaryTree
{
private:
	Node *root;
	void destroy(Node*);
	bool search(int, Node*);
	void insert(int, Node*&);
	void traverseInOrder(Node*);
	void traversePreOrder(Node*);
	void traversePostOrder(Node*);
	int countNodes(Node *);
	int countLeaf(Node*);
	int treeHeight(Node *);
public:
	BinaryTree();
	~BinaryTree();
	bool search(int);
	void insert(int);
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
	int countNodes();
	int countLeaf();
	int treeHeight();
};