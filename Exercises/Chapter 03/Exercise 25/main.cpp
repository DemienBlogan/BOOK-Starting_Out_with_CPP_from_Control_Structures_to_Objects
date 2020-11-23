/*
25. Word Game
Write a program that plays a word game with the user. The program should ask the
user to enter the following:
- His or her name
- His or her age
- The name of a city
- The name of a college
- A profession
- A type of animal
- A pet's name
After the user has entered these items, the program should display the following story,
inserting the user's input inro the appropriate locations:
There once was a person named NAME who lived in CITY. At the age of AGE,
NAME went to college at COLLEGE. NAME graduated and went to work as a
PROFESSION. Then, NAME adopted a(n) ANINAL named PETNAME. They both lived
happily ever after!
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Enter your name: ";
	string name;
	cin >> name;

	cout << "Enter your age: ";
	int age;
	cin >> age;
	cin.ignore();

	cout << "Enter the name of a city: ";
	string city;
	getline(cin, city);

	cout << "Enter the name of a college: ";
	string college;
	getline(cin, college);

	cout << "Enter a profession: ";
	string profession;
	getline(cin, profession);

	cout << "Enter a type of animal: ";
	string animalType;
	getline(cin, animalType);

	cout << "Enter a pet's name: ";
	string petName;
	getline(cin, petName);

	cout << "There once was a person named " << name << " who lived in " << city;
	cout << ". At the age of " << age << ", " << name << " went to college at ";
	cout << "college at " << college << ". " << name << " graduated and went to ";
	cout << "went to work as a " << profession << ". Then, " << name << " adopted ";
	cout << "a(n) " << animalType << " named " << petName << ". They both lived ";
	cout << "happily ever after!\n";

	return 0;
}