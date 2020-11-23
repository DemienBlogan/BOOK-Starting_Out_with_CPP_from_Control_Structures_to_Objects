/*
18. Tic-Tac-Toe Game
Write a program that allows two players to play a game of tic-tac-toe. Use a two-dimensional
char array with three rows and three columns as the game board. Each
element of the array should be initialized with an asterisk (*). The program should run a
loop that does the following.

- Displays the contents of the board array.
- Allows player 1 to select a location on the board for an X. The program should ask
  the user to enter the row and column numbers.
- Allows player 2 to select a location on the board for an O. The program should ask
  the user to enter the row and column numbers.
- Determines whether a player has won, or a tie has occured. If a player has won,
  the program should declare that player the winner and end. If a tie has occurred, the
  program should display an appropriate message and end.

Player 1 wins when there are three Xs in a row on the game board. The Xs can appear in a
row, in a column, or diagonally across the board. Player 2 wins when there are three Os in
a row on the game board. The Os can appear in a row, in a column, or diagonally across
the board. A tie occurs when all of the locations on the board are full, but there is no winner.
*/

#include <iostream>

using namespace std;

enum class Winner
{
	NoOne,
	Player1,
	Player2,
	Draw
};

char** CreateField(size_t rows, size_t cols);
void ClearField(char** field, size_t rows, size_t cols);
void DeleteField(char** field, size_t rows);
void ShowField(const char* const* field, size_t rows, size_t cols);
int EnterCoordinate(char axile);
bool IsCorrectCoordinates(char** field, int x, int y);
void SetByCoordinate(char** field, int x, int y, char symbol);
void ClearScreen();
void PlayerTurn(char** field, int playerNumber, char symbol);
Winner CheckGameStatus(const char* const* field, size_t rows, size_t cols);
void ShowWinner(const Winner& winner);

int main()
{
	const size_t ROWS = 3, COLS = 3;
	char** field;

	field = CreateField(ROWS, COLS);
	ClearField(field, ROWS, COLS);

	Winner winner = Winner::NoOne;
	bool player1Turn = true;

	// Game cycle
	while (winner == Winner::NoOne)
	{
		ShowField(field, ROWS, COLS);
		PlayerTurn(field, player1Turn ? 1 : 2, player1Turn ? 'X' : 'Y');
		winner = CheckGameStatus(field, ROWS, COLS);
		player1Turn = !player1Turn;
	}

	ShowWinner(winner);
	DeleteField(field, ROWS);

	return 0;
}

char** CreateField(size_t rows, size_t cols)
{
	if (rows == 0 || cols == 0)
		return nullptr;

	char** field = new char* [rows];
	for (size_t i = 0; i < rows; i++)
		field[i] = new char[cols];

	return field;
}

void ClearField(char** field, size_t rows, size_t cols)
{
	if (field == nullptr)
		return;

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			field[i][j] = '*';
}

void DeleteField(char** field, size_t rows)
{
	if (field == nullptr)
		return;

	for (size_t i = 0; i < rows; i++)
		delete[] field[i];
	delete[] field;
}

void ShowField(const char* const* field, size_t rows, size_t cols)
{
	if (field == nullptr)
		return;

	cout << "\t  0   1   2   (X)\n";
	cout << "\t-------------\n";

	for (size_t i = 0; i < rows; i++)
	{
		cout << i << "\t| ";
		for (size_t j = 0; j < cols; j++)
			cout << field[i][j] << " | ";
		cout << endl;
	}

	cout << "(Y)\t-------------\n\n";
}

int EnterCoordinate(char axile)
{
	int coordinate;

	do
	{
		cout << "\tEnter " << axile << " coordinate: ";
		cin >> coordinate;

	} while (coordinate < 0 || coordinate > 2);

	return coordinate;
}

bool IsCorrectCoordinates(char** field, int x, int y)
{
	if (field == nullptr)
		return false;

	return field[y][x] == '*' ? true : false;
}

void SetByCoordinate(char** field, int x, int y, char symbol)
{
	field[y][x] = symbol;
}

void ClearScreen()
{
	system("cls");
}

void PlayerTurn(char** field, int playerNumber, char symbol)
{
	cout << "Player #" << playerNumber << " turn.\n";

	bool correctCoordiantes = true;

	int x, y;

	do
	{
		x = EnterCoordinate('X');
		y = EnterCoordinate('Y');

		correctCoordiantes = IsCorrectCoordinates(field, x, y);

		if (!correctCoordiantes)
			cout << "This place is already taken. Try again.\n";

	} while (!correctCoordiantes);

	ClearScreen();
	SetByCoordinate(field, x, y, symbol);
}

Winner CheckGameStatus(const char* const* field, size_t rows, size_t cols)
{
	int symbolYCount = 0, symbolXCount = 0;

	// Horizontal check
	for (size_t i = 0; i < rows; i++)
	{
		symbolYCount = symbolXCount = 0;

		for (size_t j = 0; j < cols; j++)
		{
			if (field[i][j] == 'X')
				symbolXCount++;
			if (field[i][j] == 'Y')
				symbolYCount++;
		}

		if (symbolXCount == 3)
			return Winner::Player1;

		if (symbolYCount == 3)
			return Winner::Player2;
	}

	// Vertical check
	for (size_t j = 0; j < cols; j++)
	{
		symbolYCount = symbolXCount = 0;

		for (size_t i = 0; i < rows; i++)
		{
			if (field[i][j] == 'X')
				symbolXCount++;
			if (field[i][j] == 'Y')
				symbolYCount++;
		}

		if (symbolXCount == 3)
			return Winner::Player1;

		if (symbolYCount == 3)
			return Winner::Player2;
	}

	// Diagonal up-left/down-right check
	symbolYCount = symbolXCount = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i == j && field[i][j] == 'X')
				symbolXCount++;
			if (i == j && field[i][j] == 'Y')
				symbolYCount++;
		}
	}

	if (symbolXCount == 3)
		return Winner::Player1;

	if (symbolYCount == 3)
		return Winner::Player2;

	// Diagonal down-left/up-right check
	symbolYCount = symbolXCount = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i + j == rows - 1 && field[i][j] == 'X')
				symbolXCount++;
			if (i + j == rows - 1 && field[i][j] == 'Y')
				symbolYCount++;
		}
	}

	if (symbolXCount == 3)
		return Winner::Player1;

	if (symbolYCount == 3)
		return Winner::Player2;

	// Draw check
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (field[i][j] == '*')
				return Winner::NoOne;

	return Winner::Draw;
}

void ShowWinner(const Winner& winner)
{
	switch (winner)
	{
	case Winner::Draw:
		cout << "!!! DRAW !!!\n";
		break;
	case Winner::Player1:
		cout << "!!! PLAYER #1 WIN !!!\n";
		break;
	case Winner::Player2:
		cout << "!!! PLAYER #2 WIN !!!\n";
		break;
	}
}