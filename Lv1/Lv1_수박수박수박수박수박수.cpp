#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int ii = 0; ii < n; ii++)
    {
        if (ii % 2 == 0)
            answer += "��";
        else
            answer += "��";
    }
    return answer;
}