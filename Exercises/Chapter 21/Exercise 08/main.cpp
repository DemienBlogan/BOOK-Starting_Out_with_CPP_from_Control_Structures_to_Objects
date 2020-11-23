/*
8. Employee Tree
Design an EmployeeInfo class that holds the following employee information:

Employee ID Number: an integer
Employee Name:      a string

Next, use the template you designed in Programming Challenge 1 (Binary Tree Template)
to implement a binary tree whose nodes hold an instance of the EmployeeInfo class.
The nodes should be sorted on the Employee ID number.
*/

#include "BinaryTree.h"
#include "Employee.h"

int main()
{
	BinaryTree<Employee> tree;

	tree.Insert(Employee{ 70, "Demien" });
	tree.Insert(Employee{ 30, "Olga" });
	tree.Insert(Employee{ 20, "Vita" });
	tree.Insert(Employee{ 50, "Anya" });
	tree.Insert(Employee{ 33, "Sonya" });
	tree.Insert(Employee{ 48, "Nazar" });
	tree.Insert(Employee{ 28, "Andrew" });
	tree.Insert(Employee{ 3, "David" });
	tree.Insert(Employee{ 5, "LastBoy" });

	std::cout << "Employees:\n";
	tree.DisplayInOrder();
	std::cout << std::endl;
	return 0;
}