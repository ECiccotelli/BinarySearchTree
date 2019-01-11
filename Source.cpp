#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{

	BinaryTree B;

	B.insert(5);
	B.insert(4);
	B.insert(7);
	B.insert(2);

	cout << "In order traversal: " << endl;
	B.traverseInOrder();

	cout << "Number of nodes: " << B.countNodes() << endl;
	cout << "Number of leaves: " << B.countLeaf() << endl;
	cout << "Height of tree: " << B.treeHeight() << endl;



	return 0;
}