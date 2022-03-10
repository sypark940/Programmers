#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    // n 의 각 자리 숫자를 구하여 numbers 에 저장
    vector<int> numbers;
    while (n > 0)
    {
        numbers.push_back(n % 10);
        n /= 10;
    }

    // numbers 를 내림차순으로 정렬
    sort(numbers.begin(), numbers.end(), [](int a, int b)->bool {return a > b;});


    // numbers를 정수로 변환
    for (size_t ii = 0; ii < numbers.size(); ii++)
        answer += (numbers[ii] * pow(10, numbers.size() - ii - 1));

    return answer;
}