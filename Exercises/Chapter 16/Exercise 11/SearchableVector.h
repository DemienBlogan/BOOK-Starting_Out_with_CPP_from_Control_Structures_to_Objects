#pragma once
#include "SortableVector.h"

template <class T>
class SearchableVector : public SortableVector<T>
{
public:
	SearchableVector() : SortableVector<T>()
	{ }

	SearchableVector(int size) : SortableVector<T>(size)
	{ }

	SearchableVector(const SearchableVector& other);

	int findItem(const T);

	int sortAndSearch(const T& value);
};

template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector& other) 
	: SortableVector<T>(other.GetSize())
{
	for (size_t i = 0; i < this->GetSize(); i++)
		this->operator[](i) = other[i];
}

template <class T>
int SearchableVector<T>::findItem(const T item)
{
	int leftBorder = 0, rightBorder = this->GetSize();
	
	while (leftBorder < rightBorder)
	{
		int middleIndex = (leftBorder + rightBorder) / 2;
		int middleElement = this->getElementAt(middleIndex);

		if (middleElement == item)
			return middleIndex;
		else if (item > middleElement)
			leftBorder = middleIndex + 1;
		else
			rightBorder = middleIndex - 1;
	}
	
	return -1;
}

template<class T>
inline int SearchableVector<T>::sortAndSearch(const T& value)
{
	this->Sort();
	return findItem(value);
}