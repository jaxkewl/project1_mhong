#pragma once

#include <list>
#include "Card.h"
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class CardDeck
{
public:
	static const int DECK_SIZE = 52;

private:
	list<Card> cards;
	

public:
	CardDeck();
	~CardDeck();
	void shuffle();
	Card getCard();
	list<Card> getCards();

};

