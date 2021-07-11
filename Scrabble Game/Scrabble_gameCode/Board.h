#ifndef __Board
#define __Board

#include <bits/stdc++.h>
#include "Tilebag.h"
// #include "Game.h"

using namespace std;
typedef long long int ll;

class Board : public Tilebag
{
private:
    string makeword[8];
    int pointvalue[8];
    int size1;
    int size2;

public:
    char gboard[16][16];
    Board();
    void createboard();
    void printboard();
    void setchar(char c, int x, int y);
    string horizontal(int fixed, int start, int end);
    string vertical(int fixed, int start, int end);
    int* setpointH(int fixed, int start, int end);
    int* setpointV(int fixed, int start, int end);
};

#endif
