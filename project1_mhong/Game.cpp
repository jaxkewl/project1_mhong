#include "stdafx.h"
#include "Game.h"


bool Game::isFULL_HOUSE()
{
	return isTHREE_OF_A_KIND() && isTWO_PAIR();
}

bool Game::isFLUSH()
{
	bool allSameSuit = false;
	list<Card> cards = player.getCards();
	int hearts = 0, clubs = 0, diamonds = 0, spades = 0;
	for (auto citr = cards.begin(); citr != cards.end(); ++citr)
	{
		Card card = *citr;
		if (card.getSuit() == Card::CLUB) ++clubs;
		if (card.getSuit() == Card::DIAMOND) ++diamonds;
		if (card.getSuit() == Card::SPADE) ++spades;
		if (card.getSuit() == Card::HEART) ++hearts;
	}

	bool matchSuit = spades == 5 || hearts == 5 || diamonds == 5 || clubs == 5;
	return matchSuit;
}

bool Game::isSTRAIGHT()
{
	//find the lowest card
	int lowestValNum = lowestStraightVal[Card::KING];
	list<Card> cards = player.getCards();
	for (auto citr = cards.begin(); citr != cards.end(); ++citr)
	{
		int temp = lowestStraightVal[citr->getVal()];
		if (temp < lowestValNum) lowestValNum = temp;
	}
	if (lowestValNum >= 9) return false;

	//now determine if the numbers are sequential
	int startNum = lowestValNum;
	bool foundNext = false;
	for (int i = startNum; i < startNum + 5; ++i)
	{
		for (auto citr = cards.begin(); citr != cards.end(); ++citr)
		{
			foundNext = false;
			if (citr->getVal() == i)
			{
				foundNext = true;
				break;
			}
			if (!foundNext) break;
		}
	}
	return foundNext;
}

bool Game::isTHREE_OF_A_KIND()
{
	//Three cards of the same rank and two cards of two other ranks that is 
	//not a full house or four of a kind.For example, 5 of hearts, 5 of clubs, 
	//5 of spades, 7 of clubs, 9 of diamonds.

	int aces = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, sevens = 0, eights = 0,
		nines = 0, tens = 0, jacks = 0, queens = 0, kings = 0;
	list<Card> cards = player.getCards();
	for (auto citr = cards.begin(); citr != cards.end(); ++citr)
	{
		Card card = *citr;
		if (card.getVal() == Card::ACE) ++aces;
		if (card.getVal() == Card::TWO) ++twos;
		if (card.getVal() == Card::THREE) ++threes;
		if (card.getVal() == Card::FOUR) ++fours;
		if (card.getVal() == Card::FIVE) ++fives;
		if (card.getVal() == Card::SIX) ++sixes;
		if (card.getVal() == Card::SEVEN) ++sevens;
		if (card.getVal() == Card::EIGHT) ++eights;
		if (card.getVal() == Card::NINE) ++nines;
		if (card.getVal() == Card::TEN) ++tens;
		if (card.getVal() == Card::JACK) ++jacks;
		if (card.getVal() == Card::QUEEN) ++queens;
		if (card.getVal() == Card::KING) ++kings;
	}

	bool matchVal = (aces == 3 | twos == 3 | threes == 3 | fours == 3 | fives == 3 | sixes == 3 | sevens == 3 | eights == 3 | nines == 3 | tens == 3 | jacks == 3 | queens == 3 | kings == 3);
	return matchVal;
}

bool Game::isTWO_PAIR()
{
	int aces = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, sevens = 0, eights = 0,
		nines = 0, tens = 0, jacks = 0, queens = 0, kings = 0;
	list<Card> cards = player.getCards();
	for (auto citr = cards.begin(); citr != cards.end(); ++citr)
	{
		Card card = *citr;
		if (card.getVal() == Card::ACE) ++aces;
		if (card.getVal() == Card::TWO) ++twos;
		if (card.getVal() == Card::THREE) ++threes;
		if (card.getVal() == Card::FOUR) ++fours;
		if (card.getVal() == Card::FIVE) ++fives;
		if (card.getVal() == Card::SIX) ++sixes;
		if (card.getVal() == Card::SEVEN) ++sevens;
		if (card.getVal() == Card::EIGHT) ++eights;
		if (card.getVal() == Card::NINE) ++nines;
		if (card.getVal() == Card::TEN) ++tens;
		if (card.getVal() == Card::JACK) ++jacks;
		if (card.getVal() == Card::QUEEN) ++queens;
		if (card.getVal() == Card::KING) ++kings;
	}
	int pairCount = 0;
	if (aces == 2) ++pairCount;
	if (twos == 2) ++pairCount;
	if (threes == 2) ++pairCount;
	if (fours == 2) ++pairCount;
	if (fives == 2) ++pairCount;
	if (sixes == 2) ++pairCount;
	if (sevens == 2) ++pairCount;
	if (eights == 2) ++pairCount;
	if (nines == 2) ++pairCount;
	if (tens == 2) ++pairCount;
	if (jacks == 2) ++pairCount;
	if (queens == 2) ++pairCount;
	if (kings == 2) ++pairCount;

	return pairCount == 2;
}

bool Game::isJACKS_OR_BETTER()
{
	//Exactly one pair of Jacks, Queens, Kings, 
	//or Aces, and nothing else of interest.
	int aces = 0, jacks = 0, queens = 0, kings = 0;
	list<Card> cards = player.getCards();
	for (auto citr = cards.begin(); citr != cards.end(); ++citr)
	{
		Card card = *citr;
		if (card.getVal() == Card::ACE) ++aces;
		if (card.getVal() == Card::JACK) ++jacks;
		if (card.getVal() == Card::QUEEN) ++queens;
		if (card.getVal() == Card::KING) ++kings;
	}
	if (aces == 2) return true;
	if (jacks == 2) return true;
	if (queens == 2) return true;
	if (kings == 2) return true;

	return false;
}

Game::Game()
{

}


Game::~Game()
{

}

list<Card> Game::deal()
{
	//remove the first 5 cards from the deck.
	list<Card> firstCards;
	for (int i = 0; i < 5; ++i)
	{
		firstCards.push_back(cardDeck.getCard());
	}
	player.setCards(firstCards);
	return firstCards;

}

void Game::insertCoin()
{
	++playerBet;
	int currentPlayerCoinCount = player.getCointCount();
	player.setCointCount(--currentPlayerCoinCount);
}

void Game::clearPlayerBet()
{
	playerBet = 0;
}

Card Game::getCard()
{
	Card c(cardDeck.getCard());

	return c;
}



Game::CARD_HANDS Game::findBestHand()
{
	//brute force way to determine the player's best hand
	if (isROYAL_FLUSH()) return ROYAL_FLUSH;
	if (isSTRAIGHT_FLUSH()) return STRAIGHT_FLUSH;
	if (isFOUR_OF_A_KIND()) return FOUR_OF_A_KIND;
	if (isFULL_HOUSE()) return FULL_HOUSE;
	if (isFLUSH()) return FLUSH;
	if (isSTRAIGHT()) return STRAIGHT;
	if (isTHREE_OF_A_KIND()) return THREE_OF_A_KIND;
	if (isTWO_PAIR()) return TWO_PAIR;
	if (isJACKS_OR_BETTER()) return JACKS_OR_BETTER;
	return NONE;
}

int Game::getWinMultiplier()
{
	Game::CARD_HANDS bestHand = findBestHand();
	return winMultiplier[bestHand];
}


void Game::shuffle()
{

}

bool Game::isROYAL_FLUSH()
{
	//Royal Flush: 10, Jack, King, Queen, Ace, all of the same suit. 
	bool found10 = false, foundJack = false, foundKing = false, foundQueen = false, foundAce = false;
	list<Card> cards = player.getCards();
	for (auto citr = cards.begin(); citr != cards.end(); ++citr)
	{
		Card card = *citr;
		if (card.getVal() == Card::ACE) foundAce = true;
		if (card.getVal() == Card::KING) foundKing = true;
		if (card.getVal() == Card::QUEEN) foundQueen = true;
		if (card.getVal() == Card::JACK) foundJack = true;
		if (card.getVal() == Card::TEN) found10 = true;
	}

	bool matchVal = foundJack && foundAce && found10 && foundKing && foundQueen;
	bool matchSuit = isFLUSH();
	return matchVal && matchSuit;
}

bool Game::isSTRAIGHT_FLUSH()
{
	// Five cards in rank sequence, all of the same suit, but not a royal flush.
	// For example, Ace, 2, 3, 4, 5 all hearts

	return isSTRAIGHT() && isFLUSH();
}

bool Game::isFOUR_OF_A_KIND()
{
	// For cards of the same rank. For example, 3 of hearts, 3 of diamonds, 
	//3 of spades, and 3 of clubs

	int aces = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, sevens = 0, eights = 0,
		nines = 0, tens = 0, jacks = 0, queens = 0, kings = 0;
	list<Card> cards = player.getCards();
	for (auto citr = cards.begin(); citr != cards.end(); ++citr)
	{
		Card card = *citr;
		if (card.getVal() == Card::ACE) ++aces;
		if (card.getVal() == Card::TWO) ++twos;
		if (card.getVal() == Card::THREE) ++threes;
		if (card.getVal() == Card::FOUR) ++fours;
		if (card.getVal() == Card::FIVE) ++fives;
		if (card.getVal() == Card::SIX) ++sixes;
		if (card.getVal() == Card::SEVEN) ++sevens;
		if (card.getVal() == Card::EIGHT) ++eights;
		if (card.getVal() == Card::NINE) ++nines;
		if (card.getVal() == Card::TEN) ++tens;
		if (card.getVal() == Card::JACK) ++jacks;
		if (card.getVal() == Card::QUEEN) ++queens;
		if (card.getVal() == Card::KING) ++kings;
	}

	bool matchVal = (aces == 4 | twos == 4 | threes == 4 | fours == 4 | fives == 4 | sixes == 4 | sevens == 4 | eights == 4 | nines == 4 | tens == 4 | jacks == 4 | queens == 4 | kings == 4);
	return matchVal;
}
