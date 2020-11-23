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

	~LinkedList();

	void Append(int value);
	void Insert(int value);
	bool Delete(int value);
};