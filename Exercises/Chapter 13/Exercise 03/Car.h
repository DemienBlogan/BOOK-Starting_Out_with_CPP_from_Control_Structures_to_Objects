#pragma once

#include <string>

using std::string;

class Car
{
private:
	int yearModel;
	string make;
	int speed;

public:
	Car(int yearModel, const string& make);

	int GetYearModel() const { return yearModel; }
	string GetMake() const { return make; }
	int GetSpeed() const { return speed; }

	void Accelerate() { speed += 5; }
	void Brake() { speed -= 5; }
};