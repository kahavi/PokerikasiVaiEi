#include "card.h"

Card::Card()
{

}

Card::Card(string setSuit, string setValue)
{
    suit = setSuit;
    value = setValue;
    cout << "Created " + value + " of " + suit << endl;
}

Card::~Card(){}

string Card::getSuit()
{
    return suit;
}

string Card::getValue()
{
    return value;
}
