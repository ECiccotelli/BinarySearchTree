#include "BinaryTree.h"
#include <iostream>
using namespace std;

//---PUBLIC FUNCTIONS---
BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroy(root);
}

bool BinaryTree::search(int data)
{
	return search(data, root);
}

void BinaryTree::insert(int data)
{
	insert(data, root);
}

void BinaryTree::traverseInOrder()
{
	traverseInOrder(root);
}

void BinaryTree::traversePreOrder()
{
	traversePreOrder(root);
}

void BinaryTree::traversePostOrder()
{
	traversePostOrder(root);
}

int BinaryTree::countNodes()
{
	return countNodes(root);
}

int BinaryTree::treeHeight()
{
	return treeHeight(root);
}

int BinaryTree::countLeaf()
{
	return countLeaf(root);
}

//---PRIVATE FUNCTIONS---
void BinaryTree::destroy(Node *tempNode)
{
	if (tempNode)
	{
		destroy(tempNode->left);
		destroy(tempNode->right);
		delete tempNode;
	}
}

bool BinaryTree::search(int data, Node *tempNode)
{
	if (!tempNode)
		return false;
	if (data == tempNode->data)
		return true;
	else if (data < tempNode->data)
		return search(data, tempNode->left);
	else
		return search(data, tempNode->right);
}

void BinaryTree::insert(int data, Node* &tempNode)
{
	if (!tempNode)
	{
		Node *newNode = new Node;
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		tempNode = newNode;
	}
	else if (data < tempNode->data)
		insert(data, tempNode->left);
	else
		insert(data, tempNode->right);
}

void BinaryTree::traverseInOrder(Node *tempNode)
{
	if (tempNode)
	{
		traverseInOrder(tempNode->left); // left
		cout << tempNode->data << endl; // root
		traverseInOrder(tempNode->right);; // right
	}
}

void BinaryTree::traversePreOrder(Node *tempNode)
{
	if (tempNode)
	{
		cout << tempNode->data << endl; // root
		traversePreOrder(tempNode->left); // left
		traversePreOrder(tempNode->right);; // right
	}
}

void BinaryTree::traversePostOrder(Node *tempNode)
{
	if (tempNode)
	{
		traversePostOrder(tempNode->left); // left
		traversePostOrder(tempNode->right);; // right
		cout << tempNode->data << endl; // root
	}
}

//Count Number of Nodes
//Private Function
int BinaryTree::countNodes(Node *tempNode)
{
	if (tempNode)
		return 1 + countNodes(tempNode->left) + countNodes(tempNode->right);
	return 0;
}



//Count Number of Leaves
//PUBLIC:

//PRIVATE
int BinaryTree::countLeaf(Node* tempNode)
{
	if (tempNode)
	{
		if (!(tempNode->left) && !(tempNode->right))
			return 1;
		else
			return countLeaf(tempNode->left) + countLeaf(tempNode->right);

	}
	return 0;
}



//PRIVATE
int BinaryTree::treeHeight(Node *tempNode)
{
	//Assuming Tree with 1 Node is of height 1
	if (tempNode)
	{
		int left = treeHeight(tempNode->left);
		int right = treeHeight(tempNode->right);
		if (left > right)
			return 1 + left;
		else
			return 1 + right;

	}
	return 0;
}

