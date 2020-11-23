#pragma once
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T>
class SimpleVector
{
private:
	T* arr;
	int size;
	void memError();
	void subError();

public:
	SimpleVector();
	SimpleVector(int size);
	SimpleVector(const SimpleVector& other);

	~SimpleVector();

	int GetSize() const { return size; }
	T getElementAt(int index);

	void push_back(const T& value);
	void pop_back();

	T& operator[](const int& index);
};

template <class T>
SimpleVector<T>::SimpleVector()
	: arr(0), size(0)
{ }

template <class T>
SimpleVector<T>::SimpleVector(int size)
{
	this->size = size;

	try
	{
		arr = new T[size]{ 0 };
	}
	catch (const bad_alloc&)
	{
		memError();
	}
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& other)
{
	size = other.size;

	arr = new T[size];
	if (arr == nullptr)
		memError();

	for (size_t i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (size > 0)
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
}

template <class T>
void SimpleVector<T>::memError()
{
	cout << "ERROR: Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::subError()
{
	cout << "ERROR: Subscript is out of range.\n";
	exit(EXIT_FAILURE);
}

template <class T>
T SimpleVector<T>::getElementAt(int index)
{
	if (index < 0 || index >= size)
		subError();
	return arr[index];
}

template<class T>
inline void SimpleVector<T>::push_back(const T& value)
{
	if (size == 0)
	{
		size = 1;

		try
		{
			arr = new T[size]{ value };
		}
		catch (const bad_alloc&)
		{
			memError();
		}
	}
	else
	{
		size++;

		try
		{
			T* newArr = new T[size];

			for (size_t i = 0; i < size - 1; i++)
				newArr[i] = arr[i];
			newArr[size - 1] = value;

			delete[] arr;
			arr = newArr;
		}
		catch (const bad_alloc&)
		{
			memError();
		}
	}
}

template<class T>
inline void SimpleVector<T>::pop_back()
{
	if (size == 1)
	{
		size = 0;
		delete[] arr;
		arr = nullptr;
	}
	else
	{
		size--;

		try
		{
			T* newArr = new T[size];

			for (size_t i = 0; i < size; i++)
				newArr[i] = arr[i];

			delete[] arr;
			arr = newArr;
		}
		catch (const bad_alloc&)
		{
			memError();
		}
	}
}

template <class T>
T& SimpleVector<T>::operator[](const int& index)
{
	if (index < 0 || index >= size)
		subError();
	return arr[index];
}

// SPECIALIZED TEMPLATE CLASS "CHAR *"
template <>
class SimpleVector<char*>
{
private:
	char** arr;
	int size;
	void memError()
	{
		cout << "ERROR: Cannot allocate memory.\n";
		exit(EXIT_FAILURE);
	}

	void subError()
	{
		cout << "ERROR: Subscript is out of range.\n";
		exit(EXIT_FAILURE);
	}

public:
	SimpleVector()
		: arr(nullptr), size(0)
	{ };

	SimpleVector(int size)
	{
		this->size = size;

		try
		{
			arr = new char* [size] { nullptr };
		}
		catch (const bad_alloc&)
		{
			memError();
		}
	}

	SimpleVector(const SimpleVector& other)
	{
		size = other.size;

		arr = new char* [size];
		if (arr == nullptr)
			memError();

		for (size_t i = 0; i < size; i++)
		{
			if (other.arr[i] == nullptr)
				arr[i] = nullptr;
			else
			{
				size_t length = strlen(other.arr[i]);
				arr[i] = new char[length + 1];
				strcpy_s(arr[i], length + 1, other.arr[i]);
			}
		}
	}

	~SimpleVector()
	{
		if (size > 0)
		{
			for (size_t i = 0; i < size; i++)
				delete[] arr[i];
			delete[] arr;

			arr = nullptr;
			size = 0;
		}
	}

	int GetSize() const
	{ 
		return size;
	}

	char* getElementAt(int index)
	{
		if (index < 0 || index >= size)
			subError();
		return arr[index];
	}

	void push_back(const char* const& value)
	{
		if (size == 0)
		{
			size = 1;

			try
			{
				arr = new char* [1];

				if (value == nullptr)
					arr[0] = nullptr;
				else
				{
					size_t length = strlen(value);
					arr[0] = new char[length + 1];
					strcpy_s(arr[0], length + 1, value);
				}
			}
			catch (const bad_alloc&)
			{
				memError();
			}
		}
		else
		{
			size++;

			try
			{
				char** newArr = new char* [size];

				for (int i = 0; i < size - 1; i++)
				{
					size_t length = strlen(arr[i]);
					newArr[i] = new char[length + 1];
					strcpy_s(newArr[i], length + 1, arr[i]);
				}

				size_t length = strlen(value);
				newArr[size - 1] = new char[length + 1];
				strcpy_s(newArr[size - 1], length + 1, value);

				for (int i = 0; i < size - 1; i++)
					delete[] arr[i];
				delete[] arr;

				arr = newArr;
			}
			catch (const bad_alloc&)
			{
				memError();
			}
		}
	}

	void pop_back()
	{
		if (size == 1)
		{
			size = 0;
			delete[] arr[0];
			delete[] arr;
			arr = nullptr;
		}
		else
		{
			size--;

			try
			{
				char** newArr = new char* [size];

				for (int i = 0; i < size; i++)
				{
					size_t length = strlen(arr[i]);
					newArr[i] = new char[length + 1];
					strcpy_s(newArr[i], length + 1, arr[i]);
				}

				for (int i = 0; i < size + 1; i++)
					delete[] arr[i];
				delete[] arr;

				arr = newArr;
			}
			catch (const bad_alloc&)
			{
				memError();
			}
		}
	}

	const char* operator[](const int& index)
	{
		if (index < 0 || index >= size)
			subError();
		return arr[index];
	}
};