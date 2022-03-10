#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int x_copy = x;

    // x�� �� �ڸ����� ���Ѵ�.
    vector<int> numbers;
    while (x_copy > 0)
    {
        numbers.push_back(x_copy % 10);
        x_copy /= 10;
    }

    // x�� �� �ڸ����� �� ���
    int sum = 0;
    for (int num : numbers)
        sum += num;

    // �ϻ��� �� �Ǻ�
    answer = (x % sum == 0) ? true : false;

    return answer;
}