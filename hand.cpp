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

struct Hand::handValue{
    bool royalFlush;
    bool straightFlush;
    bool fourOfAKind;
    bool fullHouse;
    bool flush;
    bool straight;
    bool threeOfAKind;
    bool twoPair;
    bool onePair;
    bool royalStraight;
    handValue() {
        flush = straight = royalStraight = straightFlush = royalFlush = fourOfAKind = threeOfAKind = twoPair = onePair = fullHouse = false;
    }
};

void Hand::analyzeHand()
{
    //Reset all flags by calling the constructor of handValue
    handValue hv;
    //0 is Ace, so set to -1
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
        if(cardsBySuit[i] == 5) hv.flush = true;
    }

    //Straight
    for(int i = 0; i < 13; i++)
    {
        if(cardsByValue[i] > 0) straightCounter += 1;
        else straightCounter = 0;

        if(straightCounter == 5)
        {
            hv.straight = true;
            break;
        }

        //Need to check if we're at the end of the check and the counter is at 4, in case of high Ace
        if(straightCounter == 4 && i == 12 && cardsByValue[0] > 0)
        {
            //Royal Straight is not a hand, but we use it to check for a Royal Flush
            hv.royalStraight = true;
        }
    }

    //Royal Flush
    if(hv.flush && hv.royalStraight)
    {
        hv.royalFlush = true;
    }

    //Straight Flush
    if(hv.flush && hv.straight)
    {
        hv.straightFlush = true;
    }

    //Four of a kind
    for(int i = 0; i < 13; i++)
    {
        if(cardsByValue[i] == 4) hv.fourOfAKind = true;
    }

    //Three of a kind
    for(int i = 0; i < 13; i++)
    {
        if(cardsByValue[i] == 3) hv.threeOfAKind = true;
    }

    //Pairs
    for(int i = 0; i < 13; i++)
    {
        //Only check if we have found a pair on a previous loop
        if(cardsByValue[i] >= 2 && hv.onePair) hv.twoPair = true;
        //If we have a three of a kind, we don't want to check for pairs
        if(cardsByValue[i] >= 2 && !hv.threeOfAKind) hv.onePair = true;
    }

    //Full house
    if(hv.threeOfAKind && hv.onePair) hv.fullHouse = true;

    //Highest card
    for(int i = 0; i < 13; i++)
    {
        if(cardsByValue[i] > 0 && highestCard != 0)
        {
            highestCard = i;
        }
    }

    if(hv.royalFlush)          cout << "Royal Flush" << endl;
    else if(hv.straightFlush)  cout << "Straight Flush" << endl;
    else if(hv.fourOfAKind)    cout << "Four of a kind" << endl;
    else if(hv.fullHouse)      cout << "Full house" << endl;
    else if(hv.flush)          cout << "Flush" << endl;
    else if(hv.straight)       cout << "Straight" << endl;
    else if(hv.threeOfAKind)   cout << "Three of a kind" << endl;
    else if(hv.twoPair)        cout << "Two pair" << endl;
    else if(hv.onePair)        cout << "Pair" << endl;
    else cout << "Highest card: " + faces[highestCard] << endl;
}
