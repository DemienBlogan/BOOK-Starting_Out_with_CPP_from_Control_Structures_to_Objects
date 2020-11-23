/*
2. Node Counter
Write a member function, for either the template you designed in Programming
Challenge 1 or the IntBinaryTree class, that counts and returns the number of nodes
in the tree. Demonstrate the function in a driver program.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	BinaryTree<int> tree;

	for (size_t i = 0; i < 20; i++)
	{
		int value = std::rand() % 100;
		tree.Insert(value);
	}

	tree.DisplayInOrder();
	std::cout << std::endl;

	std::cout << "Nodes count = " << tree.GetNodesCount() << std::endl;

	return 0;
}