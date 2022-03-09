#include <string>
#include <vector>

using namespace std;

bool HasEvenDivisors(int num)
{
    // 1 -> ����� ���� 1��
    if (num == 1)
        return false;

    // 2 -> ����� ���� 2��
    if (num == 2)
        return true;

    // ��� ���� �ʱ�ȭ (1 �� �ڱ� �ڽ� -> 2��)
    int divisorCnt = 2;

    // 1 �� num �ڽ��� ������ �� ������ ���� num �� ������ �������� ���, ����� ���� ����
    for (int divisor = 2; divisor < num; divisor++)
    {
        if (num % divisor == 0)
            divisorCnt++;
    }

    return !(divisorCnt % 2);
}

int solution(int left, int right) {
    int answer = 0;

    // left ���� right ������ ��� ���� �߿���,
    // ����� ������ ¦���� ���� ���ϰ� Ȧ���� ���� ����.
    for (int num = left; num <= right; num++)
    {
        if (HasEvenDivisors(num))
            answer += num;
        else
            answer -= num;
    }

    return answer;
}