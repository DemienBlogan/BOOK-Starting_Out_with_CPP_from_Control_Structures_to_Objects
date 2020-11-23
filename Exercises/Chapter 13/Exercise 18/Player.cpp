#include "Player.h"

Player::Player(int dies, int sides)
{
	for (int die = 0; die < dies; die++)
		this->dies.push_back(Die(sides));
}

int Player::GetPoints() const
{
	return points;
}

void Player::Toss()
{
	for (size_t die = 0; die < dies.size(); die++)
	{
		dies[die].Toss();
		points += dies[die].GetValue();
	}
}