#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int x_copy = x;

    // x의 각 자릿수를 구한다.
    vector<int> numbers;
    while (x_copy > 0)
    {
        numbers.push_back(x_copy % 10);
        x_copy /= 10;
    }

    // x의 각 자릿수의 합 계산
    int sum = 0;
    for (int num : numbers)
        sum += num;

    // 하샤드 수 판별
    answer = (x % sum == 0) ? true : false;

    return answer;
}