#include "example 21-1-IntBinaryTree.h"

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