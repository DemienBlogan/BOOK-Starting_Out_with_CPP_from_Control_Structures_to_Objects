/*
9. Hotel Occupancy
Write a program that calculates the occupancy rate for a hotel. The program should
start by asking the user how many floors the hotel has. A loop should then iterate once
for each floor. In each iteration, the loop should ask the user for the number of rooms
on the floor and how many of them are occupied. After all the iterations, the program
should display how many rooms the hotel has, how many of them are occupied, how
many are unoccupied, and the percentage of rooms that are occupied. The percentage
may be calculated by dividing the number of rooms occupied by the number of rooms.

NOTE: It is traditional that mose hotels do not have a thirteenth floor. The loop in
this program should skip the entire thirteenth iteration.

Input Validation: Do not accept a value less than 1 for the number of floors. Do not
accept a number less than 10 for the number of rooms on a floor.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the number of floors the hotal has (floors > 0): ";
	int floors;
	cin >> floors;

	if (floors < 1)
	{
		cout << "Incorrect number of floors. It has to be greater than 0.\n";
		return 0;
	}

	int hotelRooms = 0;
	int hotelOccupiedRooms = 0;

	for (int floor = 1; floor <= floors; floor++)
	{
		if (floor == 13)
			continue;

		cout << "Enter the number of rooms (rooms > 9): ";
		int floorRooms;
		cin >> floorRooms;

		if (floorRooms < 10)
		{
			cout << "Incorrect number of rooms. It has to be greater than 9.\n";
			return 0;
		}

		hotelRooms += floorRooms;

		cout << "How many of them are occupied? ";
		int occupiedFloorRooms;
		cin >> occupiedFloorRooms;

		if (occupiedFloorRooms > floorRooms)
		{
			cout << "Incorrect number of occupied rooms. It has to be less or equal to floor rooms.\n";
			return 0;
		}

		hotelOccupiedRooms += occupiedFloorRooms;
	}

	double occupiedRoomsPercentage = hotelOccupiedRooms * 100.0 / hotelRooms;

	cout << "All hotel rooms: " << hotelRooms << endl;
	cout << "All hotel occupied rooms: " << hotelOccupiedRooms << endl;

	cout << fixed << setprecision(1);
	cout << "Occupied rooms percentage: " << occupiedRoomsPercentage << "%\n";

	return 0;
}