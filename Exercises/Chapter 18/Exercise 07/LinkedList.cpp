#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
	: head(nullptr), tail(nullptr)
{ }

LinkedList::LinkedList(const LinkedList& other)
	: head(nullptr), tail(nullptr)
{
	Node* node = other.head;

	while (node != nullptr)
	{
		Append(node->value);
		node = node->next;
	}
}

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

void LinkedList::Insert(int value, size_t index)
{
	size_t nodeIndex = 0;
	Node* node = head;
	Node* previous = nullptr;

	while (node != nullptr)
	{
		if (nodeIndex == index)
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

		nodeIndex++;
		previous = node;
		node = node->next;
	}

	Append(value);
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

bool LinkedList::Delete(size_t index)
{
	Node* node = head;
	Node* previous = nullptr;
	size_t nodeIndex = 0;

	while (node != nullptr)
	{
		if (nodeIndex == index)
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
		nodeIndex++;
	}
	return false;
}

void LinkedList::Print() const
{
	Node* node = head;
	while (node != nullptr)
	{
		std::cout << node->value << " ";
		node = node->next;
	}
}

void LinkedList::Reserve()
{
	if (head == nullptr)
		return;

	Node* node = head;
	Node* previous = nullptr;
	Node* next;

	while (true)
	{
		next = node->next;
		node->next = previous;

		if (next == nullptr)
		{
			head = node;
			return;
		}

		previous = node;
		node = next;
	}
}

int LinkedList::Search(int value)
{
	int index = 0;
	Node* node = head;

	while (node != nullptr)
	{
		if (node->value == value)
			return index;

		index++;
		node = node->next;
	}

	return -1;
}