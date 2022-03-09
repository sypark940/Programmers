#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;

    // n을 3진법 상에서 앞뒤로 뒤집은 각 자리의 수를 vecNum3 에 저장
    vector<int> vecNum3;
    while (n > 0)
    {
        vecNum3.push_back(n % 3);
        n /= 3;
    };

    // vecNum3 를 10진법으로 표현한 수를 계산
    for (size_t ii = 0; ii < vecNum3.size(); ii++)
    {
        answer += vecNum3[ii] * pow(3, (int)(vecNum3.size() - ii - 1));
    }

    return answer;
}