#include "Player.h"
// #include "Game.h"

Player ::Player()
{
    point = 0;
    totalpoint = 0;
    //Initalising set[7] with blank
    for (int i = 0; i < 7; i++)
    {
        set[i] = ' ';
    }
}

//This function sets name of player
void Player ::setname()
{
    cin >> name;
}

//This function return name of player
string Player ::tellname()
{
    return name;
}

//This function add points of each letter which is stored at each index of an array
//and given as argument to it from setpointH or setpointV function of Board class
int Player ::addpoints(int *val)
{
    for (int i = 0; i < 10; i++)
    {
        if ((*(val + i)) == -1)
        {
            return point;
        }
        else
        {
            point = point + (*(val + i));
        }
    }
    return 0;
}

//This function returns Total points of a player
int Player ::tellpoint()
{
    return point;
}

//This function assigns a set of 7 random letters from a to z to each player
void Player ::makeset()
{
    cout << "Preparing Your set...." << endl;
    cout << "Here is Your Set" << endl;
    srand(time(0));
    for (int i = 0; i < 7; i++)
    {
        if (set[i] == ' ')
        {
            set[i] = 'a' + rand() % 26;
        }
        cout << set[i] << " ";
    }
    cout << endl;
}

//This function deletes/removes the letter placed on board by player from set of that player
void Player ::deleteTile(char c)
{
    for (int i = 0; i < 7; i++)
    {
        if (set[i] == c)
        {
            // cout << "Deleting " << c << " from your set" << endl;
            set[i] = ' ';
            break;
        }
    }
}