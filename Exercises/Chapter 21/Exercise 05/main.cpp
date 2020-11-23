/*
5. Tree Width
Write a member function, for either the template you designed in Programming
Challenge 1 or the IntBinaryTree class, that returns the width of the tree. The
width of the tree is the largest number of nodes in the same level. Demonstrate the
function in a driver program.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	BinaryTree<int> tree;

	for (size_t i = 0; i < 10; i++)
	{
		int value = std::rand() % 100;
		tree.Insert(value);
	}

	tree.DisplayInOrder();
	std::cout << std::endl;

	std::cout << "Nodes count = " << tree.GetNodesCount() << std::endl;
	std::cout << "Nodes count = " << tree.GetLeafNodesCount() << std::endl;
	std::cout << "Tree Height = " << tree.GetHeight() << std::endl;
	std::cout << "Tree Width = " << tree.GetWidth() << std::endl;

	return 0;
}