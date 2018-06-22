#pragma once
#include "Player.h"
#include "CardDeck.h"
#include <map>
#include <list>
using namespace std;

class Game
{

public:

	enum CARD_HANDS
	{
		ROYAL_FLUSH,
		STRAIGHT_FLUSH,
		FOUR_OF_A_KIND,
		FULL_HOUSE,
		FLUSH,
		STRAIGHT,
		THREE_OF_A_KIND,
		TWO_PAIR,
		JACKS_OR_BETTER,
		NONE
	};

	void shuffle();

	int getPlayerBet() const
	{
		return playerBet;
	}
	void setPlayerBet(int val)
	{
		playerBet = val;
	}
private:
	map<CARD_HANDS, int> winMultiplier = {
		{ROYAL_FLUSH, 250},
		{STRAIGHT_FLUSH, 50 },
		{ FOUR_OF_A_KIND, 25 },
		{ FULL_HOUSE, 9 },
		{ FLUSH, 6 },
		{ STRAIGHT, 4 },
		{ THREE_OF_A_KIND,3 },
		{ TWO_PAIR, 2 },
		{ JACKS_OR_BETTER, 1 },
		{NONE, 0 }
	};
	map<Card::VAL, int> lowestStraightVal = {
		{Card::ACE, 0},
		{Card::TWO, 1},
		{Card::THREE, 2},
		{Card::FOUR, 3},
		{Card::FIVE, 4 },
		{Card::SIX, 5},
		{Card::SEVEN, 6},
		{Card::EIGHT, 7},
		{Card::NINE, 8},
		{Card::TEN, 9},
		{Card::JACK, 10},
		{Card::QUEEN, 11},
		{Card::KING, 12}
	};

	CardDeck cardDeck;
	bool isROYAL_FLUSH();
	bool isSTRAIGHT_FLUSH();
	bool isFOUR_OF_A_KIND();
	bool isFULL_HOUSE();
	bool isFLUSH();
	bool isSTRAIGHT();
	bool isTHREE_OF_A_KIND();
	bool isTWO_PAIR();
	bool isJACKS_OR_BETTER();
	int playerBet = 0;

public:
	Player player;
	Game();
	~Game();
	list<Card> deal();
	void insertCoin();
	void clearPlayerBet();
	Card getCard();

	void setPlayer(Player val)
	{
		player = val;
	}
	CardDeck getCardDeck() const
	{
		return cardDeck;
	}
	void setCardDeck(CardDeck val)
	{
		cardDeck = val;
	}
	Game::CARD_HANDS findBestHand();
	int getWinMultiplier();
};

