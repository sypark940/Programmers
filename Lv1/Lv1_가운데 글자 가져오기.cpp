#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    size_t length = s.length();

    // 단어의 길이가 짝수인 경우
    if (length % 2 == 0)
    {
        answer += s[length / 2 - 1];
        answer += s[length / 2];
    }
    // 단어의 길이가 홀수인 경우
    else
    {
        answer += s[length / 2];
    }

    return answer;
}