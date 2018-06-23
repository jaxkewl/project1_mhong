#include "stdafx.h"
#include "Player.h"

//default constructor
Player::Player()
{
}

//default destructor
Player::~Player()
{
}

//add a card to the players current cards
void Player::addCard(const Card & card)
{
	cards.push_back(card);
}

//swap out the card located at the position with the card
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

