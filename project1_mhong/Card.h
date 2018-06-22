#pragma once
#include <iostream>
#include <map>
using namespace std;

class Card
{
public:
	enum SUIT
	{
		CLUB = 0,
		HEART = 1,
		SPADE = 2,
		DIAMOND = 3
	};

	enum VAL
	{
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE
	};

	map<int, string> suitMap = {
		{ 0, "CLUB" },
		{ 1, "HEART" },
		{ 2, "SPADE" },
		{ 3, "DIAMOND" }
	};

	map<int, string> valMap = {
		{0, "TWO" },
		{1,"THREE"},
		{2,"FOUR"},
		{3, "FIVE"},
		{4,"SIX"},
		{5,"SEVEN"},
		{6,"EIGHT"},
		{7,"NINE"},
		{8,"TEN"},
		{9,"JACK"},
		{10,"QUEEN"},
		{11,"KING"},
		{12,"ACE"}
	};

	Card::SUIT getSuit() const { return suit; }
	void setSuit(Card::SUIT val) { suit = val; }
	Card::VAL getVal() const { return val; }
	void setVal(Card::VAL val) { val = val; }
private:
	SUIT suit;
	VAL val;
	Card();

public:

	Card(SUIT suit, VAL val);
	~Card();
	string toString();
};

