#include <iostream>
#include "example 21-2-IntBinaryTree.h"
using namespace std;

void IntBinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;               // Insert the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);  // Search the left branch.
	else
		insert(nodePtr->right, newNode); // Search the right branch.
}

void IntBinaryTree::insertNode(int num)
{
	TreeNode* newNode = nullptr; // Pointer to a new node.

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

//***************************************************************
// The displayInOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//***************************************************************

void IntBinaryTree::displayInOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void IntBinaryTree::displayPreOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//*****************************************************************
// The displayPostOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via postorder traversal. *
//*****************************************************************

void IntBinaryTree::displayPostOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}