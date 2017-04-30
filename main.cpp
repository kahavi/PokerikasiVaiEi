/**
 *  This is a program that deals a set number of hands,
 *  and analyses if they have any poker hands present.
 *
 *  Made by Teemu Kolu
 **/


#include <iostream>
#include "deckofcards.h"
#include "hand.h"

//Anything more than 10 hands will cause a potential error,
//where the same card can be dealt again
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

    //Analyse each hand
    for(int i = 0; i < NUMBER_OF_HANDS; i++)
    {
        cout << "Hand " + to_string(i) + ": ";
        hands[i].analyzeHand();
    }

    return 0;
}

