/*
7. Queue Converter
Write a program that stores a series of numbers in a binary tree. Then have the program
insert the values into a queue in ascending order. Dequeue the values and display them
on the screen to confirm that they were stored in the proper order.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"
#include "Queue.h"

void InsertNodeQueue(const BinaryTree<int>::Node* node, Queue<int>& queue)
{
	if (node != nullptr)
	{
		InsertNodeQueue(node->left, queue);
		queue.Enqueue(node->value);
		InsertNodeQueue(node->right, queue);
	}
}

void InsertTreeNodesIntoQueue(const BinaryTree<int>& tree, Queue<int>& queue)
{
	InsertNodeQueue(tree.GetRoot(), queue);
}

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	BinaryTree<int> tree;

	for (size_t i = 0; i < 10; i++)
	{
		int value = std::rand() % 100;
		tree.Insert(value);
	}

	Queue<int> queue;

	InsertTreeNodesIntoQueue(tree, queue);

	std::cout << "Binary Tree: ";
	tree.DisplayInOrder();
	std::cout << std::endl;

	std::cout << "Queue      : ";
	while (!queue.IsEmpty())
	{
		int value;
		queue.Dequeue(value);
		std::cout << value << " ";
	}
	std::cout << std::endl;

	return 0;
}