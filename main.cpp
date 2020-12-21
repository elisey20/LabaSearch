#include <iostream>
#include <string>
#include <fstream>

#include "methods.h"

#define SAY_MESSAGE std::cout <<
#define SAY_ERROR std::cout <<

using namespace std;

int main()
{
    ifstream fin;
    fin.open("../inputFiles/input.txt");

    string lookingString;
    getline(fin, lookingString);

    string searchStr;
    SAY_MESSAGE "Введите искомую строку: ";
    getline(cin, searchStr);

    vector<size_t> positions = findString(lookingString, searchStr);

    SAY_MESSAGE "Позиции найденных строк: ";
    for (size_t j : positions)
    {
        SAY_MESSAGE j + 1 << ' ';
    }

    //delete[] positions;
    fin.close();

    return 0;
}
