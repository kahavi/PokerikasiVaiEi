#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "card.h"
#include <iostream>
#include <algorithm>
#include <time.h>

#define NUMBER_OF_CARDS 52

using namespace std;

class DeckOfCards
{
public:
    DeckOfCards();
    ~DeckOfCards();
    Card draw();
    void shuffle();
protected:
    Card deck[NUMBER_OF_CARDS];
    int cardIndex;
};

#endif // DECKOFCARDS_H
