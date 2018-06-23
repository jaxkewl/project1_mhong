#pragma once
#include "Card.h"
#include <iostream>
#include <list>

using namespace std;
class Player
{

public:
	static const int INITIAL_COINT_COUNT = 175;

	int getCointCount() const
	{
		return cointCount;
	}
	void setCointCount(int val)
	{
		cointCount = val;
	}
	list<Card> getCards() const
	{
		return cards;
	}
	void setCards(const std::list<Card>& val)
	{
		cards = val;
	}
private:
	list<Card> cards;
	int cointCount = INITIAL_COINT_COUNT;

public:
	Player();
	~Player();
	void addCard(const Card & card);
	void swapCards(const Card card, int position);
};

