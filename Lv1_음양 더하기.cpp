#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (size_t ii = 0; ii < absolutes.size() && ii < signs.size(); ii++)
    {
        // signs[ii] 의 부호에 따라 실제 정수 결정 후 answer 에 더한다.
        int num = signs[ii] ? absolutes[ii] : -absolutes[ii];
        answer += num;
    }

    return answer;
}