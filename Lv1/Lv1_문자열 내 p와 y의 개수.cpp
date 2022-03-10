#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pCnt = 0;
    int yCnt = 0;

    for (auto c : s)
    {
        if (c == 'p' || c == 'P')
            pCnt++;
        else if (c == 'y' || c == 'Y')
            yCnt++;
    }

    answer = (pCnt == yCnt) ? true : false;
    return answer;
}