/*
26. Personal Web Page Generator
Write a program that asks the user for his or her name, then asks the user to enter a
sentence that describes himself or herself.

Once the user has entered the requested input, the program should create an HTML
file, containing the input, for a simple webpage. Here is an example of the HTML
content, using the sample input previously shown:
<html>
<head>
</head>
<body>
	<center>
		<h1>Julie Taylor/h1>
	<center>
	<hr />
		I am a computer science major, a member of the Jazz club,
		and I hope to work as a mobile app developer after I graduate.
	<hr />
</body>
</html>
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;

	ofstream file("SimpleSite.html");

	if (!file)
	{
		cout << "The file 'SimpleSite.html' could not been opened or created.\n";
		return 1;
	}

	cout << "Enter your name: ";
	string name;
	getline(cin, name);

	cout << "Describe yourself: ";
	string describe;
	getline(cin, describe);

	file << R"(<html>
<head>
</head>
<body>
	<center>
		<h1>)";
	file << name;
	file << R"(</h1>
	<center>
	<hr />
)";
	file << "\t\t" << describe << endl;
	file << R"(
	<hr />
</body>
</html>)";

	return 0;
}