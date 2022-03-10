#include <string>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a < b)
    {
        for (int num = a; num <= b; num++)
            answer += (long long)num;
    }
    else
    {
        for (int num = b; num <= a; num++)
            answer += (long long)num;
    }

    return answer;
}