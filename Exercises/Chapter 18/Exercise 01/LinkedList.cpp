#include "LinkedList.h"

LinkedList::LinkedList()
	: head(nullptr), tail(nullptr)
{ }

LinkedList::~LinkedList()
{
	if (head != nullptr)
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}

		tail = nullptr;
	}
}

void LinkedList::Append(int value)
{
	if (head == nullptr)
		head = tail = new Node{ value, nullptr };
	else
	{
		tail->next = new Node{ value, nullptr };
		tail = tail->next;
	}
}

void LinkedList::Insert(int value)
{
	Node* node = head;
	Node* previous = nullptr;

	while (node != nullptr)
	{
		if (node->value > value)
		{
			if (node == head)
			{
				Node* newNode = new Node{ value, head->next };
				head = newNode;
			}
			else if (node == tail)
			{
				Node* newNode = new Node{ value, nullptr };
				tail->next = newNode;
				tail = newNode;
			}
			else
			{
				Node* newNode = new Node{ value, node };
				previous->next = newNode;
			}

			return;
		}

		previous = node;
		node = node->next;
	}

	Node* newNode = new Node{ value, nullptr };
	tail->next = newNode;
	tail = newNode;
}

bool LinkedList::Delete(int value)
{
	Node* node = head;
	Node* previous = nullptr;

	while (node != nullptr)
	{
		if (node->value == value)
		{
			if (node == head)
			{
				if (head != tail)
					head = head->next;
				else
					head = tail = nullptr;
			}
			else if (node == tail)
			{
				tail = previous;
				tail->next = nullptr;
			}
			else
				previous->next = node->next;

			delete node;
			return true;
		}

		previous = node;
		node = node->next;
	}

	return false;
}