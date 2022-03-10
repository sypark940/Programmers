#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int num = 1; num <= n; num++)
    {
        // n 이 num으로 나누어 떨어지는 경우 -> num 은 n의 약수
        if (n % num == 0)
            answer += num;
    }

    return answer;
}