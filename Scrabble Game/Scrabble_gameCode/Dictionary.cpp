#include "Dictionary.h"
// #include "Game.h"

Dictionary ::Dictionary()
{
    
}

//This function is to check word from dictonary (Words.txt) whether it is valid or not.
bool Dictionary ::checkword(string temp)
{
    fstream file;
    string word, t, q, filename;
    // cout << "Enter it again to confirm " << endl;
    // cin >> temp;
    filename = "Words.txt";

    file.open(filename.c_str());

    while (file >> word)
    {
        if (temp == word)
        {
            cout << "Your word is Valid" << endl
                 << "Processing your points..." << endl;
            return true;
        }
    }
    cout << "Your word is Invalid" << endl
         << "Your Points : 0" << endl;
    return false;
}