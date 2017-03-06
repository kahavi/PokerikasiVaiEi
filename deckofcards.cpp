#include "deckofcards.h"

DeckOfCards::DeckOfCards()
{
    //Generate the deck
    string faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for(int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        deck[i] = Card(suits[i / 13], faces[i % 13]);
    }
    //Shuffle the deck of cards
    this->shuffle();
}

DeckOfCards::~DeckOfCards(){}

//Returns a card at index value of cardIndex
Card DeckOfCards::draw()
{
    Card cardToDraw = deck[cardIndex];
    cardIndex++;
    //if we reach the end of the deck, shuffle
    if(cardIndex >= NUMBER_OF_CARDS) this->shuffle();
    return cardToDraw;
}

//Shuffle the deck
void DeckOfCards::shuffle()
{
    //Change the random seed so we don't get the same deck every time
    srand(time(0));
    random_shuffle(std::begin(deck), std::end(deck));
    cout << "Deck shuffled" << endl;
    cardIndex = 0;
}
