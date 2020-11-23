#pragma once
#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
	struct ListNode
	{
		T value;
		struct ListNode* next;
	};

	ListNode* head;

public:
	LinkedList()
		: head(nullptr)
	{ }

	~LinkedList();

	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;

	int search(const T& value);
};

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
	ListNode* newNode;
	ListNode* nodePtr;

	newNode = new ListNode;
	newNode->value = newValue;
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

template <class T>
void LinkedList<T>::displayList() const
{
	ListNode* nodePtr;

	nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->value << endl;

		nodePtr = nodePtr->next;
	}
}

template<class T>
int LinkedList<T>::search(const T& value)
{
	int nodeNumber = 0;
	ListNode* node = head;

	while (node != nullptr)
	{
		nodeNumber++;

		if (node->value == value)
			return nodeNumber;

		node = node->next;
	}

	return 0;
}

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode* newNode;
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = newValue;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;

		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < newValue)
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

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
	ListNode* nodePtr;
	ListNode* previousNode;

	if (!head)
		return;

	if (head->value == searchValue)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != searchValue)
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

template <class T>
LinkedList<T>::~LinkedList()
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