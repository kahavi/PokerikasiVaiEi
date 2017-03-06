#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;


class Card
{
public:
    Card();
    Card(string setSuit, string setValue);
    ~Card();
    string getSuit();
    string getValue();
    void setSuit(string setSuit);
    void setValue(string setValue);
protected:
    string suit;
    string value;
};

#endif // CARD_H
