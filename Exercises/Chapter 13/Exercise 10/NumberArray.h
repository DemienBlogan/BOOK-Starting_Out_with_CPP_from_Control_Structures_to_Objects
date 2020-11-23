#pragma once

class NumberArray
{
private:
	float* arr;
	size_t size;

public:
	NumberArray(size_t size);
	~NumberArray();

	float GetElement(size_t index) const { return arr[index]; }
	void SetElement(size_t index, float value) { arr[index] = value; }
	float GetMax() const;
	float GetMin() const;
	float GetAverage() const;
};