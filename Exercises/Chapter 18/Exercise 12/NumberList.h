#pragma once

class NumberList
{
private:
	struct ListNode
	{
		double value;
		struct ListNode* next;
	};

	ListNode* head;

public:
	NumberList()
		: head(nullptr)
	{ }

	~NumberList();

	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const;
	void mergeArray(double arr[], size_t size);
};