#include "stdafx.h"
#include "GameDisplay.h"




//call this function to prompt the player for the number of coins to play with
bool GameDisplay::insertCoin()
{
	game.clearPlayerBet();
	int coinsInserted = 0;
	//cout << "Player's current coin count: " << getPlayerCoinBalance() << endl;
	cout << "Insert how many coins?" << endl;
	cin >> coinsInserted;
	if (coinsInserted > game.player.getCointCount() ||
		coinsInserted > 5 ||
		coinsInserted < 1)
	{
		cout << "Insert 1 to 5 coins, ending game!" << endl;
		return false;
	}
	for (int i = 0; i < coinsInserted; ++i)
	{
		game.insertCoin();
	}
	return true;
}

//after the cards have been dealt, ask player for their action.
//they can either swap a card out or end the hand, they have a limit of 3 cards
//they can swap out, plus they can not swap out a card that was already 
//swapped out
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
		cout << "Enter card number to switch or 6 to end" << endl;
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

//display the end game metrics
void GameDisplay::endGame()
{
	int payout = getPayout();
	int playerBalance = game.player.getCointCount();
	cout << "Ending game, adding " << payout << " to player account" << endl;
	int winnings = payout + playerBalance;
	game.player.setCointCount(winnings);
	cout << "Player now has " << game.player.getCointCount() << endl;

}

//display the players cards
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

//determine the player's hand if they have any
void GameDisplay::displayBestHand()
{
	string bestHand = findBestHand();
	cout << "Best Hand: " << bestHand.c_str() << endl;
	cout << "Payout " << getPayout() << endl;
}

//calculate the player's payout given the bet and the best hand of the player
int GameDisplay::getPayout()
{
	return game.getWinMultiplier() * game.getPlayerBet();
}

//get a card from the game's deck of cards
Card GameDisplay::getCard()
{
	return game.getCard();
}

//initialize a new game
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
		if (!insertCoin()) break;
		//displayGameInfo();
		deal();
		displayGameInfo();
		promptPlayerAction();
		//game.getCardDeck().displayCards();
	}

}

//get the players coin balance
int GameDisplay::getPlayerCoinBalance()
{
	return game.player.getCointCount();
}

//deal new cards
void GameDisplay::deal()
{
	game.deal();
}


//display the game's current information and state
void GameDisplay::displayGameInfo()
{
	cout << "Player's coin balance:" << getPlayerCoinBalance() << endl;
	cout << "Player's bet: " << game.getPlayerBet() << endl;

	displayCards();
	displayBestHand();
}

//default constructor
GameDisplay::GameDisplay()
{
}

//default destructor
GameDisplay::~GameDisplay()
{
}


//main entry point into the game
void GameDisplay::startGame()
{
	cout << "Starting Video Poker Game" << endl;
	initGame();

}

//convert the best hand to a string display
string GameDisplay::findBestHand()
{
	return cardHandToStringMap[game.findBestHand()];
}
