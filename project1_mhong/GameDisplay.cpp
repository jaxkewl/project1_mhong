#include "stdafx.h"
#include "GameDisplay.h"





void GameDisplay::insertCoin()
{
	game.clearPlayerBet();
	int coinsInserted = 0;
	//cout << "Player's current coin count: " << getPlayerCoinBalance() << endl;
	cout << "Insert how many coins?" << endl;
	cin >> coinsInserted;

	for (int i = 0; i < coinsInserted; ++i)
	{
		game.insertCoin();
	}

}

void GameDisplay::promptPlayerAction()
{
	int actionNum = 0;
	bool one = false, two = false, three = false, four = false, five = false;
	int cntr = 0;
	while (true)
	{
		if (cntr == 3)
		{
			endGame();
			break;
		}
		cout << "Enter card number to hold or 6 to end" << endl;
		cin >> actionNum;
		if (!one && actionNum == 1)
		{
			++cntr;
			one = true;
			game.player.swapCards(game.getCard(), 1);

		}
		else if (!two && actionNum == 2)
		{
			++cntr;
			two = true;
			game.player.swapCards(game.getCard(), 2);
		}
		else if (!three && actionNum == 3)
		{
			++cntr;
			three = true;
			game.player.swapCards(game.getCard(), 3);
		}
		else if (!four && actionNum == 4)
		{
			++cntr;
			four = true;
			game.player.swapCards(game.getCard(), 4);
		}
		else if (!five && actionNum == 5)
		{
			++cntr;
			five = true;
			game.player.swapCards(game.getCard(), 5);
		}
		else if (actionNum >= 3)
		{
			endGame();
			break;
		}
		displayCards();
		displayBestHand();
	}
}

void GameDisplay::endGame()
{
	int payout = getPayout();
	int playerBalance = game.player.getCointCount();
	cout << "Ending game, adding " << payout << " to player account" << endl;
	int winnings = payout + playerBalance;
	game.player.setCointCount(winnings);
	cout << "Player now has " << game.player.getCointCount() << endl;

}

void GameDisplay::displayCards()
{
	list<Card> cards = game.player.getCards();
	if (!cards.empty()) cout << "Player's current cards" << endl;
	int i = 1;

	for (list<Card>::iterator c = cards.begin();
		c != cards.end();
		++c)
	{
		cout << std::to_string(i).c_str() << ") ";
		cout << c->toString().c_str() << endl;
		i++;
	}
}

void GameDisplay::displayBestHand()
{
	string bestHand = findBestHand();
	cout << "Best Hand: " << bestHand.c_str() << endl;
	cout << "Payout " << getPayout() << endl;
}

int GameDisplay::getPayout()
{
	return game.getWinMultiplier() * game.getPlayerBet();
}

Card GameDisplay::getCard()
{
	return game.getCard();
}

void GameDisplay::initGame()
{
	//insertCoin();
	//game.getCardDeck().shuffle();
	//game.getCardDeck().shuffle();

	displayGameInfo();
	while (true)
	{
		if (game.player.getCointCount() <= 0)
		{
			cout << "Player has no more coins, thanks for playing" << endl;
			break;
		}
		insertCoin();
		//displayGameInfo();
		deal();
		displayGameInfo();
		promptPlayerAction();
		//game.getCardDeck().displayCards();
	}

}

int GameDisplay::getPlayerCoinBalance()
{
	return game.player.getCointCount();
}

void GameDisplay::deal()
{
	game.deal();
}



void GameDisplay::displayGameInfo()
{
	cout << "Player's coin balance:" << getPlayerCoinBalance() << endl;
	cout << "Player's bet: " << game.getPlayerBet() << endl;

	displayCards();
	displayBestHand();
}

GameDisplay::GameDisplay()
{
}


GameDisplay::~GameDisplay()
{
}


void GameDisplay::startGame()
{
	cout << "Starting Video Poker Game" << endl;
	initGame();

}

string GameDisplay::findBestHand()
{
	return cardHandToStringMap[game.findBestHand()];
}
