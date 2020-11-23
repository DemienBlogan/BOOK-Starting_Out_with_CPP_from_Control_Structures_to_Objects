#pragma once
#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
	SearchableVector() : SimpleVector<T>()
	{ }

	SearchableVector(int size) : SimpleVector<T>(size)
	{ }

	SearchableVector(const SearchableVector& other);

	int findItem(const T);
};

template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector& other) 
	: SimpleVector<T>(other.GetSize())
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