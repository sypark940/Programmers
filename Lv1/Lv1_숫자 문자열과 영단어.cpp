#include <string>
#include <math.h>
#include <vector>

using namespace std;

// s 의 맨 앞에 있는 숫자를 찾는 함수 (찾은 숫자는 s에서 제거)
int GetNum(string& s)
{
    if (s.find("zero") == 0) { s.erase(0, 4); return 0; }
    else if (s.find("one") == 0) { s.erase(0, 3); return 1; }
    else if (s.find("two") == 0) { s.erase(0, 3); return 2; }
    else if (s.find("three") == 0) { s.erase(0, 5); return 3; }
    else if (s.find("four") == 0) { s.erase(0, 4); return 4; }
    else if (s.find("five") == 0) { s.erase(0, 4); return 5; }
    else if (s.find("six") == 0) { s.erase(0, 3); return 6; }
    else if (s.find("seven") == 0) { s.erase(0, 5); return 7; }
    else if (s.find("eight") == 0) { s.erase(0, 5); return 8; }
    else if (s.find("nine") == 0) { s.erase(0, 4); return 9; }
    else if (s.find("0") == 0) { s.erase(0, 1); return 0; }
    else if (s.find("1") == 0) { s.erase(0, 1); return 1; }
    else if (s.find("2") == 0) { s.erase(0, 1); return 2; }
    else if (s.find("3") == 0) { s.erase(0, 1); return 3; }
    else if (s.find("4") == 0) { s.erase(0, 1); return 4; }
    else if (s.find("5") == 0) { s.erase(0, 1); return 5; }
    else if (s.find("6") == 0) { s.erase(0, 1); return 6; }
    else if (s.find("7") == 0) { s.erase(0, 1); return 7; }
    else if (s.find("8") == 0) { s.erase(0, 1); return 8; }
    else if (s.find("9") == 0) { s.erase(0, 1); return 9; }
}

int solution(string s) {
    int answer = 0;

    vector<int> numbers;
    while (!s.empty())
    {
        // s의 맨 앞에 있는 숫자를 구해서 numbers 에 추가
        numbers.push_back(GetNum(s));
    };

    // vector<int> -> 정수로 변환
    for (size_t ii = 0; ii < numbers.size(); ii++)
        answer += (numbers[ii] * pow(10, (int)(numbers.size() - ii - 1)));

    return answer;
}