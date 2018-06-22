#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}



void Player::displayPlayerInfo()
{
	cout << "Coin Balance: " << getCointCount() << endl;

}

void Player::addCard(const Card & card)
{
	cards.push_back(card);
}

void Player::swapCards(const Card card, int position)
{
	list<Card> newCards;
	int cntr = 0;
	for (auto itr = cards.begin(); itr != cards.end(); ++itr)
	{
		cntr++;
		if (cntr == position) newCards.push_back(card);
		else newCards.push_back(*itr);
	}
	setCards(newCards);
}

