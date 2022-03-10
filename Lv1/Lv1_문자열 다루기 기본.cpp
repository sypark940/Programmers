#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    // s �� ���� Ȯ��
    size_t length = s.length();
    if (length == 4 || length == 6)
    {
        // s �� ��� ���Ұ� �������� Ȯ��
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