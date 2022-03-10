#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    // n 의 각 자리수를 answer 에 역순으로 저장
    while (n > 0)
    {
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}