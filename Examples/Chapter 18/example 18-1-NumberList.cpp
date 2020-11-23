#include "example 18-1-NumberList.h"

void NumberList::appendNode(double num)
{
	ListNode* newNode; // To point to a new node
	ListNode* nodePtr; // To move through the list

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	// If there are no does in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}