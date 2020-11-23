/*
9. How Many Calories?
A bag of cookies holds 30 cookies. The calorie information on the bag claims there are
10 "servings" in the bag and that a serving equals 300 calorics. Write a program that
asks the user co input how many cookies he or she actually are, then reports how many
total calories were consumed.
*/

#include <iostream>

int main()
{
	using namespace std;

	const int COOKIES_IN_BAG = 30;
	const int AMOUNT_OF_SERVINGS = 10;
	const int COOKIES_IN_SERVING = COOKIES_IN_BAG / AMOUNT_OF_SERVINGS;
	const double CALORIES_IN_SERVING = 300;
	const double CALORIES_IN_COOKIE = CALORIES_IN_SERVING / COOKIES_IN_SERVING;

	cout << "How many cookies did you actually eat: ";
	int cookies;
	cin >> cookies;

	double totalCalories = cookies * CALORIES_IN_COOKIE;
	cout << "Total calories consumed = " << totalCalories << endl;

	return 0;
}