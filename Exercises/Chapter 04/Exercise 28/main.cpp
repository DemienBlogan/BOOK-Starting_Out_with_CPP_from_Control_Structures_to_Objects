/*
28. Restaurant Selector
You have a group of friends coming to visit for your high school reunion, and you want
to take them out to eat at a local restaurant. You aren't sure if any of them have dietary
restrictions, but your restaurant choices are as follows:

Joe's Gourmet Burgers - Vegetarian: No, Vegan: No, Gluten-Free: No
Main Street Pizza Company - Vegetarian: Yes, Vegan: No, Gluten-Free: Yes
Corner Cafe - Vegetarian: Yes, Vegan: Yes, Gluten-Free: Yes
Mama's Fine Italian - Vegetarian: Yes, Vegan: No, Gluten-Free: No
The Chef's Kitchen - Vegetarian: Yes, Vegan: Yes, Gluten-Free: Yes

Write a program that asks whether any members of your party are vegetarian, vegan,
or gluten-free, then displays only the restaurants that you may take the group to.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Is anyone in your party a vegetarian? ";
	string isAnyoneVegetarian;
	cin >> isAnyoneVegetarian;

	cout << "Is anyone in your party a vegan? ";
	string isAnyoneVegan;
	cin >> isAnyoneVegan;

	cout << "Is anyone in your party a gluten-free? ";
	string isAnyoneGlutenfree;
	cin >> isAnyoneGlutenfree;

	cout << "Here are your restaurant choices:\n";

	if (isAnyoneVegetarian == "yes" && isAnyoneVegan == "no" && isAnyoneGlutenfree == "no")
	{
		cout << "\t - Corner Cafe \n";
		cout << "\t - The Chef's Kitchen \n";
		cout << "\t - Main Street Pizza Company \n";
		cout << "\t - Mama's Fine Italian \n";
	}
	else if (isAnyoneVegetarian == "no" && isAnyoneVegan == "no" && isAnyoneGlutenfree == "yes")
	{
		cout << "\t - Corner Cafe \n";
		cout << "\t - The Chef's Kitchen \n";
		cout << "\t - Main Street Pizza Company \n";
	}
	else if ((isAnyoneVegetarian == "yes" && isAnyoneVegan == "yes" && isAnyoneGlutenfree == "no")  ||
		     (isAnyoneVegetarian == "yes" && isAnyoneVegan == "yes" && isAnyoneGlutenfree == "yes") ||
		     (isAnyoneVegetarian == "no"  && isAnyoneVegan == "yes" && isAnyoneGlutenfree == "no")  || 
		     (isAnyoneVegetarian == "no"  && isAnyoneVegan == "yes" && isAnyoneGlutenfree == "yes"))
	{
		cout << "\t - Corner Cafe \n";
		cout << "\t - The Chef's Kitchen \n";
	}
	else if (isAnyoneVegetarian == "yes" && isAnyoneVegan == "no" && isAnyoneGlutenfree == "yes")
	{
		cout << "\t - Corner Cafe \n";
		cout << "\t - The Chef's Kitchen \n";
		cout << "\t - Main Street Pizza Company \n";
	}
	else if (isAnyoneVegetarian == "no" && isAnyoneVegan == "no" && isAnyoneGlutenfree == "no")
	{
		cout << "\t - Joe's Gourment Burgers \n";
		cout << "\t - Corner Cafe \n";
		cout << "\t - The Chef's Kitchen \n";
		cout << "\t - Main Street Pizza Company \n";
		cout << "\t - Mama's Fine Italian \n";
	}

	return 0;
}