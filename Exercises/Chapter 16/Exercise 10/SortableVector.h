#pragma once
#include <utility>
#include "SimpleVector.h"

template <typename T>
class SortableVector : public SimpleVector<T>
{
public:
	SortableVector() : SimpleVector<T>()
	{ }

	SortableVector(int size) : SimpleVector<T>(size)
	{ }

	SortableVector(const SortableVector& other);

	void Sort();
};

template <typename T>
inline SortableVector<T>::SortableVector(const SortableVector& other) 
	: SimpleVector<T>(other.GetSize())
{
	for (size_t i = 0; i < this->GetSize(); i++)
		this->operator[](i) = other[i];
}

template <typename T>
inline void SortableVector<T>::Sort()
{
	for (size_t i = 0; i < this->GetSize() - 1; i++)
		for (size_t j = i + 1; j < this->GetSize(); j++)
			if (this->operator[](i) > this->operator[](j))
				std::swap(this->operator[](i), this->operator[](j));
}