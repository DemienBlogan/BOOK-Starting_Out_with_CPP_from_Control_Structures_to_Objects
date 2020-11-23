/*
4. Tree Height
Write a member function, for either the template you designed in Programming
Challenge 1 or the IntBinaryTree class, that returns height of the tree. The
height of the tree is number of levels it contains. For example, the tree shown
in Figure 21-10 has three levels.

Demonstrate the function in a driver program
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	BinaryTree<int> tree;

	for (size_t i = 0; i < 5; i++)
	{
		int value = std::rand() % 100;
		tree.Insert(value);
	}

	tree.DisplayInOrder();
	std::cout << std::endl;

	std::cout << "Nodes count = " << tree.GetNodesCount() << std::endl;
	std::cout << "Nodes count = " << tree.GetLeafNodesCount() << std::endl;
	std::cout << "Tree Height = " << tree.GetHeight() << std::endl;

	return 0;
}