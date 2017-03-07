#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <iostream>

#define CARDS_IN_HAND 5

using namespace std;

class Hand
{
public:
    Hand();
    ~Hand();
    void addCard(Card addedCard);
    void analyzeHand();
protected:
    Card hand[CARDS_IN_HAND];
    int cardIndex;
    bool flush;
    bool straight;
    bool royalStraight;
    bool straightFlush;
    bool royalFlush;
    bool fourOfAKind;
    bool threeOfAKind;
    bool twoPair;
    bool onePair;
    bool fullHouse;
    int highestCard;
};

#endif // HAND_H
