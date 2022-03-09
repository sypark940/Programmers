#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;

    // n�� 3���� �󿡼� �յڷ� ������ �� �ڸ��� ���� vecNum3 �� ����
    vector<int> vecNum3;
    while (n > 0)
    {
        vecNum3.push_back(n % 3);
        n /= 3;
    };

    // vecNum3 �� 10�������� ǥ���� ���� ���
    for (size_t ii = 0; ii < vecNum3.size(); ii++)
    {
        answer += vecNum3[ii] * pow(3, (int)(vecNum3.size() - ii - 1));
    }

    return answer;
}