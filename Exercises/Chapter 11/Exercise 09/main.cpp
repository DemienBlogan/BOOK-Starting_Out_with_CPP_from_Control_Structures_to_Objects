/*
9. Speaker's Bureau
Write a program that keeps track of a speakers' bureau. The program should use a
structure to store the following data about a speaker:
	Name
	Telephone Number
	Speaking Topic
	Fee Required
The program should use an array of at least 10 structures. It should let the user enter
data into the array, change the contents of any element, and display all the data stored
in the array. The program should have a menu-driven user interface.

Input Validation: When the data for a new speaker is entered, be sure the user enters
data for all the fields. no negative amounts should be entered for a speaker's fee.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Speaker
{
	string name;
	string telephone;
	string speakingTopic;
	double fee;
};

void ShowMenu();
char SelectMenuItem();
void ErrorTerminate();
void ShowSpeakersBureau(const Speaker speakersBureau[], size_t speakers);
void ShowSpeaker(const Speaker& speaker);
void InitializeSpeakersBureau(Speaker speakersBureau[], size_t speakers);
void InitializeSpeaker(Speaker& speaker);
double EnterBalance();
void ChangeSpeaker(Speaker speakersBureau[], size_t speakers, size_t speakerIndex);
size_t EnterSpeakerIndex(size_t speakers);

int main()
{
	const size_t SPEAKERS = 10;
	Speaker speakersBureau[SPEAKERS];
	char menuItem;
	size_t speakerIndex;

	InitializeSpeakersBureau(speakersBureau, SPEAKERS);

	do
	{
		ShowMenu();
		menuItem = SelectMenuItem();

		switch (menuItem)
		{
		case '1':
			ShowSpeakersBureau(speakersBureau, SPEAKERS);
			break;
		case '2':
			speakerIndex = EnterSpeakerIndex(SPEAKERS);
			ChangeSpeaker(speakersBureau, SPEAKERS, speakerIndex);
			break;
		case '0':
			system("cls");
			break;
		default:
			ErrorTerminate();
			break;
		}

	} while (menuItem != '0');

	return 0;
}

void ShowMenu()
{
	cout << "1 - Show speakers           \n";
	cout << "2 - Change speaker info     \n";
	cout << "0 - Quit                    \n";
}

char SelectMenuItem()
{
	char menuItem;

	do
	{
		cin >> menuItem;

		if (menuItem != '1' && menuItem != '2' && menuItem != '0')
			cout << "Incorrect item. Try again.\n";

	} while (menuItem != '1' && menuItem != '2' && menuItem != '0');

	return menuItem;
}

void ErrorTerminate()
{
	cerr << "Error. Incorrect value of menuItem in default case.\n";
	exit(1);
}

void ShowSpeakersBureau(const Speaker speakersBureau[], size_t speakers)
{
	cout << fixed << setprecision(2);

	for (size_t i = 0; i < speakers; i++)
	{
		cout << "Speaker #" << i + 1 << ":\n";
		ShowSpeaker(speakersBureau[i]);
	}
}

void ShowSpeaker(const Speaker& speaker)
{
	cout << "\t Name: " << speaker.name << endl;
	cout << "\t Telephone: " << speaker.telephone << endl;
	cout << "\t Speaking topic: " << speaker.speakingTopic << endl;
	cout << "\t Fee: $" << speaker.fee << endl;
}

void InitializeSpeakersBureau(Speaker speakersBureau[], size_t speakers)
{
	for (size_t i = 0; i < speakers; i++)
	{
		cout << "Speaker #" << i + 1 << ":\n";
		InitializeSpeaker(speakersBureau[i]);
	}
}

void InitializeSpeaker(Speaker& speaker)
{
	cout << "\t Enter name: ";
	getline(cin, speaker.name);

	cout << "\t Enter telephone: ";
	getline(cin, speaker.telephone);

	cout << "\t Enter speaking topic: ";
	getline(cin, speaker.speakingTopic);

	cout << "\t Enter fee: ";
	do
	{
		cin >> speaker.fee;
		cin.ignore();

		if (speaker.fee < 0)
			cout << "Incorrect fee. Try again.\n";

	} while (speaker.fee < 0);
}

void ChangeSpeaker(Speaker speakersBureau[], size_t speakers, size_t speakerIndex)
{
	if (speakerIndex >= speakers)
	{
		cout << "Incorrect index of customer.\n";
		return;
	}

	InitializeSpeaker(speakersBureau[speakerIndex]);
}

size_t EnterSpeakerIndex(size_t speakers)
{
	size_t speakerIndex;

	do
	{
		cout << "Enter speaker index (0 ... " << speakers - 1 << "): ";
		cin >> speakerIndex;
		cin.ignore();

		if (speakerIndex >= speakers)
			cout << "Your index is too large. Try again.\n";

	} while (speakerIndex >= speakers);

	return speakerIndex;
}