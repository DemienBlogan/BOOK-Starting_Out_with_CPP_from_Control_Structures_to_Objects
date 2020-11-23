#pragma once

#include "Player.h"

class Game
{
private:
	Player user;
	Player computer;
	bool isPlaying = true;
	int rouds = 0;

	bool AskUserAboutToss() const;
	void ClearBuffer() const;

public:
	Game();
	void PlayRound();
	bool IsPlaying() const;
	void ShowUserPoints() const;
	void ShowComputerPoints() const;
	void ShowWinner() const;
};