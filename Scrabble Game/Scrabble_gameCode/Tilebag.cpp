#include "Tilebag.h"
// #include "Game.h"

Tilebag ::Tilebag()
{

}

//This function assigns value to each letter from a to z and store in letterValueMap
void Tilebag ::assigningvalue()
{
    for (char i = 'a'; i <= 'z'; i++)
    {
        switch (i)
        {
        case 'a':
        case 'i':
            letterValueMap.insert({i, 1});
            break;
        case 'b':
        case 'c':
        case 'm':
        case 'p':
            letterValueMap.insert({i, 3});
            break;
        case 'd':
            letterValueMap.insert({i, 2});
            break;
        case 'e':
            letterValueMap.insert({i, 1});
            break;
        case 'f':
        case 'h':
        case 'v':
        case 'w':
        case 'y':
            letterValueMap.insert({i, 4});
            break;
        case 'g':
            letterValueMap.insert({i, 2});
            break;
        case 'j':
        case 'x':
            letterValueMap.insert({i, 8});
            break;
        case 'k':
            letterValueMap.insert({i, 5});
            break;
        case 'l':
        case 's':
        case 'u':
            letterValueMap.insert({i, 1});
            break;
        case 'n':
        case 'r':
        case 't':
            letterValueMap.insert({i, 1});
            break;
        case 'o':
            letterValueMap.insert({i, 1});
            break;
        case 'q':
        case 'z':
            letterValueMap.insert({i, 10});
            break;
        default:
            break;
        }
    }
}

//This function will take letter as argument and will return its value from letterValueMap
int Tilebag ::getletterval(char c)
{
    for (auto it = letterValueMap.begin(); it != letterValueMap.end(); it++)
    {
        if ((it->first) == c)
        {
            //cout<<"value "<<(it->second)<<endl;
            return (it->second);
        }
    }
    return 0;
}