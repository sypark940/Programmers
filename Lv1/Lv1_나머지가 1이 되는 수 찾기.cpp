#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    // 1 �� �ڱ� �ڽ��� ������ ������ ���� n�� ������ �������� Ȯ��
    // (���� �׻� �������� ����� �� �ִٰ� �����Ƿ�, n�� �Ҽ��� �ƴ�)
    for (int x = 2; x <= n - 1; x++)
    {
        if (n % x == 1)
        {
            answer = x;
            break;
        }
    }
    return answer;
}