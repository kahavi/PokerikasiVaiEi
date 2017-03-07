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
        cout << addedCard.getValue() + " of " + addedCard.getSuit() << endl;
        hand[cardIndex] = addedCard;
        cardIndex++;

    }else
        cout << "Hand is full" << endl;
}

void Hand::analyzeHand()
{
    //Reset all checks
    flush = false;
    straight = false;
    royalStraight = false;
    straightFlush = false;
    royalFlush = false;
    fourOfAKind = false;
    threeOfAKind = false;
    twoPair = false;
    onePair = false;
    fullHouse = false;
    highestCard = -1;

    //Lets first determine how many cards of each value and suit we have
    //Order is the same we used before:
    string faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int cardsByValue[13] = {0};
    int cardsBySuit[4] = {0};
    int straightCounter = 0;

    for(int i = 0; i < CARDS_IN_HAND; i++)
    {
        for(int j = 0; j < 13; j++)
        //C++ std::string::compare returns 0 when the strings are the same
        if(hand[i].getValue().compare(faces[j]) == 0) cardsByValue[j] += 1;
    }

    for(int i = 0; i < CARDS_IN_HAND; i++)
    {
        for(int j = 0; j < 4; j++)
        if(hand[i].getSuit().compare(suits[j]) == 0) cardsBySuit[j] += 1;
    }


    /////////////////////////////////////////////////////
    ///// This was used for debugging ///////////////////
    /*
    cout << "Cards by value:" <<endl;
    for (int i = 0; i < 13; i++)
        cout << cardsByValue[i] << endl;
    cout << "Cards by suit:" <<endl;
    for (int i = 0; i < 4; i++)
        cout << cardsBySuit[i] << endl;
    */


    //Checking for hands
    //Flush
    for(int i = 0; i < 4; i++)
    {
        if(cardsBySuit[i] == 5) flush = true;
    }

    //Straight
    for(int i = 0; i < 13; i++)
    {
        if(cardsByValue[i] > 0) straightCounter += 1;
        else straightCounter = 0;

        if(straightCounter == 5)
        {
            straight = true;
            break;
        }

        //Need to check if we're at the end of the check and the counter is at 4, in case of high Ace
        if(straightCounter == 4 && i == 12 && cardsByValue[0] > 0)
        {
            //Royal Straight is not a hand, but we use it to check for a Royal Flush
            royalStraight = true;
        }
    }

    //Straight Flush
    if(flush && straight)
    {
        straightFlush = true;
    }

    //Royal Flush
    if(flush && royalStraight)
    {
        royalFlush = true;
    }

    //Four of a kind
    for(int i = 0; i < 13; i++)
    {
        if(cardsByValue[i] == 4) fourOfAKind = true;
    }

    //Three of a kind
    for(int i = 0; i < 13; i++)
    {
        if(cardsByValue[i] == 3) threeOfAKind = true;
    }

    //Pairs
    for(int i = 0; i < 13; i++)
    {
        //Only check if we have found a pair on a previous loop
        if(cardsByValue[i] >= 2 && onePair) twoPair = true;
        //If we have a three of a kind, we don't want to check for pairs
        if(cardsByValue[i] >= 2 && !threeOfAKind) onePair = true;
    }

    //Full house
    if(threeOfAKind && onePair) fullHouse = true;

    //Highest card
    for(int i = 0; i < 13; i++)
    {
        if(cardsByValue[i] > 0 && highestCard != 0)
        {
            highestCard = i;
        }
    }


    if(royalFlush)          cout << "Royal Flush" << endl;
    else if(straightFlush)  cout << "Straight Flush" << endl;
    else if(fourOfAKind)    cout << "Four of a kind" << endl;
    else if(fullHouse)      cout << "Full house" << endl;
    else if(flush)          cout << "Flush" << endl;
    else if(straight)       cout << "Straight" << endl;
    else if(threeOfAKind)   cout << "Three of a kind" << endl;
    else if(twoPair)        cout << "Two pair" << endl;
    else if(onePair)        cout << "Pair" << endl;
    else cout << "Highest card: " + faces[highestCard] << endl;
}
