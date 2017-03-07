#include <iostream>
#include "deckofcards.h"
#include "hand.h"

#define NUMBER_OF_HANDS 3

using namespace std;

int main()
{

    DeckOfCards *deck = new DeckOfCards();
    Hand hands[NUMBER_OF_HANDS];

    //Deal cards to all hands in turn
    for(int j = 0; j < NUMBER_OF_HANDS; j++)
        for(int i = 0; i < 5; i++)
        {
            cout << "Added to Hand " + to_string(j) + ": ";
            hands[j].addCard(deck->draw());
        }

    cout << "Hand 0: ";
    hands[0].analyzeHand();
    cout << "Hand 1: ";
    hands[1].analyzeHand();
    cout << "Hand 2: ";
    hands[2].analyzeHand();

    return 0;
}

