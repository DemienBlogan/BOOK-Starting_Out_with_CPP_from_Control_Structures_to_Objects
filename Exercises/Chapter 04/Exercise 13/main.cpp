/*
13. Book Club Points
Serendipity Booksellers has a book club that awards points to its customers based on
the number of books purchased each month. The points are awarded as follows:
- If a customer purchases 0 books, he or she earns 0 points.
- If a customer purchases 1 book, he or she earns 5 points.
- If a customer purchases 2 books, he or she earns 15 points.
- If a customer purchases 3 books, he or she earns 30 points.
- If a customer purchases 4 books or more books, he or she earns 60 points.
Write a program that asks the user to enter the number of books he or she has purchased
this month then displays the number of points awarded.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the numbe rof books you have purchased: ";
	int books;
	cin >> books;

	if (books < 0)
	{
		cout << "Incorrect value. Try again.\n";
		return 0;
	}

	int points;

	switch (books)
	{
	case 0:
		points = 0;
		break;
	case 1:
		points = 5;
		break;
	case 2:
		points = 15;
		break;
	case 3:
		points = 30;
		break;
	default:
		points = 60;
		break;
	}

	cout << "You have earned " << points << " points!\n";

	return 0;
}