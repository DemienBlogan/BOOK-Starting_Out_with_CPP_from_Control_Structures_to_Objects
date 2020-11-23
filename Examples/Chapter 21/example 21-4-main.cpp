// This program builds a binary tree with 5 nodes.
// The deleteNode function is used to remove tow of them.
#include <iostream>
#include "example 21-4-IntBinaryTree.h"
using namespace std;

int main()
{
	IntBinaryTree tree;

	// Insert some nodes in the tree.
	cout << "Inserting nodes. ";
	tree.insertNode(5);
	tree.insertNode(8);
	tree.insertNode(3);
	tree.insertNode(12);
	tree.insertNode(9);

	// Display the values.
	cout << "Here are the values in the tree:\n";
	tree.displayInOrder();

	// Delete the value 8.
	cout << "Deleting 8...\n";
	tree.remove(8);

	// Delete the value 12.
	cout << "Deleting 12...\n";
	tree.remove(12);

	// Display the values.
	cout << "Now, here are the nodes:\n";
	tree.displayInOrder();
	return 0;
}