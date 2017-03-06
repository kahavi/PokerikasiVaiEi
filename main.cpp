#include <iostream>
#include "deckofcards.h"
#include "hand.h"

using namespace std;

int main()
{

    DeckOfCards *deck = new DeckOfCards();
    Hand *hand1 = new Hand();
    Hand *hand2 = new Hand();
    Hand *hand3 = new Hand();

    //Deal cards to all hands in turn
    for(int i = 0; i < 6; i++)
    {
        cout << "Hand 1: ";
        hand1->addCard(deck->draw());
        cout << "Hand 2: ";
        hand2->addCard(deck->draw());
        cout << "Hand 3: ";
        hand3->addCard(deck->draw());
    }

    hand1->analyzeHand();
    hand2->analyzeHand();
    hand3->analyzeHand();

    return 0;
}

