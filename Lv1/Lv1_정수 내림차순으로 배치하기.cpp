#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    // n �� �� �ڸ� ���ڸ� ���Ͽ� numbers �� ����
    vector<int> numbers;
    while (n > 0)
    {
        numbers.push_back(n % 10);
        n /= 10;
    }

    // numbers �� ������������ ����
    sort(numbers.begin(), numbers.end(), [](int a, int b)->bool {return a > b;});


    // numbers�� ������ ��ȯ
    for (size_t ii = 0; ii < numbers.size(); ii++)
        answer += (numbers[ii] * pow(10, numbers.size() - ii - 1));

    return answer;
}