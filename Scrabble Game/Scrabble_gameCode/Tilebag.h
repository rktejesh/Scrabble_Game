#ifndef __Tilebag
#define __Tilebag

#include <bits/stdc++.h>
// #include "Game.h"

using namespace std;
typedef long long int ll;

// class Tilebag : public Game
class Tilebag
{
protected:
    map<char, int> letterValueMap;

public:
    Tilebag();
    void assigningvalue();
    int getletterval(char c);
};

#endif
