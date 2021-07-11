#ifndef __Player
#define __Player

#include <bits/stdc++.h>
// #include "Game.h"

using namespace std;
typedef long long int ll;

// class Player : public Game
class Player
{
    string name;
    int point;
    int pointvalue;
    int totalpoint;

public:
    char set[7];
    Player();
    void setname();
    string tellname();
    int addpoints(int *val);
    int tellpoint();
    void makeset();
    void deleteTile(char c);
};

#endif
