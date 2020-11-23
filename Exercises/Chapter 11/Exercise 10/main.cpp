/*
10. Search Function for the Speakers' Bureau Program
Add a function to Programming Challenge 9 (Speakers' Bureau) that allows the user to
search for a speaker on a particular topic. It should accept a key word as an argument
then search the array for a structure with that key word in the Speaking Topic field.
All structures that match should be displayed. If no structure matches, a message saying
so should be displayed.
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
string EnterTopic();
void FindSpeakers(const Speaker speakersBureau[], size_t speakers, const string& topic);

int main()
{
	const size_t SPEAKERS = 10;
	Speaker speakersBureau[SPEAKERS];
	char menuItem;
	size_t speakerIndex;
	string speakingTopic;

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

		case '3':
			speakingTopic = EnterTopic();
			FindSpeakers(speakersBureau, SPEAKERS, speakingTopic);
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
	cout << "3 - Find speakers by topic  \n";
	cout << "0 - Quit                    \n";
}

char SelectMenuItem()
{
	char menuItem;

	do
	{
		cin >> menuItem;

		if (menuItem != '1' && menuItem != '2' && menuItem != '3' && menuItem != '0')
			cout << "Incorrect item. Try again.\n";

	} while (menuItem != '1' && menuItem != '2' && menuItem != '3' && menuItem != '0');

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

string EnterTopic()
{
	cout << "Enter the topic: ";
	string topic;
	cin.ignore();
	getline(cin, topic);

	return topic;
}

void FindSpeakers(const Speaker speakersBureau[], size_t speakers, const string& topic)
{
	bool isFound = false;

	for (size_t i = 0; i < speakers; i++)
	{
		size_t findIndex = speakersBureau[i].speakingTopic.find(topic);

		if (findIndex != string::npos)
		{
			isFound = true;
			cout << "Match with speaker #" << i + 1 << ":\n";
			ShowSpeaker(speakersBureau[i]);
			cout << endl;
		}
	}

	if (!isFound)
		cout << "There is no match.\n";
}