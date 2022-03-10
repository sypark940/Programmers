#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    // s 의 길이 확인
    size_t length = s.length();
    if (length == 4 || length == 6)
    {
        // s 의 모든 원소가 숫자인지 확인
        bool bOnlyNum = true;
        for (auto c : s)
        {
            if (c < '0' || c > '9')
            {
                bOnlyNum = false;
                break;
            }
        }

        answer = bOnlyNum ? true : false;
    }
    else
    {
        answer = false;
    }

    return answer;
}