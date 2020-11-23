/*
1. Movie Data
Write a program that uses a sturcture named MovieData to store the following information
about a movie:
	Title
	Director
	Year Released
	Running Time (in minutes)
The program should create two MovieData variables, store values in their members,
and pass each one, in turn, to a function that displays the information about the movie
in a clearly formatted manner.
*/

#include <iostream>
#include <string>

using namespace std;

struct MovieData
{
	string title;
	string director;
	int yearReleased;
	int runningTime; // minutes
};

void Show(const MovieData& movie);

int main()
{
	MovieData movie1 = { "Interstellar", "Christopher Nolan", 2014, 164 };
	MovieData movie2 = { "Inception", "Christopher Nolan", 2012, 153 };

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
	cout << "Running Time:  " << movie.runningTime << "m\n\n";
}