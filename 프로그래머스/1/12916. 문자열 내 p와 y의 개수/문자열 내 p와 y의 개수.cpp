#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int nY = 0;
    int nP = 0;
    for (auto i : s)
    {
        if (i == 'y' || i == 'Y')
        {
            nY++;
        }
        else if (i == 'p' || i == 'P')
        {
            nP++;
        }
    }
    return (nY == nP) ? true : false;
}