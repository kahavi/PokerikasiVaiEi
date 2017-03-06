#include "hand.h"

Hand::Hand()
{
    cardIndex = 0;
}

Hand::~Hand(){}

void Hand::addCard(Card addedCard)
{
    if(cardIndex < CARDS_IN_HAND)
    {
        cout << "Added " + addedCard.getValue() + " of " + addedCard.getSuit() << endl;
        hand[cardIndex] = addedCard;
        cardIndex++;

    }else
        cout << "Hand is full" << endl;
}

void Hand::analyzeHand()
{

}
