#include "stdafx.h"
#include "CardDeck.h"
#include <vector>

CardDeck::CardDeck()
{
	shuffle();
}


CardDeck::~CardDeck()
{

}

Card CardDeck::getCard()
{
	if (!cards.empty())
	{
		Card copyCard(*cards.begin());
		cards.pop_front();
		return copyCard;
	}
	Card c(Card::HEART, Card::TWO);
	return c;
}

list<Card> CardDeck::getCards()
{
	if (cards.empty())
	{
		shuffle();
	}
	return cards;
}

void CardDeck::shuffle()
{
	//use the shuffle properties of a vector and then
	//copy that into a list of cards.
	cout << "club: " << Card::CLUB << " heart: " << Card::HEART << " spade: " << Card::SPADE << " diamond: " << Card::DIAMOND << endl;
	vector<Card> localCards;
	int s = Card::CLUB;
	for (; s <= Card::DIAMOND; s++)
	{
		Card::SUIT suit = static_cast<Card::SUIT>(s);
		for (int v = Card::TWO; v <= Card::ACE; v++)
		{
			Card::VAL val = static_cast<Card::VAL>(v);
			localCards.push_back(Card(suit, val));
		}
	}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
	std::shuffle(localCards.begin(), localCards.end(), e);

	cards.clear();
	for (auto itr = localCards.begin(); itr != localCards.end(); ++itr)
	{
		cards.push_back(*itr);
	}
}
