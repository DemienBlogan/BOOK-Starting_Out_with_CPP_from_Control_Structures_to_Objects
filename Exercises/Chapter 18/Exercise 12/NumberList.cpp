#include <iostream>
#include "NumberList.h"

using namespace std;

void NumberList::appendNode(double num)
{
	ListNode* newNode;
	ListNode* nodePtr;

	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}
}

void NumberList::displayList() const
{
	ListNode* nodePtr;

	nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->value << endl;

		nodePtr = nodePtr->next;
	}
}

void NumberList::mergeArray(double arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		insertNode(arr[i]);
}

void NumberList::insertNode(double num)
{
	ListNode* newNode;
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = num;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;

		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void NumberList::deleteNode(double num)
{
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	if (!head)
		return;

	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

NumberList::~NumberList()
{
	ListNode* nodePtr;
	ListNode* nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}