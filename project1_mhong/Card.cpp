#include "stdafx.h"
#include "Card.h"

Card::Card(SUIT suit, VAL val) : suit(suit), val(val)
{
}

Card::~Card()
{
}

string Card::toString()
{
	string ret = valMap[getVal()];
	ret.append(" of ");
	ret.append(suitMap[getSuit()]);
	return ret;
}
