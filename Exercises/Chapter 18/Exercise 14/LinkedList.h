#pragma once
#include <iostream>

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T value;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	LinkedList();
	LinkedList(const LinkedList& other);

	~LinkedList();

	void Append(const T& value);
	void Insert(const T& value);
	void Insert(const T& value, size_t index);
	bool Delete(const T& value);
	bool Delete(size_t index);
	void Print() const;
	void Reserve();
	int Search(const T& value);

	T& operator[](size_t index);
	const T& operator[](size_t index) const;
};

template <typename T>
LinkedList<T>::LinkedList()
	: head(nullptr), tail(nullptr)
{ }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
	: head(nullptr), tail(nullptr)
{
	Node* node = other.head;

	while (node != nullptr)
	{
		Append(node->value);
		node = node->next;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
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

template <typename T>
void LinkedList<T>::Append(const T& value)
{
	if (head == nullptr)
		head = tail = new Node{ value, nullptr };
	else
	{
		tail->next = new Node{ value, nullptr };
		tail = tail->next;
	}
}

template <typename T>
void LinkedList<T>::Insert(const T& value)
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

template <typename T>
void LinkedList<T>::Insert(const T& value, size_t index)
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

template <typename T>
bool LinkedList<T>::Delete(const T& value)
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

template <typename T>
bool LinkedList<T>::Delete(size_t index)
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

template <typename T>
void LinkedList<T>::Print() const
{
	Node* node = head;
	while (node != nullptr)
	{
		std::cout << node->value << " ";
		node = node->next;
	}
}

template <typename T>
void LinkedList<T>::Reserve()
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

template <typename T>
int LinkedList<T>::Search(const T& value)
{
	size_t index = 0;
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

template<typename T>
T& LinkedList<T>::operator[](size_t index)
{
	size_t nodeIndex = 0;
	Node* node = head;

	while (node != nullptr)
	{
		if (nodeIndex == index)
			return node->value;

		nodeIndex++;
		node = node->next;
	}

	throw std::out_of_range("Index is out of list range!");
}

template<typename T>
const T& LinkedList<T>::operator[](size_t index) const
{
	// TODO: insert return statement here
}
