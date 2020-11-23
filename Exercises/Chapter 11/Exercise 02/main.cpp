/*
2. Movie Profit
Modify the program written for Programming Challenge 1 (Movie Data) to include
two additional members that hold the movie's production costs and first-year revenues.
Modify the function that displays the movie data to display the title, director, release
year, running time, and first year's profit or loss.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct MovieData
{
	string title;
	string director;
	int yearReleased;
	int runningTime; // minutes
	double productionCosts;
	double revenues;
};

void Show(const MovieData& movie);

int main()
{
	MovieData movie1 = { "Interstellar", "Christopher Nolan", 2014, 164, 18'000'000, 130'000'000 };
	MovieData movie2 = { "Inception", "Christopher Nolan", 2012, 153, 14'000'000, 243'000'000 };

	cout << "--- Movie #1 ---\n";
	Show(movie1);

	cout << "--- Movie #2 ---\n";
	Show(movie2);

	return 0;
}

void Show(const MovieData& movie)
{
	cout << "Title:         " << movie.title << endl;
	cout << "Director:      " << movie.director << endl;
	cout << "Year Released: " << movie.yearReleased << endl;
	cout << "Running Time:  " << movie.runningTime << "m\n";
	
	double profit = movie.productionCosts - movie.revenues;

	cout << setprecision(2) << fixed;

	if (profit >= 0)
		cout << "Profit:  $" << profit << endl;
	else
		cout << "Loss: $" << -profit << endl;
}