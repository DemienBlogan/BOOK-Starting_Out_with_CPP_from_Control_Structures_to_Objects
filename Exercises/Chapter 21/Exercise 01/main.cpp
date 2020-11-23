/*
1. Binary Tree Template
Write your own version of a class template that will create a binary tree that can hold
values of any data type. Demonstrate the class with a driver program.
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

	tree.DisplayPreOrder();
	std::cout << std::endl;

	tree.DisplayPostOrder();
	std::cout << std::endl;

	return 0;
}