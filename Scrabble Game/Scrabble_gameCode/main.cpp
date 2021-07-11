#include <bits/stdc++.h>
#include <string>
#include "Game.h"
#include "Board.h"
#include "Dictionary.h"
#include "Player.h"
#include "Tilebag.h"

using namespace std;
typedef long long int ll;

int main()
{
    Game g;
    int chc;
    do
    {
        cout << "1. Read Instructions for Game\n";
        cout << "2. Play Game\n";
        cout << "3. Exit\n";
        cout << "Enter your choice : ";
        cin >> chc;
        if (chc == 1)
        {
            g.instructions();
        }
        else if (chc == 2)
        {
            g.playgame();
        }
        else if (chc == 3)
        {
            exit(0);
        }
        else if (!cin || chc > 3 || chc < 1)
        {
            cout << "Choose a vaild option\n"
                 << endl;
            cout << "---------------------------------\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (chc != 2);
    return 0;
}