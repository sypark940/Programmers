#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    // 1 과 자기 자신을 제외한 나머지 수로 n을 나눠서 나머지를 확인
    // (답이 항상 존재함은 증명될 수 있다고 했으므로, n은 소수가 아님)
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