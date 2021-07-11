#include "Game.h"
#include "Game.h"
#include "Board.h"
#include "Dictionary.h"
#include "Player.h"
#include "Tilebag.h"

void Game ::instructions()
{
    fstream Intro;
    string line, word, name;
    name = "Instruction.txt";
    Intro.open(name.c_str());
    cout << "\n--- INSTRUCTIONS FOR GAME ---\n\n";
    while (getline(Intro, line))
    {
        cout << line << "\n";
    }
    cout << "\n------------------------------------------\n\n";
}

void Game ::playgame()
{
    int turns;
    int Playernum;
    Board b;
    Dictionary d;
    b.createboard();
    b.assigningvalue();
    cout << "How many turns' game you want??" << endl;
    while (true)
    {
        cin >> turns;
        if (!cin)
        {
            cout << "Invalid choice" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
            break;
    }
    cout << "Enter number of Players (Max 4)" << endl;
    while (true)
    {
        cin >> Playernum;
        if (!cin || Playernum > 4 || Playernum < 1)
        {
            cout << "Invalid choice" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
            break;
    }
    int playerscore[5] = {0};
    Player p1;
    Player p2;
    Player p3;
    Player p4;
    cout << "Enter Player names" << endl;
    for (int i = 1; i <= Playernum; i++)
    {
        if (i == 1)
        {
            cout << "Player " << i << " : ";
            p1.setname();
        }
        else if (i == 2)
        {
            cout << "Player " << i << " : ";
            p2.setname();
        }
        else if (i == 3)
        {
            cout << "Player " << i << " : ";
            p3.setname();
        }
        else if (i == 4)
        {
            cout << "Player " << i << " : ";
            p4.setname();
        }
    }
    cout << "-------------------------------------\n";
    cout << "Creating Players..." << endl;
    cout << "Lets Start to Play" << endl;
    cout << "-------------------------------------\n";
    for (int i = 1; i <= turns; i++)
    {
        cout << "TURN " << i << endl;
        cout << "- - - - - - - - - - - - - - - - - - \n";
        for (int j = 1; j <= Playernum; j++)
        {
            b.printboard();
            cout << "- - - - - - - - - - - - - - - - - - \n";
            cout << "Player " << j << " : ";
            if (j == 1)
            {
                cout << p1.tellname() << endl;
                p1.makeset();
            }
            else if (j == 2)
            {
                cout << p2.tellname() << endl;
                p2.makeset();
            }
            else if (j == 3)
            {
                cout << p3.tellname() << endl;
                p3.makeset();
            }
            else if (j == 4)
            {
                cout << p4.tellname() << endl;
                p4.makeset();
            }
            cout << "- - - - - - - - - - - - - - - - - - \n";

            int length;
            length = 0;
            cout << "Enter number of letters you will place on Board (Enter 0 to skip) : ";
            while (true)
            {
                cin >> length;
                if (!cin)
                {
                    cout << "Please provide a vaild input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else
                    break;
            }
            if (length != 0)
            {
                int arr_x[length + 1], arr_y[length + 1];
                cout << "Input Your word letter-by-letter as given below" << endl;
                cout << "Example : c 1 2 (letter 'c' at coordinate (1,2))" << endl;
                if (j == 1)
                {
                    for (int k = 1; k <= length; k++)
                    {
                        char c;
                        int x, y;
                        cin >> c >> x >> y;
                        arr_x[k] = x;
                        arr_y[k] = y;
                        b.setchar(c, x, y);
                        p1.deleteTile(c);
                    }
                }
                else if (j == 2)
                {
                    for (int k = 1; k <= length; k++)
                    {
                        char c;
                        int x, y;
                        cin >> c >> x >> y;
                        arr_x[k] = x;
                        arr_y[k] = y;
                        b.setchar(c, x, y);
                        p2.deleteTile(c);
                    }
                }
                else if (j == 3)
                {
                    for (int k = 1; k <= length; k++)
                    {
                        char c;
                        int x, y;
                        cin >> c >> x >> y;
                        arr_x[k] = x;
                        arr_y[k] = y;
                        b.setchar(c, x, y);
                        p3.deleteTile(c);
                    }
                }
                else if (j == 4)
                {
                    for (int k = 1; k <= length; k++)
                    {
                        char c;
                        int x, y;
                        cin >> c >> x >> y;
                        arr_x[k] = x;
                        arr_y[k] = y;
                        b.setchar(c, x, y);
                        p4.deleteTile(c);
                    }
                }
                char orient;
                int xnum = 0, ynum = 0;
                for (int k = 1; k < length; k++)
                {
                    if (arr_x[k] == arr_x[k + 1])
                    {
                        xnum = xnum + 1;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int k = 1; k < length; k++)
                {
                    if (arr_y[k] == arr_y[k + 1])
                    {
                        ynum = ynum + 1;
                    }
                    else
                    {
                        break;
                    }
                }
                if (xnum == (length - 1))
                {
                    orient = 'V';
                }
                else if (ynum == (length - 1))
                {
                    orient = 'H';
                }
                else
                {
                    cout << "Enter valid Coordinates !!!!" << endl;
                }
                // cout << "Your word is Vertical or Horizontal ?" << endl;
                // cout << "V/H : ";
                // cin >> orient;
                int fixed, start, end;
                // cout << "Enter your Coordinates " << endl;
                if (j == 1)
                {
                    if (orient == 'H')
                    {
                        cout << "------------------------------------\n";
                        //cout << "Your word is Horizontal\n";
                        fixed = arr_y[1];
                        start = arr_x[1];
                        end = arr_x[length];
                        // cout << "Y Coordinate is : " << fixed << endl;
                        // cout << "X Start Coordinate is : " << start << endl;
                        // cout << "X End Coordinate is : " << end << endl;
                        // cout << "- - - - - - - - - - - - - - - - - - \n";
                        if (d.checkword(b.horizontal(fixed, start, end)))
                        {
                            p1.addpoints(b.setpointH(fixed, start, end));
                            cout << "Player : " << p1.tellname() << " | Points : " << p1.tellpoint() << endl;
                            playerscore[j] = playerscore[j] + p1.tellpoint();
                        }
                        else
                        {
                            for (int k = start; k <= end; k++)
                            {
                                b.setchar(' ', k, fixed);
                            }
                        }
                        cout << "------------------------------------\n";
                    }
                    else if (orient == 'V')
                    {
                        cout << "------------------------------------\n";
                        // cout << "Your word is Vertical\n";
                        fixed = arr_x[1];
                        start = arr_y[1];
                        end = arr_y[length];
                        // cout << "X Coordinate is : " << fixed << endl;
                        // cout << "Y Start Coordinate is : " << start << endl;
                        // cout << "Y End Coordinate is : " << end << endl;
                        // cout << "- - - - - - - - - - - - - - - - - - \n";
                        if (d.checkword(b.vertical(fixed, start, end)))
                        {
                            p1.addpoints(b.setpointV(fixed, start, end));
                            cout << "Player : " << p1.tellname() << " | Points : " << p1.tellpoint() << endl;
                            playerscore[j] = playerscore[j] + p1.tellpoint();
                        }
                        else
                        {
                            for (int k = start; k <= end; k++)
                            {
                                b.setchar(' ', fixed, k);
                            }
                        }
                        cout << "------------------------------------\n";
                    }
                }
                else if (j == 2)
                {
                    if (orient == 'H')
                    {
                        cout << "------------------------------------\n";
                        // cout << "Your word is Horizontal\n";
                        fixed = arr_y[1];
                        start = arr_x[1];
                        end = arr_x[length];
                        // cout << "Y Coordinate is : " << fixed << endl;
                        // cout << "X Start Coordinate is : " << start << endl;
                        // cout << "X End Coordinate is : " << end << endl;
                        // cout << "- - - - - - - - - - - - - - - - - - \n";
                        if (d.checkword(b.horizontal(fixed, start, end)))
                        {
                            p2.addpoints(b.setpointH(fixed, start, end));
                            cout << "Player : " << p2.tellname() << " | Points : " << p2.tellpoint() << endl;
                            playerscore[j] = playerscore[j] + p2.tellpoint();
                        }
                        else
                        {
                            for (int k = start; k <= end; k++)
                            {
                                b.setchar(' ', k, fixed);
                            }
                        }
                        cout << "------------------------------------\n";
                    }
                    else if (orient == 'V')
                    {
                        cout << "------------------------------------\n";
                        // cout << "Your word is Vertical\n";
                        fixed = arr_x[1];
                        start = arr_y[1];
                        end = arr_y[length];
                        // cout << "X Coordinate is : " << fixed << endl;
                        // cout << "Y Start Coordinate is : " << start << endl;
                        // cout << "Y End Coordinate is : " << end << endl;
                        // cout << "- - - - - - - - - - - - - - - - - - \n";
                        if (d.checkword(b.vertical(fixed, start, end)))
                        {
                            p2.addpoints(b.setpointV(fixed, start, end));
                            cout << "Player : " << p2.tellname() << " | Points : " << p2.tellpoint() << endl;
                            playerscore[j] = playerscore[j] + p2.tellpoint();
                        }
                        else
                        {
                            for (int k = start; k <= end; k++)
                            {
                                b.setchar(' ', fixed, k);
                            }
                        }
                        cout << "------------------------------------\n";
                    }
                }
                else if (j == 3)
                {
                    if (orient == 'H')
                    {
                        cout << "------------------------------------\n";
                        // cout << "Your word is Horizontal\n";
                        fixed = arr_y[1];
                        start = arr_x[1];
                        end = arr_x[length];
                        // cout << "Y Coordinate is : " << fixed << endl;
                        // cout << "X Start Coordinate is : " << start << endl;
                        // cout << "X End Coordinate is : " << end << endl;
                        // cout << "- - - - - - - - - - - - - - - - - - \n";
                        if (d.checkword(b.horizontal(fixed, start, end)))
                        {
                            p3.addpoints(b.setpointH(fixed, start, end));
                            cout << "Player : " << p3.tellname() << " | Points : " << p3.tellpoint() << endl;
                            playerscore[j] = playerscore[j] + p3.tellpoint();
                        }
                        else
                        {
                            for (int k = start; k <= end; k++)
                            {
                                b.setchar(' ', k, fixed);
                            }
                        }
                        cout << "------------------------------------\n";
                    }
                    else if (orient == 'V')
                    {
                        cout << "------------------------------------\n";
                        // cout << "Your word is Vertical\n";
                        fixed = arr_x[1];
                        start = arr_y[1];
                        end = arr_y[length];
                        // cout << "X Coordinate is : " << fixed << endl;
                        // cout << "Y Start Coordinate is : " << start << endl;
                        // cout << "Y End Coordinate is : " << end << endl;
                        // cout << "- - - - - - - - - - - - - - - - - - \n";
                        if (d.checkword(b.vertical(fixed, start, end)))
                        {
                            p3.addpoints(b.setpointV(fixed, start, end));
                            cout << "Player : " << p3.tellname() << " | Points : " << p3.tellpoint() << endl;
                            playerscore[j] = playerscore[j] + p3.tellpoint();
                        }
                        else
                        {
                            for (int k = start; k <= end; k++)
                            {
                                b.setchar(' ', fixed, k);
                            }
                        }
                        cout << "------------------------------------\n";
                    }
                }
                else if (j == 4)
                {
                    if (orient == 'H')
                    {
                        cout << "------------------------------------\n";
                        // cout << "Your word is Horizontal\n";
                        fixed = arr_y[1];
                        start = arr_x[1];
                        end = arr_x[length];
                        // cout << "Y Coordinate is : " << fixed << endl;
                        // cout << "X Start Coordinate is : " << start << endl;
                        // cout << "X End Coordinate is : " << end << endl;
                        // cout << "- - - - - - - - - - - - - - - - - - \n";
                        if (d.checkword(b.horizontal(fixed, start, end)))
                        {
                            p4.addpoints(b.setpointH(fixed, start, end));
                            cout << "Player : " << p4.tellname() << " | Points : " << p4.tellpoint() << endl;
                            playerscore[j] = playerscore[j] + p4.tellpoint();
                        }
                        else
                        {
                            for (int k = start; k <= end; k++)
                            {
                                b.setchar(' ', k, fixed);
                            }
                        }
                        cout << "------------------------------------\n";
                    }
                    else if (orient == 'V')
                    {
                        cout << "------------------------------------\n";
                        // cout << "Your word is Vertical\n";
                        fixed = arr_x[1];
                        start = arr_y[1];
                        end = arr_y[length];
                        // cout << "X Coordinate is : " << fixed << endl;
                        // cout << "Y Start Coordinate is : " << start << endl;
                        // cout << "Y End Coordinate is : " << end << endl;
                        // cout << "- - - - - - - - - - - - - - - - - - \n";
                        if (d.checkword(b.vertical(fixed, start, end)))
                        {
                            p4.addpoints(b.setpointV(fixed, start, end));
                            cout << "Player : " << p4.tellname() << " | Points : " << p4.tellpoint() << endl;
                            playerscore[j] = playerscore[j] + p4.tellpoint();
                        }
                        else
                        {
                            for (int k = start; k <= end; k++)
                            {
                                b.setchar(' ', fixed, k);
                            }
                        }
                        cout << "------------------------------------\n";
                    }
                }
            }
            else
            {
                if (j == 1)
                {
                    for (int i = 0; i < 7; i++)
                    {
                        p1.set[i] = ' ';
                    }
                    p1.makeset();
                }
                else if (j == 2)
                {
                    for (int i = 0; i < 7; i++)
                    {
                        p2.set[i] = ' ';
                    }
                    p2.makeset();
                }
                else if (j == 3)
                {
                    for (int i = 0; i < 7; i++)
                    {
                        p3.set[i] = ' ';
                    }
                    p3.makeset();
                }
                else if (j == 4)
                {
                    for (int i = 0; i < 7; i++)
                    {
                        p4.set[i] = ' ';
                    }
                    p4.makeset();
                }
            }
        }
    }
    b.printboard();
    cout << "------------------------------------\n";
    cout << "Game Ended" << endl;
    cout << "--------Final Scores are----------" << endl;
    for (int j = 1; j <= Playernum; j++)
    {
        cout << "Player " << j << " : ";
        if (j == 1)
        {
            cout << p1.tellname() << endl;
        }
        else if (j == 2)
        {
            cout << p2.tellname() << endl;
        }
        else if (j == 3)
        {
            cout << p3.tellname() << endl;
        }
        else if (j == 4)
        {
            cout << p4.tellname() << endl;
        }
        cout << "Score : " << playerscore[j] << endl;
    }
    int max = 0;
    int index;
    for (int j = 1; j <= Playernum; j++)
    {
        if (playerscore[j] >= max)
        {
            max = playerscore[j];
            index = j;
        }
    }
    cout << "----------  Congratulations ";
    if (index == 1)
    {
        cout << p1.tellname();
    }
    if (index == 2)
    {
        cout << p2.tellname();
    }
    if (index == 3)
    {
        cout << p3.tellname();
    }
    if (index == 4)
    {
        cout << p4.tellname();
    }
    cout << " !!!! You won with " << max << " points  ----------" << endl;
}