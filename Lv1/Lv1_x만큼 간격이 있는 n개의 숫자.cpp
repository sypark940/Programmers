#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    for (int ii = 1; ii <= n; ii++)
    {
        answer.push_back((long long)(x * ii));
    }

    return answer;
}