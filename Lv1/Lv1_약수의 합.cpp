#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int num = 1; num <= n; num++)
    {
        // n �� num���� ������ �������� ��� -> num �� n�� ���
        if (n % num == 0)
            answer += num;
    }

    return answer;
}