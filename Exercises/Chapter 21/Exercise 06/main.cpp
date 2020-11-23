/*
6. Tree Assignment Operators, Copy Constructors, and Move Constructors
Design an overloaded copy assignment operator, a move assignment operator, a
copy constructor, and a move constructor for either the template you designed in
Programming Challenge 1 or the IntBinaryTree clas. Demonstrate the
function in a driver program.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	BinaryTree<int> tree1;

	for (size_t i = 0; i < 10; i++)
	{
		int value = std::rand() % 100;
		tree1.Insert(value);
	}

#pragma region Copy Constructor
	std::cout << "--- Test Copy Constructor:\n";
	BinaryTree<int> tree2{ tree1 };
	std::cout << "Tree 1: ";
	tree1.DisplayInOrder();
	std::cout << std::endl;

	std::cout << "Tree 2: ";
	tree2.DisplayInOrder();
	std::cout << std::endl;
#pragma endregion

#pragma region Move Constructor
	std::cout << "--- Test Move Constructor:\n";
	BinaryTree<int> tree3{ std::move(tree1) };

	std::cout << "Tree 1: ";
	tree1.DisplayInOrder();
	std::cout << std::endl;

	std::cout << "Tree 3: ";
	tree3.DisplayInOrder();
	std::cout << std::endl;
#pragma endregion

#pragma region Move Assignment Operator
	std::cout << "--- Test Move Assignment Operator:\n";
	BinaryTree<int> tree4;
	tree4 = std::move(tree2);

	std::cout << "Tree 2: ";
	tree2.DisplayInOrder();
	std::cout << std::endl;

	std::cout << "Tree 4: ";
	tree4.DisplayInOrder();
	std::cout << std::endl;
#pragma endregion

#pragma region Copy Assignment Operator
	std::cout << "--- Test Copy Assignment Operator:\n";
	BinaryTree<int> tree5;
	tree5 = tree4;

	std::cout << "Tree 4: ";
	tree4.DisplayInOrder();
	std::cout << std::endl;

	std::cout << "Tree 5: ";
	tree5.DisplayInOrder();
	std::cout << std::endl;
#pragma endregion

	return 0;
}