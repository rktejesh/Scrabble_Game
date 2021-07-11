#include "Board.h"
#include "Tilebag.h"
// #include "Game.h"

Board ::Board()
{
    
}

//This function initialize the board with blanks
void Board ::createboard()
{
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= 15; j++)
        {
            gboard[i][j] = ' ';
        }
    }
}

void Board ::printboard()
{
    #ifdef _WIN32
	    #ifdef _WIN64
	        system("CLS");
	    #endif
	#else
	    system("clear");
	#endif
    cout << "        1       2       3       4       5       6       7       8       9      10      11      12      13      14      15   " << endl;
    for (int i = 1; i <= 15; i++)
    {
        cout << "    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
        if (i < 10)
        {
            cout << i << "   |   ";
        }
        else
        {
            cout << i << "  |   ";
        }
        for (int j = 1; j <= 15; j++)
        {
            cout << gboard[i][j] << "   |   ";
        }
        cout << endl;
    }
    cout << "    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
}

//This function will take letter, x and y coordinate as arguments and will place it on board at (x,y).
void Board ::setchar(char c, int x, int y)
{
    gboard[x][y] = c;
    // cout << "setting " << c << " at position (" << x << "," << y << ")" << endl;
}

//This function is to print the word that player made in horizontal
string Board ::horizontal(int fixed, int start, int end)
{
    int j = 0;
    makeword[j] = gboard[start][fixed];
    cout << "Your word is" << endl;
    for (int i = start + 1; i <= end; i++)
    {
        makeword[j + 1] = makeword[j] + gboard[i][fixed];
        j++;
        size1 = j;
    }
    cout << makeword[j] << endl;
    return makeword[size1];
}
//This function is to print the word that player made in vertical
string Board ::vertical(int fixed, int start, int end)
{
    int j = 0;
    makeword[j] = gboard[fixed][start];
    cout << "Your word is" << endl;
    for (int i = start + 1; i <= end; i++)
    {
        makeword[j + 1] = makeword[j] + gboard[fixed][i];
        j++;
        size1 = j;
    }
    cout << makeword[j] << endl;
    return makeword[size1];
}

//This function is to store points of horizontal word in array by passing character to getletterval function of Tilebag class
//which in then given as argument in addpoint function of player class to have total points
int* Board ::setpointH(int fixed, int start, int end)
{
    int j = 0;
    for (int i = start; i <= end; i++)
    {
        pointvalue[j] = getletterval(gboard[i][fixed]);
        j++;
        size2 = j;
    }
    pointvalue[size2] = -1;
    return pointvalue;
}

//This function is to store points of vertical word in array by passing character to getletterval function of Tilebag class
//which in then given as argument in addpoint function of Player class to have total points
int* Board ::setpointV(int fixed, int start, int end)
{
    int j = 0;
    for (int i = start; i <= end; i++)
    {
        pointvalue[j] = getletterval(gboard[fixed][i]);
        j++;
        size2 = j;
    }
    pointvalue[size2] = -1;
    return pointvalue;
}