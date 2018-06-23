#pragma once

#include <iostream>
#include "Game.h"
#include "CardDeck.h"
#include <vector>
#include <string>

using namespace std;

class GameDisplay
{
private:

	bool insertCoin();
	void promptPlayerAction();
	void endGame();
	void displayCards();
	void displayBestHand();
	int getPayout();
	Card getCard();
	void initGame();
	int getPlayerCoinBalance();
	void deal();
	void displayGameInfo();
	Game game;

	map<Game::CARD_HANDS, string> cardHandToStringMap = {
		{Game::ROYAL_FLUSH, "Royal Flush"},
		{Game::STRAIGHT_FLUSH, "Straight Flush"},
		{Game::FOUR_OF_A_KIND, "Four of a kind"},
		{Game::FULL_HOUSE, "Full House"},
		{Game::FLUSH, "Flush"},
		{Game::STRAIGHT, "Straight"},
		{Game::THREE_OF_A_KIND, "Three of a kind"},
		{Game::TWO_PAIR, "Two Pair"},
		{Game::JACKS_OR_BETTER, "Jacks or better"},
		{Game::NONE, "None"}
	};

public:
	GameDisplay();
	~GameDisplay();
	void startGame();
	string findBestHand();
};

