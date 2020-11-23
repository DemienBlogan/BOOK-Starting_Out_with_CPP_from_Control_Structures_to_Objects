#pragma once

class LinkedList
{
private:
	struct Node
	{
		int value;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	LinkedList();
	LinkedList(const LinkedList& other);

	~LinkedList();

	void Append(int value);
	void Insert(int value);
	void Insert(int value, size_t index);
	bool Delete(int value);
	void Print() const;
	void Reserve();
	int Search(int value);
};