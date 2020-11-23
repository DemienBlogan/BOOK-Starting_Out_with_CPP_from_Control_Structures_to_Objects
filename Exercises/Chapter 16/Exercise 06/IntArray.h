#pragma once

class IntArray
{
private:
	int* arr;
	int size;

public:
	IntArray(int size);
	IntArray(const IntArray& other);

	~IntArray();

	int GetSize() const { return size; }

	const IntArray operator=(const IntArray& other);
	int& operator[](const int& index);
};