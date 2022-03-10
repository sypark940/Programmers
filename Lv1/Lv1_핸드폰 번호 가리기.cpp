#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;

    size_t index = 0;
    size_t cntNum = answer.length();
    while (cntNum > 4)
    {
        answer[index] = '*';
        index++;
        cntNum--;
    }

    return answer;
}