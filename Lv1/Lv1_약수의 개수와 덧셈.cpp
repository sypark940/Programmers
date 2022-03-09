#include <string>
#include <vector>

using namespace std;

bool HasEvenDivisors(int num)
{
    // 1 -> 약수의 개수 1개
    if (num == 1)
        return false;

    // 2 -> 약수의 개수 2개
    if (num == 2)
        return true;

    // 약수 개수 초기화 (1 과 자기 자신 -> 2개)
    int divisorCnt = 2;

    // 1 과 num 자신을 제외한 그 사이의 수로 num 이 나누어 떨어지는 경우, 약수의 개수 증가
    for (int divisor = 2; divisor < num; divisor++)
    {
        if (num % divisor == 0)
            divisorCnt++;
    }

    return !(divisorCnt % 2);
}

int solution(int left, int right) {
    int answer = 0;

    // left 부터 right 까지의 모든 수들 중에서,
    // 약수의 개수가 짝수인 수는 더하고 홀수인 수는 뺀다.
    for (int num = left; num <= right; num++)
    {
        if (HasEvenDivisors(num))
            answer += num;
        else
            answer -= num;
    }

    return answer;
}