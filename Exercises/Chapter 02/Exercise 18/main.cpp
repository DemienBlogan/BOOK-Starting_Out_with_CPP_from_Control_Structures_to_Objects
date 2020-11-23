/*
18. Energy Drink Consumption
A soft drink company recently surveyed 16,500 of its customers and found that approximately
15 percent of those surveyed purchase one or more energy drinks per week. Of
those customers who purchase energy drinks, approximately 58 percent of them prefer
citrus-flavored energy drinks. Write a program that displays the following:
- The approximate number of customers in the survey who purchase one or more
  energy drinks per week.
- The approximate number of customers in the survey who prefer citrus-flavored
  energy drinks.
*/

#include <iostream>

int main()
{
	using namespace std;

	int surveys = 16'500;
	double oneOrMoreDrinksPercent = 0.15; // 15%
	double preferCitrusPercent = 0.58;    // 58%
	double customersPurchaseOneOrMore = surveys * oneOrMoreDrinksPercent;
	double customersPreferCitrus = surveys * preferCitrusPercent;

	cout << "Number of surveys = " << surveys << endl;
	cout << "Number of customers who purchase one or more evergy drinks per week = ";
	cout << customersPurchaseOneOrMore << endl;
	cout << "Number of customers who prefer citrus-flavored evergy drinks = ";
	cout << customersPreferCitrus << endl;

	return 0;
}